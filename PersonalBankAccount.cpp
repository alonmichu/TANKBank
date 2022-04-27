#include "PersonalBankAccount.h"

PersonalBankAccount::PersonalBankAccount()
{
	registrated_ = false;
}

void PersonalBankAccount::reg_name()
{
	string name;
	cout << "     Enter your name: ";
	getline(cin, name);
	set_name(is_correct_str(name, 's'));
}

void PersonalBankAccount::reg_surname()
{
	string surname;
	cout << "     Enter your surname: ";
	getline(cin, surname);
	set_surname(is_correct_str(surname, 's'));
}

void PersonalBankAccount::reg_patronymic()
{
	string patronymic;
	cout << "     Enter your patronimyc if you have, else press enter: ";
	getline(cin, patronymic);
	set_patronymic(is_correct_str(patronymic, 's'));
}

void PersonalBankAccount::reg_birth()
{
	cout << "     Enter your birth date(DD MM YYYY): ";
	string day, month, year;
	Date birth;
	cin >> day;
	birth.set_day(stoi(is_correct_str(day, 'd')));
	cin >> month;
	birth.set_month(stoi(is_correct_str(month, 'm')));
	cin >> year;
	birth.set_year(stoi(is_correct_str(year, 'y')));
	if (birth.IsInvalidDate())
		cout << "     Your Birth wasn't save\n";
	else
		set_birth_date(birth);
}

void PersonalBankAccount::reg_sex()
{
	cout << "     Enter your sex(0 - Man, 1 - Woman, 2 - NonBinary, 3 - Transgender): ";
	int tmp_sex;
	cin >> tmp_sex;
	try
	{
		switch (tmp_sex)
		{
		case 0: my_sex_ = Man; break;
		case 1: my_sex_ = Woman; break;
		case 2: my_sex_ = NonBinary; break;
		case 3: my_sex_ = Transgender; break;
		default: throw (tmp_sex); break;
		}
	}
	catch (int tmp_sex)
	{
		cout << "     Sex was saved as NonBinary\n";
	}
}

void PersonalBankAccount::reg_passport()
{
	string passport;
	cout << "     Enter your passport: ";
	getline(cin, passport);
	set_passport_num(is_correct_date(passport, 'p', 10));
}

void PersonalBankAccount::registration()
{
	if (registrated_)
	{
		cout << "Account has been registrated already" << endl;
		return;
	}
	cout << "Welcome to T.A.N.K. Bank!" << '\n';
	cout << "Form:" << '\n';
	reg_name();
	reg_surname();
	reg_patronymic();
	reg_birth();
	reg_sex();
	reg_phone();
	reg_passport();
	reg_address();
	registrated_ = true;
}

string PersonalBankAccount::get_my_sex() const
{
	switch (my_sex_)
	{
	case 'M': return "Man";
	case 'W': return "Woman";
	case 'B': return "NonBinary";
	case 'T': return "Transgender";
	}
	return "";
}

bool PersonalBankAccount::has_patronymic()
{
	if (patronymic_ != "")
		return true;
	patronymic_ = "";
	return false;
}

void PersonalBankAccount::print_info()
{
	cout << "Saved information:\n";
	cout << "Name: " << get_name() << '\n';
	cout << "Surame: " << get_surname() << '\n';
	if (has_patronymic())
		cout << "Patronymic: " << get_patronymic() << '\n';
	cout << "Birthday: ";
	birth_date_.Display();
	cout << "\n";
	cout << "Sex: " << get_my_sex() << '\n';
	cout << "Passport: " << get_passport_num() << '\n';
	cout << "Phone: " << get_phone_number() << '\n';
	print_address();
}

void PersonalBankAccount::print_menu()
{
	system("cls");// очищаем экран
	cout << "Chose the field for changes" << endl;
	cout << "1. Name" << endl;
	cout << "2. Surname" << endl;
	cout << "3. Patronymic" << endl;
	cout << "4. Birth" << endl;
	cout << "5. Sex" << endl;
	cout << "6. Passport" << endl;
	cout << "7. Phone" << endl;
	cout << "8. Print new information" << endl;
	cout << "9. Address" << endl;
	cout << "10.Exit" << endl;
	cout << ">>";
}

void PersonalBankAccount::change_info()
{
	int variant; // выбранный пункт меню
	do
	{
		print_menu(); // выводим меню на экран

		cin >> variant;

		switch (variant)
		{
		case 1:
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			reg_name();
			break;
		case 2:
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			reg_surname();
			break;
		case 3:
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			reg_patronymic();
			break;
		case 4:
			reg_birth();
			break;
		case 5:
			reg_sex();
			break;
		case 6:
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			reg_passport();
			break;
		case 7:
			reg_phone();
			break;
		case 8:
			print_info();
			break;
		case 9:
			reg_address();
			break;
		default:
			continue;
		}
		if (variant != 10)
			system("pause");
	} while (variant != 10);
}