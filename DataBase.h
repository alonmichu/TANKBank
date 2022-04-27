#pragma once
#include "BankAccount.h"
#include "PersonalBankAccount.h"
#include "Transaction.h"
#include "Card.h"
#include "CashTransaction.h"
#include <vector>

//���� ������
class DataBase
{
public:
	//����������� �������
	void client_registration(BankAccount* client);
	//����������� �������� �����
	void account_openning(BankAccount* client, const decimal<2>& first_amount,
		const currencies& currency, const decimal<2>& limit);
	//��������� ����� � �����
	void card_registration(Account* acccount, Card* card);
	//������������ �����
	void relink_card(Account* new_account, Card* card);
	//�������� �����
	void close_card(Card* card);
	//����������
	bool transaction(Account* write_off_account, Account* credit_account,
		const decimal<2>& amount);
	bool transaction(Card* write_off_card, Account* credit_account,
		const decimal<2>& amount);
	bool transaction(Account* write_off_account, Card* credit_card,
		const decimal<2>& amount);
	bool transaction(Card* write_off_card, Card* credit_card,
		const decimal<2>& amount);
	//�������� � ���������
	bool cash_transaction(Account* account, const decimal<2>& amount,
		const operation& operation);
	bool cash_transaction(Card* card, const decimal<2>& amount,
		const operation& operation);
	//�������� �����
	void close_account_transaction(Account* write_off_account, Account* credit_account);
	void close_account_cash(Account* write_off_account);

protected:
	//������ ��������
	vector<BankAccount*> users_;
	long int accounts_num_ = 0;
	long int card_num_ = 0;

};

