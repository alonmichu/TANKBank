#pragma once
#include "BankAccount.h"
#include "Date.h"
#include <limits>

enum sex :char { Man = 'M', Woman = 'W', NonBinary = 'B', Transgender = 'T' };

//������� ����������� ����
class PersonalBankAccount : public BankAccount
{
public:
	//�����������
	PersonalBankAccount();
	//��������� �����������
	void registration();
	//������ ���������� � �����������
	void print_info();
	//��������� ���������� � �������
	void change_info();
	//������ ����
	void print_menu();
	//������� ��� ����������� ���. ����
	void reg_name();
	void reg_surname();
	void reg_patronymic();
	void reg_birth();
	void reg_sex();
	void reg_passport();

	//�������� ������� �������
	string get_surname() const { return surname_; }
	//�������� �������� �������(���� ��� ����)
	string get_patronymic()const { return patronymic_; }
	//�������� ���� �������� �������
	Date get_birth_date() const { return birth_date_; }
	//�������� ��� �������
	string get_my_sex() const;
	//�������� ����� �������� �������
	string get_passport_num()const { return passport_num_; }

	//������ ������� �������
	void set_surname(const string& new_surname) { surname_ = new_surname; }
	//������ �������� �������(���� ��� ����)
	void set_patronymic(const string& new_patronymic) { patronymic_ = new_patronymic; }
	//������ ���� �������� �������
	void set_birth_date(const Date& new_birth_date) { birth_date_ = new_birth_date; }
	//������ ��� �������
	void set_my_sex(const sex& new_sex) { my_sex_ = new_sex; }
	//������ ����� �������� �������
	void set_passport_num(const string& new_passport_num) { passport_num_ = new_passport_num; }

	//���� �� ��������
	bool has_patronymic();

protected:
	//�������
	string surname_ = "";
	//��������
	string patronymic_ = "";
	//���� ��������
	Date birth_date_;
	//���
	sex my_sex_ = NonBinary;
	//�������
	string passport_num_ = "";
	//������� ��������������� ��� ������ (������ ������ ��� ����������)
	bool registrated_ = false;

};

