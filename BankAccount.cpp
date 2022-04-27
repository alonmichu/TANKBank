#include "BankAccount.h"

decimal<2> BankAccount::get_balance_on_account(const string& account_id) const
{
	int num = id_to_num(account_id);
	return accounts_[num]->get_balance();
}

void BankAccount::reg_name()
{
	string name;
	cout << "     Enter your name: ";
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	getline(cin, name);
	set_name(is_correct_str(name, 's'));
}

void BankAccount::reg_phone()
{
	string phone;
	cout << "     Enter your phone number: ";
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	getline(cin, phone);
	set_phone_number(is_correct_date(phone, 't', 10));
}

void BankAccount::reg_address()
{
	string country, city, building, street, flat;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	cout << "     Enter your country: ";
	getline(cin, country);
	cout << "     Enter your city: ";
	getline(cin, city);
	cout << "     Enter your street: ";
	getline(cin, street);
	cout << "     Enter your building: ";
	getline(cin, building);
	cout << "     Enter your flat(if it's necessary, else press enter): ";
	getline(cin, flat);
	set_address(country, city, street, building, flat);
}

void BankAccount::print_address()
{
	cout << "Address: " << "\n" << get_country()
		<< '\n' << get_city() << '\n' << get_street()
		<< '\n' << get_building() << '\n';
	if (has_flat())
	{
		cout << get_flat() << '\n';
	}
}

bool BankAccount::has_flat()
{
	if (address_.flat_ != "")
		return true;
	return false;
}