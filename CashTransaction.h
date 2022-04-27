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

	//��������� ������ �� �������
	Account* get_account() const { return account_; }
	//�������� ����� ����������
	decimal<2> get_amount() const { return amount_; }
	//�������� ������
	currencies get_currency() const { return currency_; }
	string get_str_currency() const;
	//�������� ������ ����������
	status get_status() const { return status_; }
	string get_str_status() const;
	//�������� ��� �������� (�����/��������)
	operation get_operation() const { return operation_; }
	//
	place get_place() const { return place_; }
	string get_str_place() const;

	//��������� ����������
	void make_transaction();
	//���������� � ����������
	void transaction_info() const;

protected:
	//������� �������
	Account* account_ = nullptr;
	//����� ����������
	decimal<2> amount_;
	//������
	currencies currency_ = Ruble;
	//������ ����������
	status status_ = status::toprocessing;
	//��� �������� (�����/��������)
	operation operation_ = operation::deposit;
	//�����
	place place_ = place::department;

	//������ �������
	void set_account(Account* new_account) { account_ = new_account; }
	//������ ����� ����������
	void set_amount(const decimal<2>& new_amount) { amount_ = new_amount; }
	//������ ������ ����������
	void set_currency(const currencies& new_currency) { currency_ = new_currency; }
	//������ ������ ����������
	void set_status(const status& new_status) { status_ = new_status; }
	//������ ��� �������� (�����/��������)
	void set_operation(const operation& new_operation) { operation_ = new_operation; }
	//������ �����
	void set_place(const place& new_place) { place_ = new_place; }

};


