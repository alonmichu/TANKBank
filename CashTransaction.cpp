#include "CashTransaction.h"

CashTransaction::CashTransaction(Account* account, 
	const decimal<2>& amount, const operation& operation)
{
	set_account(account);
	set_amount(amount);
	set_operation(operation);
}

CashTransaction::CashTransaction(Card* card, 
	const decimal<2>& amount, const operation& operation)
{
	Account* account = card->get_account();
	CashTransaction(account, amount, operation);
}

string CashTransaction::get_str_currency() const
{
	switch (currency_)
	{
	case 'R': return "Ruble";
	case 'D': return "DollarUSA";
	case 'E': return "Euro";
	}
	return "";
}

string CashTransaction::get_str_status() const
{
	switch (status_)
	{
	case status::rejected: return "Rejected";
	case status::done: return "Done";
	case status::toprocessing: return "To processing";
	}
	return "";
}

string CashTransaction::get_str_place() const
{
	switch (place_)
	{
	case place::atm: return "ATM";
	case place::department: return "Done";
	}
	return "";
}

void CashTransaction::make_transaction()
{
	if (status_ != status::toprocessing)
		return;
	if (operation_ == operation::withdraw)
	{
		if ((account_ == nullptr || account_->get_balance() < get_amount()
			|| (account_->get_limit() < get_amount() && account_->get_limit() != 0))
			//в банкомате и в отделении нельзя снять/положить небумажные деньги
			//|| amount_.ceil() % 10 != 0 && amount_.floor() != 0
			)
			set_status(status::rejected);
		else
		{
			Account* write_off = get_account();
			write_off->set_balance(write_off->get_balance() - amount_);
			set_status(status::done);
		}
	}
	else
	{
		if (account_ == nullptr || amount_.ceil() % 10 != 0 && amount_.floor() != 0)
			set_status(status::rejected);
		else
		{
			Account* write_off = get_account();
			write_off->set_balance(write_off->get_balance() + get_amount());
			set_status(status::done);
		}
	}
}

void CashTransaction::transaction_info() const
{
	if (status_ == status::rejected)
	{
		cout << endl << "Transaction declined" << endl;
		return;
	}
	if (status_ == status::toprocessing)
	{
		cout << endl << "Transaction is to processing..." << endl;
		return;
	}
	cout << endl << "Transaction was successful" << endl;
	cout << amount_ << " " << get_str_currency() << endl;
	cout << "From: " << account_->get_account_id()
		<< " Balance: " << account_->get_balance() << endl;
}
