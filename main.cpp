#include "tools.h"
#include "PersonalBankAccount.h"
#include "DataBase.h"
#include "CashTransaction.h"
#include "LegalEntityBankAccount.h"
#include <string>
#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	string n;
	DataBase data_base;
	PersonalBankAccount client1;
	LegalEntityBankAccount client2;
	//Регистрация клиента и изменение информации о нём
	client1.registration();
	client1.print_info();
	client1.change_info();
	client2.registration();
	client2.print_info();
	client2.change_info();

	//Заносим клиентов в базу данных
	data_base.client_registration(&client1);
	data_base.client_registration(&client2);

	//Открытие сёта и привязка карты
	decimal<2> amount;
	decimal<2>limit1;
	decimal<2>limit2;
	limit1 = 1000;
	limit2 = 0;
	amount = 2345.67;
	data_base.account_openning(&client1, amount, Ruble, limit1);
	Card new_card1(Lisa);
	data_base.card_registration(client1.accounts_[0], &new_card1);
	data_base.account_openning(&client2, amount, Ruble, limit2);
	Card new_card2(HoMiR);
	data_base.card_registration(client2.accounts_[0], &new_card2);

	//Проверка привязки к одному счёту одной карты
	Card new_card(MasterBard);
	data_base.card_registration(client1.accounts_[0], &new_card);

	//Создание второго счёта для перепривязки карты
	data_base.account_openning(&client1, amount, Ruble, limit1);
	data_base.relink_card(client1.accounts_[1], &new_card1);

	//Снятие наличных
	amount = 10000;
	data_base.cash_transaction(new_card1.get_account(), amount, operation::withdraw);
	amount = 1200;
	data_base.cash_transaction(new_card1.get_account(), amount, operation::withdraw);
	amount = 100;
	data_base.cash_transaction(new_card1.get_account(), amount, operation::withdraw);
	amount = 2400;
	data_base.cash_transaction(new_card2.get_account(), amount, operation::withdraw);
	amount = 100;
	data_base.cash_transaction(new_card2.get_account(), amount, operation::withdraw);

	//Транзакции
	amount = 100;
	data_base.transaction(new_card2.get_account(), new_card1.get_account(), amount);
	amount = 10000;
	data_base.transaction(new_card2.get_account(), new_card1.get_account(), amount);

	//Пополнение счёта наличными
	amount = 1200;
	data_base.cash_transaction(new_card1.get_account(), amount, operation::deposit);
	amount = 100;
	data_base.cash_transaction(new_card2.get_account(), amount, operation::deposit);

	//Закрытие карты без перевода
	data_base.close_card(&new_card1);

	//Закрытие счёта(с транзакцией/снятием)
	data_base.close_account_transaction(client1.accounts_[1], client1.accounts_[0]);
	data_base.close_account_cash(client2.accounts_[0]);
	data_base.close_card(&new_card2);
	data_base.close_account_cash(client2.accounts_[0]);



	return 0;
}