#pragma once
#include "Account.h"
#include <string>
using namespace std;

enum pay_systems :char { Lisa = 'L', MasterBard = 'M', HoMiR = 'H' };

//�����
class Card
{
	friend class DataBase;
public:
	//�����������
	Card(const pay_systems& pay_system);

	//�������� ����� �����
	string get_card_id() const { return card_id_; }
	//�������� ��������� �������
	string get_pay_system() const;
	//�������� ������ �� ����
	Account* get_account() const { return my_account_; }
	//������ �� �����
	bool is_active() const { return active_; }
	//��� �����
	string get_bank_name() const { return bank_title_; }
	//
	decimal<2> get_limit() const { return limit_; }
	//������ �����
	string get_currency() const;

protected:
	//����� �����
	string card_id_ = "";
	//��������� �������
	pay_systems pay_system_ = Lisa;
	//��������������� ����
	Account* my_account_ = nullptr;
	//������� �� �����
	bool active_ = true;
	//�������� �����
	string bank_title_ = "T.A.N.K.";
	//
	decimal<2> limit_;

	//�������� ����� �����
	void set_card_id(const string& new_card_id) { card_id_ = new_card_id; }
	//�������� ��������� �������
	void set_pay_system(const pay_systems& new_pay_system) { pay_system_ = new_pay_system; }
	//�������� ����
	void set_account(Account* new_account) { my_account_ = new_account; }
	//
	void set_limit(const decimal<2>& new_limit) { limit_ = new_limit; }

};

