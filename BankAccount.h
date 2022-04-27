#pragma once
#include "tools.h"
#include "Account.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//Банковский аккаунт
class BankAccount
{
public:
	struct address {
		string country_;
		string city_;
		string street_;
		string building_;
		string flat_;
	};
	//Показать имя клиента
	string get_name() const { return name_; }
	//Показать адрес клиента
	address get_address() const {
		return address_;
	}
	//Показать баланс счета id
	decimal<2> get_balance_on_account(const string& account_id) const;
	//Показать id 
	string get_id() const { return account_id_; }
	//Показать номер клиента
	string get_phone_number() const { return phone_number_; }
	//Функции для того, чтобы показать адресс
	string get_country()const { return address_.country_; }
	string get_city()const { return address_.city_; }
	string get_street()const { return address_.street_; }
	string get_building()const { return address_.building_; }
	string get_flat()const { return address_.flat_; }

	//Задать имя клиента
	void set_name(const string& new_name) { name_ = new_name; }
	//Задать адрес клиента
	void set_address(const string& country = "", const string& city = "",
		const string& street = "", const string& building = "", const string& flat = "") {
		address_.country_ = country;
		address_.city_ = city;
		address_.street_ = street;
		address_.building_ = building;
		address_.flat_ = flat;
	}
	//Задать номер клиента
	void set_phone_number(const string& new_phone_number) { phone_number_ = new_phone_number; }
	//Задать id
	void set_id(const string& new_id) { account_id_ = new_id; }

	//Список счетов клиента
	vector<Account*> accounts_;

	//Функции регистрации имени, номера телефона и адресса(для физ/юр лица)
	void reg_name();
	void reg_address();
	void reg_phone();

	//Печать адреса
	void print_address();
	//Проверка наличия кв
	bool has_flat();

protected:
	//Имя
	string name_ = "";
	//id счета
	string account_id_ = "";
	//Адрес
	address address_;
	//Номер телефона клиента
	string phone_number_ = "";

};

