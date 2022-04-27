#pragma once
#include "Card.h"
//#include "tools.h"

enum status { rejected, done, toprocessing };

//
class Transaction
{
public:
	//
	Transaction(Account* write_off_account, Account* credit_account, const decimal<2>& amount);
	Transaction(Card* write_off_card, Account* credit_account, const decimal<2>& amount);
	Transaction(Account* write_off_account, Card* credit_card, const decimal<2>& amount);
	Transaction(Card* write_off_card, Card* credit_card, const decimal<2>& amount);

	//
	Account* get_write_off_account() const { return write_off_account_; }
	//
	Account* get_credit_account() const { return credit_account_; }
	//
	decimal<2> get_amount() const { return amount_; }
	//
	string get_currency() const;
	//
	string get_status() const;

	//
	void make_transaction();
	//
	void transaction_info() const;

protected:
	//
	Account* write_off_account_ = nullptr;
	//
	Account* credit_account_ = nullptr;
	//
	decimal<2> amount_;
	//
	currencies currency_ = Ruble;
	//
	status status_ = toprocessing;

	//
	void set_write_off_account(Account* new_write_off_account) { write_off_account_ = new_write_off_account; }
	//
	void set_credit_account(Account* credit_account) { credit_account_ = credit_account; }
	//
	void set_amount(const decimal<2>& amount) { amount_ = amount; }
	//
	void set_currency(const currencies& currency) { currency_ = currency; }
	//
	void set_status(const status& status) { status_ = status; }

};




