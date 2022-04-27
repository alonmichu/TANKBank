#pragma once
#include "tools.h"
#include "Account.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//���������� �������
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
	//�������� ��� �������
	string get_name() const { return name_; }
	//�������� ����� �������
	address get_address() const {
		return address_;
	}
	//�������� ������ ����� id
	decimal<2> get_balance_on_account(const string& account_id) const;
	//�������� id 
	string get_id() const { return account_id_; }
	//�������� ����� �������
	string get_phone_number() const { return phone_number_; }
	//������� ��� ����, ����� �������� ������
	string get_country()const { return address_.country_; }
	string get_city()const { return address_.city_; }
	string get_street()const { return address_.street_; }
	string get_building()const { return address_.building_; }
	string get_flat()const { return address_.flat_; }

	//������ ��� �������
	void set_name(const string& new_name) { name_ = new_name; }
	//������ ����� �������
	void set_address(const string& country = "", const string& city = "",
		const string& street = "", const string& building = "", const string& flat = "") {
		address_.country_ = country;
		address_.city_ = city;
		address_.street_ = street;
		address_.building_ = building;
		address_.flat_ = flat;
	}
	//������ ����� �������
	void set_phone_number(const string& new_phone_number) { phone_number_ = new_phone_number; }
	//������ id
	void set_id(const string& new_id) { account_id_ = new_id; }

	//������ ������ �������
	vector<Account*> accounts_;

	//������� ����������� �����, ������ �������� � �������(��� ���/�� ����)
	void reg_name();
	void reg_address();
	void reg_phone();

	//������ ������
	void print_address();
	//�������� ������� ��
	bool has_flat();

protected:
	//���
	string name_ = "";
	//id �����
	string account_id_ = "";
	//�����
	address address_;
	//����� �������� �������
	string phone_number_ = "";

};

