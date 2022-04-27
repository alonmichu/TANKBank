#pragma once
#include "Card.h"
#include "Transaction.h"

enum class operation { deposit, withdraw };
enum class place { department, atm };

class CashTransaction
{
	friend class DataBase;
public:
	CashTransaction(Account* account, const decimal<2>& amount, const operation& operation);
	CashTransaction(Card* card, const decimal<2>& amount, const operation& operation);

	//Получитьс ссылку на аккаунт
	Account* get_account() const { return account_; }
	//Получить сумму транзакции
	decimal<2> get_amount() const { return amount_; }
	//Получить валюту
	currencies get_currency() const { return currency_; }
	string get_str_currency() const;
	//Получить статус транзакции
	status get_status() const { return status_; }
	string get_str_status() const;
	//Получить тип операции (снять/положить)
	operation get_operation() const { return operation_; }
	//
	place get_place() const { return place_; }
	string get_str_place() const;

	//совершить транзакцию
	void make_transaction();
	//информация о транзакции
	void transaction_info() const;

protected:
	//Аккаунт клиента
	Account* account_ = nullptr;
	//Сумма транзакции
	decimal<2> amount_;
	//Валюта
	currencies currency_ = Ruble;
	//Статус транзакции
	status status_ = status::toprocessing;
	//Тип операции (снять/положить)
	operation operation_ = operation::deposit;
	//Место
	place place_ = place::department;

	//Задать аккаунт
	void set_account(Account* new_account) { account_ = new_account; }
	//Задать сумму транзакции
	void set_amount(const decimal<2>& new_amount) { amount_ = new_amount; }
	//Задать валюту транзакции
	void set_currency(const currencies& new_currency) { currency_ = new_currency; }
	//Задать статус транзакции
	void set_status(const status& new_status) { status_ = new_status; }
	//Задать тип операции (снять/положить)
	void set_operation(const operation& new_operation) { operation_ = new_operation; }
	//Задать место
	void set_place(const place& new_place) { place_ = new_place; }

};


