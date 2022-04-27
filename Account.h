#pragma once
#include "decimal.h"
#include <iostream>
using namespace dec;
using namespace std;

enum currencies :char { Ruble = 'R', DollarUSA = 'D', Euro = 'E' };

//Счет
class Account
{
	friend class DataBase;
	friend class Transaction;
	friend class CashTransaction;

public:
	//Конструктор
	Account(const decimal<2>& first_amount, const currencies& currency,
		const string& account_id, const decimal<2>& limit);
	//Показать текущий баланс
	decimal<2> get_balance() const { return balance_; }
	//Показать валюту
	string get_currency() const;
	//Показать id счета
	string get_account_id() const { return account_id_; }
	//
	decimal<2> get_limit() const { return limit_; }

protected:
	//Баланс
	decimal<2> balance_;
	//Валюта
	currencies currency_ = Ruble;
	//id счета
	string account_id_ = "";
	//Есть ли карта
	bool has_card = false;
	//
	decimal<2> limit_;
	//открыт счёт
	bool active_ = true;

	//Задать баланс счета
	void set_balance(const decimal<2>& new_balance) { balance_ = new_balance; }
	//Задать валюту
	void set_currency(const currencies& currency) { currency_ = currency; }
	//Задать id
	void set_id(const string& account_id) { account_id_ = account_id; }
	//
	void set_limit(const decimal<2>& new_limit) { limit_ = new_limit; }

};

