#pragma once
#include "Account.h"
#include <string>
using namespace std;

enum pay_systems :char { Lisa = 'L', MasterBard = 'M', HoMiR = 'H' };

//Карта
class Card
{
	friend class DataBase;
public:
	//Конструктор
	Card(const pay_systems& pay_system);

	//Показать номер карты
	string get_card_id() const { return card_id_; }
	//Показать платежную систему
	string get_pay_system() const;
	//Получить ссылку на счет
	Account* get_account() const { return my_account_; }
	//Ативна ли карта
	bool is_active() const { return active_; }
	//Имя банка
	string get_bank_name() const { return bank_title_; }
	//
	decimal<2> get_limit() const { return limit_; }
	//Валюта счета
	string get_currency() const;

protected:
	//Номер карты
	string card_id_ = "";
	//Платежная система
	pay_systems pay_system_ = Lisa;
	//Соответствующий счет
	Account* my_account_ = nullptr;
	//Закрыта ли карта
	bool active_ = true;
	//Название банка
	string bank_title_ = "T.A.N.K.";
	//
	decimal<2> limit_;

	//Изменить номер карты
	void set_card_id(const string& new_card_id) { card_id_ = new_card_id; }
	//Изменить платежную систему
	void set_pay_system(const pay_systems& new_pay_system) { pay_system_ = new_pay_system; }
	//Изменить счет
	void set_account(Account* new_account) { my_account_ = new_account; }
	//
	void set_limit(const decimal<2>& new_limit) { limit_ = new_limit; }

};

