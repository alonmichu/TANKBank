#include "Transaction.h"

Transaction::Transaction(Account* write_off_account,
	Account* credit_account, const decimal<2>& amount)
{
	//
	set_write_off_account(write_off_account);
	set_credit_account(credit_account);
	set_amount(amount);
}

Transaction::Transaction(Card* write_off_card,
	Account* credit_account, const decimal<2>& amount)
{
	Account* write_off_account = write_off_card->get_account();
	Transaction(write_off_account, credit_account, amount);
}

Transaction::Transaction(Account* write_off_account,
	Card* credit_card, const decimal<2>& amount)
{
	Account* credit_account = credit_card->get_account();
	Transaction(write_off_account, credit_account, amount);
}

Transaction::Transaction(Card* write_off_card,
	Card* credit_card, const decimal<2>& amount)
{
	Account* credit_account = credit_card->get_account();
	Account* write_off_account = write_off_card->get_account();
	Transaction(write_off_account, credit_account, amount);
}

string Transaction::get_currency() const
{
	switch (currency_)
	{
	case 'R': return "Ruble";
	case 'D': return "DollarUSA";
	case 'E': return "Euro";
	}
	return "";
}

string Transaction::get_status() const
{
	switch (status_)
	{
	case rejected: return "Rejected";
	case done: return "Done";
	case toprocessing: return "To processing";
	}
	return "";
}

void Transaction::make_transaction()
{
	if (get_status() != "To processing")
		return;
	if (write_off_account_ == nullptr || credit_account_ == nullptr
		|| write_off_account_->get_currency() != credit_account_->get_currency()
		|| write_off_account_->get_balance() < get_amount()
		|| write_off_account_->get_limit() != 0 && write_off_account_->get_limit() < get_amount())
	{
		set_status(rejected);
		return;
	}
	Account* write_off = get_write_off_account();
	write_off->set_balance(write_off->get_balance() - get_amount());
	Account* credit = get_credit_account();
	credit->set_balance(credit->get_balance() + get_amount());
	set_status(done);
}

void Transaction::transaction_info() const
{
	if (get_status() == "Rejected")
	{
		cout << endl << "Transaction declined" << endl;
		return;
	}
	if (get_status() == "To processing")
	{
		cout << endl << "Transaction is to processing..." << endl;
		return;
	}
	//if done:
	cout << endl << "Transaction was successful" << endl;
	cout << get_amount() << " " << get_currency() << endl;
	cout << "From: " << get_write_off_account()->get_account_id()
		<< " Balance: " << get_write_off_account()->get_balance() << endl;
	cout << "To: " << get_credit_account()->get_account_id()
		<< " Balance: " << get_credit_account()->get_balance() << endl;
}