#include "LegalEntityBankAccount.h"

LegalEntityBankAccount::LegalEntityBankAccount()
{
	registrated_ = false;
}

void LegalEntityBankAccount::reg_inn()
{
	string inn;
	cout << "     Enter INN of your company: ";
	getline(cin, inn);
	set_inn(is_correct_date(inn, 'i', 12));
}

void LegalEntityBankAccount::reg_ogrn()
{
	string ogrn;
	cout << "     Enter OGRN of your company: ";
	getline(cin, ogrn);
	set_ogrn(is_correct_date(ogrn, 'o', 13));
}

void LegalEntityBankAccount::reg_dir_name()
{
	string name;
	cout << "     Enter director's name: ";
	getline(cin, name);
	set_director_name(is_correct_str(name, 's'));
}

void LegalEntityBankAccount::reg_dir_surname()
{
	string surname;
	cout << "     Enter director's surname: ";
	getline(cin, surname);
	set_director_surname(is_correct_str(surname, 's'));
}

void LegalEntityBankAccount::reg_dir_patronymic()
{
	string patronymic;
	cout << "     Enter director's patronymic, if director has one, else press enter: ";
	getline(cin, patronymic);
	set_director_patronymic(is_correct_str(patronymic, 's'));
}

void LegalEntityBankAccount::reg_ac_name()
{
	string name;
	cout << "     Enter general accountant's name: ";
	getline(cin, name);
	set_accountant_name(is_correct_str(name, 's'));
}

void LegalEntityBankAccount::reg_ac_surname()
{
	string surname;
	cout << "     Enter general accountant's surname: ";
	getline(cin, surname);
	set_accountant_surname(is_correct_str(surname, 's'));
}

void LegalEntityBankAccount::reg_ac_patronymic()
{
	string patronymic;
	cout << "     Enter general accountant's patronymic, if accountant has one, else press enter: ";
	getline(cin, patronymic);
	set_accountant_patronymic(is_correct_str(patronymic, 's'));
}

void LegalEntityBankAccount::registration()
{
	if (registrated_)
	{
		cout << "Account has been registrated already" << endl;
		return;
	}
	cout << "Welcome to T.A.N.K. Bank!" << '\n';
	cout << "Form:" << '\n';
	reg_name();
	reg_address();
	reg_inn();
	reg_ogrn();
	reg_dir_name();
	reg_dir_surname();
	reg_dir_patronymic();
	reg_ac_name();
	reg_ac_surname();
	reg_ac_patronymic();
	reg_phone();
	create_e_key();
	registrated_ = true;
}

bool LegalEntityBankAccount::director_has_patronymic()
{
	if (director_patronymic_ != "")
		return true;
	director_patronymic_ = "";
	return false;
}

bool LegalEntityBankAccount::accountant_has_patronymic()
{
	if (accountant_patronymic_ != "")
		return true;
	accountant_patronymic_ = "";
	return false;
}

void LegalEntityBankAccount::create_e_key()
{
	int len = rand() % 10 + 4;
	const char alphanum[] = "0123456789";
	string tmp_s = "";
	tmp_s.reserve(len);
	for (int i = 0; i < len; i++)
		tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
	e_key_ = tmp_s;
}

void LegalEntityBankAccount::print_info()
{
	cout << "Saved information:\n";
	cout << "Name: " << get_name() << '\n';
	print_address();
	cout << '\n';
	cout << "INN: " << get_inn() << '\n';
	cout << "OGRN: " << get_ogrn() << "\n";
	cout << "Director's name: " << get_director_name() << '\n';
	cout << "Director's surname: " << get_director_surname() << '\n';
	if (director_has_patronymic())
		cout << "Director's patronymic: " << get_director_patronymic() << '\n';
	cout << "Accountatn's name: " << get_accountant_name() << '\n';
	cout << "Accountant's surname: " << get_accountant_surname() << '\n';
	if (accountant_has_patronymic())
		cout << "Accountant's patronymic: " << get_accountant_patronymic() << '\n';
	cout << "Phone: " << get_phone_number() << '\n';
	cout << "Electronic digital signature: " << get_e_key() << "\n";
}

void LegalEntityBankAccount::print_menu()
{
	system("cls");// очищаем экран
	cout << "Chose the field for changes" << endl;
	cout << "1. Name" << endl;
	cout << "2. Address" << endl;
	cout << "3. Inn" << endl;
	cout << "4. OGRN" << endl;
	cout << "5. Director's name" << endl;
	cout << "6. Director's surname" << endl;
	cout << "7. Director's patronymic" << endl;
	cout << "8. Accountant's name" << endl;
	cout << "9. Accountant's surname" << endl;
	cout << "10. Accountant's patronymic" << endl;
	cout << "11. Phone" << endl;
	cout << "12. Print information" << endl;
	cout << "13. Exit" << endl;
	cout << ">>";
}

void LegalEntityBankAccount::change_info()
{
	int variant;
	do
	{
		print_menu();

		cin >> variant;

		switch (variant)
		{
		case 1:
			reg_name();
			break;

		case 2:
			reg_address();
			break;

		case 3:
			reg_inn();
			break;
		case 4:
			reg_ogrn();
			break;
		case 5:
			reg_dir_name();
			break;
		case 6:
			reg_dir_surname();
			break;
		case 7:
			reg_dir_patronymic();
			break;
		case 8:
			reg_ac_name();
			break;
		case 9:
			reg_ac_surname();
			break;
		case 10:
			reg_ac_patronymic();
			break;
		case 11:
			reg_phone();
			break;
		case 12:
			print_info();
			break;
		default:
			continue;
		}

		if (variant != 13)
			system("pause");
	} while (variant != 13);
}
