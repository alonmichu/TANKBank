#pragma once
#include "BankAccount.h"

class LegalEntityBankAccount : public BankAccount
{
public:
	//Конструктор
	LegalEntityBankAccount();
	//Первичная регистрация
	void registration();

	//Показать идентификационный номер налогоплательщика
	string get_inn() const { return inn_; }
	//Показать основной государственный регистрационный номер
	string get_ogrn() const { return ogrn_; }
	//Показать имя директора
	string get_director_name() const { return director_name_; }
	//Показать фамилию директора
	string get_director_surname() const { return director_surname_; }
	//Показать отчество директора(если оно есть)
	string get_director_patronymic() const { return director_patronymic_; }
	//Показать имя главного бухгалтера
	string get_accountant_name() const { return accountant_name_; }
	//Показать фамилию главного бухгалтера
	string get_accountant_surname() const { return accountant_surname_; }
	//Показать отчество главного бухгалтера(если оно есть)
	string get_accountant_patronymic() const { return accountant_patronymic_; }
	//pin-code
	string get_e_key() const { return e_key_; }

	//Записать идентификационный номер налогоплательщика
	void set_inn(const string& inn) { inn_ = inn; }
	//Записать основной государственный регистрационный номер
	void set_ogrn(const string& ogrn) { ogrn_ = ogrn; }
	//Записать имя клиента
	void set_director_name(const string& director_name)	{
		director_name_ = director_name;
	}
	//Записать фамилию клиента
	void set_director_surname(const string& director_surname) {
		director_surname_ = director_surname;
	}
	//Записать отчество директора
	void set_director_patronymic(const string& director_patronymic)	{
		director_patronymic_ = director_patronymic;
	}
	//Записать имя главного бухгалтера
	void set_accountant_name(const string& accountant_name)	{
		accountant_name_ = accountant_name;
	}
	//Записать фамилию главного бухгалтера
	void set_accountant_surname(const string& accountant_surname) {
		accountant_surname_ = accountant_surname;
	}
	//Записать отчество главного бухгалтера
	void set_accountant_patronymic(const string& accountant_patronymic)	{
		accountant_patronymic_ = accountant_patronymic;
	}

	//Есть ли отчество
	bool director_has_patronymic();
	bool accountant_has_patronymic();

	//Создать электронную цифровую подпись (рандом)
	void create_e_key();

	//Регистрация данных юр лица
	void reg_inn();
	void reg_ogrn();
	void reg_dir_name();
	void reg_dir_surname();
	void reg_dir_patronymic();
	void reg_ac_name();
	void reg_ac_surname();
	void reg_ac_patronymic();

	//Печать информации о юр клиенте
	void print_info();
	void change_info();
	void print_menu();

protected:
	//Имя
	string name_ = "";
	//ИНН
	string inn_ = "";
	//OГРН
	string ogrn_ = "";
	//Director единоличный исполнительный орган
	string director_name_ = "";
	string director_surname_ = "";
	string director_patronymic_ = "";
	//General accountant главный бухгалтер
	string accountant_name_ = "";
	string accountant_surname_ = "";
	string accountant_patronymic_ = "";
	//pin-code: электронная цифровая подпись
	string e_key_ = "";
	//Аккаунт зарегестрирован или пустой (только создан для заполнения)
	bool registrated_ = false;

};
