#pragma once
#include "decimal.h"
#include <iostream>
using namespace dec;
using namespace std;

enum currencies :char { Ruble = 'R', DollarUSA = 'D', Euro = 'E' };

//����
class Account
{
	friend class DataBase;
	friend class Transaction;
	friend class CashTransaction;

public:
	//�����������
	Account(const decimal<2>& first_amount, const currencies& currency,
		const string& account_id, const decimal<2>& limit);
	//�������� ������� ������
	decimal<2> get_balance() const { return balance_; }
	//�������� ������
	string get_currency() const;
	//�������� id �����
	string get_account_id() const { return account_id_; }
	//
	decimal<2> get_limit() const { return limit_; }

protected:
	//������
	decimal<2> balance_;
	//������
	currencies currency_ = Ruble;
	//id �����
	string account_id_ = "";
	//���� �� �����
	bool has_card = false;
	//
	decimal<2> limit_;
	//������ ����
	bool active_ = true;

	//������ ������ �����
	void set_balance(const decimal<2>& new_balance) { balance_ = new_balance; }
	//������ ������
	void set_currency(const currencies& currency) { currency_ = currency; }
	//������ id
	void set_id(const string& account_id) { account_id_ = account_id; }
	//
	void set_limit(const decimal<2>& new_limit) { limit_ = new_limit; }

};

