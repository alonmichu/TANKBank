#include "DataBase.h"

void DataBase::client_registration(BankAccount* client)
{
	if (client == nullptr)
	{
		cout << "Operation is not correct";
		return;
	}
	string id = num_to_id(users_.size(), 8);
	client->set_id(id);
	users_.push_back(client);
	cout << "Client successfully registered, id: " << client->get_id() << endl;
}

void DataBase::account_openning(BankAccount* client, const decimal<2>& first_amount,
	const currencies& currency, const decimal<2>& limit)
{
	if (client == nullptr)
	{
		cout << "no client to register" << endl;
		return;
	}
	string account_id = client->get_id();
	account_id += " ";
	account_id += num_to_id(accounts_num_, 4);
	accounts_num_++;
	Account* new_account = new Account(first_amount, currency, account_id, limit);
	client->accounts_.push_back(new_account);
	cout << "Account successfully opened! Your id: " << account_id << endl;
}

void DataBase::card_registration(Account* account, Card* card)
{
	if (account == nullptr || card == nullptr || !card->is_active() || account->active_ == false ||
		card->get_account() != nullptr || account->has_card)
	{
		cout << "Mistake. Conditions not met" << endl;
		return;
	}
	card->set_account(account);
	card->set_limit(account->get_limit());
	string card_id = num_to_id(card_num_, 4) + " " + account->get_account_id();
	card_num_++;
	card->set_card_id(card_id);
	card->set_account(account);
	account->has_card = true;
	cout << endl << "Card successfully linked to account " << account->get_account_id() << endl;
	cout << endl << card->get_bank_name() << endl;
	cout << "Card number: " << card->get_card_id() << endl;
	cout << card->get_currency() << " " << "Debit" << "             "
		<< card->get_pay_system() << endl << endl;
}

void DataBase::relink_card(Account* new_account, Card* card)
{
	if (new_account == nullptr || card == nullptr || new_account->active_ == false ||
		card->get_account() == nullptr || new_account->has_card || !card->is_active())
	{
		cout << "Mistake. Conditions not met" << endl;
		return;
	}
	card->get_account()->has_card = false;
	card->set_account(new_account);
	new_account->has_card = true;
	cout << "Card successfully linked to account " << new_account->get_account_id() << endl;
}

void DataBase::close_card(Card* card)
{
	if (card == nullptr)
	{
		cout << "Mistake. Conditions not met" << endl;
		return;
	}
	card->get_account()->has_card = false;
	card->set_account(nullptr);
	card->active_ = false;
	cout << "Card " << card->get_card_id() << " closed" << endl;
}

bool DataBase::transaction(Account* write_off_account, 
	Account* credit_account, const decimal<2>& amount)
{
	Transaction new_transaction(write_off_account, credit_account, amount);
	new_transaction.transaction_info();
	if (new_transaction.get_status() == "To processing")
	{
		new_transaction.make_transaction();
		new_transaction.transaction_info();
		if (new_transaction.get_status() == "Done") return true;
		else return false;

	}
}

bool DataBase::transaction(Card* write_off_card,
	Account* credit_account, const decimal<2>& amount)
{
	Account* write_off_account = write_off_card->get_account();
	transaction(write_off_account, credit_account, amount);
}

bool DataBase::transaction(Account* write_off_account,
	Card* credit_card, const decimal<2>& amount)
{
	Account* credit_account = credit_card->get_account();
	transaction(write_off_account, credit_account, amount);
}

bool DataBase::transaction(Card* write_off_card,
	Card* credit_card, const decimal<2>& amount)
{
	Account* write_off_account = write_off_card->get_account();
	Account* credit_account = credit_card->get_account();
	transaction(write_off_account, credit_account, amount);
}

bool DataBase::cash_transaction(Account* account, 
	const decimal<2>& amount, const operation& operation)
{
	CashTransaction cash(account, amount, operation);
	int place;
	cash.transaction_info();
	cout << "Press 1, if you are in department. Press 2, if you are in ATM: ";
	cin >> place;
	cout << endl;
	if (place == 1)
		cash.set_place(place::department);
	else
		cash.set_place(place::atm);
	cash.make_transaction();
	cash.transaction_info();
	if (cash.get_status() == done) return true;
	else return false;
}

bool DataBase::cash_transaction(Card* card,
	const decimal<2>& amount, const operation& operation)
{
	Account* account = card->get_account();
	cash_transaction(account, amount, operation);
}

void DataBase::close_account_transaction(Account* write_off_account, Account* credit_account)
{
	if (write_off_account->has_card)
	{
		cout << "Close your card first, please\n";
		return;
	}
	decimal<2> lim;
	lim = 0;
	write_off_account->set_limit(lim);
	decimal<2> amount = write_off_account->get_balance();
	bool done = transaction(write_off_account, credit_account, amount);
	if (done) {
		write_off_account->active_ = false;
		cout << "Account succesfuly closed!" << endl;
	}
	else cout << "Condition not met" << endl;
}

void DataBase::close_account_cash(Account* write_off_account)
{
	if (write_off_account->has_card)
	{
		cout << "Close your card first, please\n";
		return;
	}
	decimal<2> lim;
	lim = 0;
	write_off_account->set_limit(lim);
	decimal<2> amount = write_off_account->get_balance();
	bool done = cash_transaction(write_off_account, amount, operation::withdraw);
	if (done) {
		write_off_account->active_ = false;
		cout << "Account succesfuly closed!" << endl;
	}
	else cout << "Condition not met" << endl;
}