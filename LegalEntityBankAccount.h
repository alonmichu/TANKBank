#pragma once
#include "BankAccount.h"

class LegalEntityBankAccount : public BankAccount
{
public:
	//�����������
	LegalEntityBankAccount();
	//��������� �����������
	void registration();

	//�������� ����������������� ����� �����������������
	string get_inn() const { return inn_; }
	//�������� �������� ��������������� ��������������� �����
	string get_ogrn() const { return ogrn_; }
	//�������� ��� ���������
	string get_director_name() const { return director_name_; }
	//�������� ������� ���������
	string get_director_surname() const { return director_surname_; }
	//�������� �������� ���������(���� ��� ����)
	string get_director_patronymic() const { return director_patronymic_; }
	//�������� ��� �������� ����������
	string get_accountant_name() const { return accountant_name_; }
	//�������� ������� �������� ����������
	string get_accountant_surname() const { return accountant_surname_; }
	//�������� �������� �������� ����������(���� ��� ����)
	string get_accountant_patronymic() const { return accountant_patronymic_; }
	//pin-code
	string get_e_key() const { return e_key_; }

	//�������� ����������������� ����� �����������������
	void set_inn(const string& inn) { inn_ = inn; }
	//�������� �������� ��������������� ��������������� �����
	void set_ogrn(const string& ogrn) { ogrn_ = ogrn; }
	//�������� ��� �������
	void set_director_name(const string& director_name)	{
		director_name_ = director_name;
	}
	//�������� ������� �������
	void set_director_surname(const string& director_surname) {
		director_surname_ = director_surname;
	}
	//�������� �������� ���������
	void set_director_patronymic(const string& director_patronymic)	{
		director_patronymic_ = director_patronymic;
	}
	//�������� ��� �������� ����������
	void set_accountant_name(const string& accountant_name)	{
		accountant_name_ = accountant_name;
	}
	//�������� ������� �������� ����������
	void set_accountant_surname(const string& accountant_surname) {
		accountant_surname_ = accountant_surname;
	}
	//�������� �������� �������� ����������
	void set_accountant_patronymic(const string& accountant_patronymic)	{
		accountant_patronymic_ = accountant_patronymic;
	}

	//���� �� ��������
	bool director_has_patronymic();
	bool accountant_has_patronymic();

	//������� ����������� �������� ������� (������)
	void create_e_key();

	//����������� ������ �� ����
	void reg_inn();
	void reg_ogrn();
	void reg_dir_name();
	void reg_dir_surname();
	void reg_dir_patronymic();
	void reg_ac_name();
	void reg_ac_surname();
	void reg_ac_patronymic();

	//������ ���������� � �� �������
	void print_info();
	void change_info();
	void print_menu();

protected:
	//���
	string name_ = "";
	//���
	string inn_ = "";
	//O���
	string ogrn_ = "";
	//Director ����������� �������������� �����
	string director_name_ = "";
	string director_surname_ = "";
	string director_patronymic_ = "";
	//General accountant ������� ���������
	string accountant_name_ = "";
	string accountant_surname_ = "";
	string accountant_patronymic_ = "";
	//pin-code: ����������� �������� �������
	string e_key_ = "";
	//������� ��������������� ��� ������ (������ ������ ��� ����������)
	bool registrated_ = false;

};
