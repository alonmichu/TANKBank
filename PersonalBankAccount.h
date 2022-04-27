#pragma once
#include "BankAccount.h"
#include "Date.h"
#include <limits>

enum sex :char { Man = 'M', Woman = 'W', NonBinary = 'B', Transgender = 'T' };

//Аккаунт физического лица
class PersonalBankAccount : public BankAccount
{
public:
	//Конструктор
	PersonalBankAccount();
	//Первичная регистрация
	void registration();
	//Печать информации о регистрации
	void print_info();
	//Изменение информации о клиенте
	void change_info();
	//Печать меню
	void print_menu();
	//Функции для регистрации физ. лица
	void reg_name();
	void reg_surname();
	void reg_patronymic();
	void reg_birth();
	void reg_sex();
	void reg_passport();

	//Показать фамилию клиента
	string get_surname() const { return surname_; }
	//Показать отчество клиента(если оно есть)
	string get_patronymic()const { return patronymic_; }
	//Показать дату рождения клиента
	Date get_birth_date() const { return birth_date_; }
	//Показать пол клиента
	string get_my_sex() const;
	//Показать номер паспорта клиента
	string get_passport_num()const { return passport_num_; }

	//Задать фамилию клиента
	void set_surname(const string& new_surname) { surname_ = new_surname; }
	//Задать отчество клиента(если оно есть)
	void set_patronymic(const string& new_patronymic) { patronymic_ = new_patronymic; }
	//Задать дату рождения клиента
	void set_birth_date(const Date& new_birth_date) { birth_date_ = new_birth_date; }
	//Задать пол клиента
	void set_my_sex(const sex& new_sex) { my_sex_ = new_sex; }
	//Задать номер паспорта клиента
	void set_passport_num(const string& new_passport_num) { passport_num_ = new_passport_num; }

	//Есть ли отчество
	bool has_patronymic();

protected:
	//Фамилия
	string surname_ = "";
	//Отчество
	string patronymic_ = "";
	//Дата рождения
	Date birth_date_;
	//Пол
	sex my_sex_ = NonBinary;
	//Паспорт
	string passport_num_ = "";
	//Аккаунт зарегестрирован или пустой (только создан для заполнения)
	bool registrated_ = false;

};

