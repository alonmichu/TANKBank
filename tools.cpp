#include "tools.h"

string num_to_id(int num, const int len)
{
	string s, res;
	int i = len - 1;
	while (i >= 0)
	{
		s += to_string(num % 10);
		num /= 10;
		i--;
	}
	for (int i = len - 1; i >= 0; i--)
		res.push_back(s[i]);
	return res;
}

int id_to_num(const string& id)
{
	int num = stoi(id);
	return num;
}

void delete_space(string& s)
{
	string res = "";
	for (int i = 0; i < s.length(); i++)
		if (s[i] != ' ')
			res += s[i];
	s = res;
}

string today_date()
{
	time_t now = time(0);
	char buf[26];
	ctime_s(buf, 26, &now);
	string res = "";
	for (int i = 0; i < 26; i++)
		res += buf[i];
	return res;
}

Date string_to_date(const string& date)
{
	Date now;
	string month = date.substr(4, 3);
	int month_ = atoi(month.c_str());
	if (month == "Jan")
		month_ = 1;
	else if (month == "Feb")
		month_ = 2;
	else if (month == "Mar")
		month_ = 3;
	else if (month == "Apr")
		month_ = 4;
	else if (month == "May")
		month_ = 5;
	else if (month == "Jun")
		month_ = 6;
	else if (month == "Jul")
		month_ = 7;
	else if (month == "Aug")
		month_ = 8;
	else if (month == "Sep")
		month_ = 9;
	else if (month == "Oct")
		month_ = 10;
	else if (month == "Nov")
		month_ = 11;
	else if (month == "Dec")
		month_ = 12;
	int day_ = stoi(date.substr(8, 2));
	int year_ = stoi(date.substr(20, 4));
	now.set_day(day_);
	now.set_month(month_);
	now.set_year(year_);
	return now;
}

void time_now(int& hour, int& min, int& sec)
{
	string now = today_date();
	hour = stoi(now.substr(11, 2));
	min = stoi(now.substr(14, 2));
	sec = stoi(now.substr(17, 2));
}

string str_time_now()
{
	string now = today_date();
	string res = "";
	res = now.substr(11, 2) + ":" + now.substr(14, 2) + ":" + now.substr(17, 2);
	return res;
}

string is_correct_str(string s, char ch)
{
	bool input_correct = false;
	string cur = s;
	while (input_correct == false)
	{
		try
		{
			if (ch == 's')
			{
				for (int i = 0; i < cur.size(); i++)
					if (not isalpha(cur[i]))
						throw(cur);
			}
			else
			{
				for (int i = 0; i < cur.size(); i++)
					if (not isdigit(cur[i]))
						throw(cur);
			}
			input_correct = true;
		}
		catch (string incorrect)
		{
			cout << "     " << incorrect << " is incorrect, try again: ";
			getline(cin, cur);
		}
	}
	return cur;
}

string is_correct_date(string s, char ch, int count)
{
	bool input_correct = false;
	string cur = s;
	while (input_correct == false)
	{
		try
		{
			if (ch == 't' && cur.size() > 1)
			{
				if (cur[0] == '+')
					cur = cur.substr(2);
				else if (cur[0] == '8')
					cur = cur.substr(1);
			}
			string res = "";
			int cnt = 0;
			for (int i = 0; i < cur.size(); i++)
			{
				if (isdigit(cur[i]))
				{
					res += cur[i];
					cnt++;
				}
			}
			if (cnt == count)
			{
				input_correct = true;
				cur = res;
			}
			else
				throw(cur);
		}
		catch (string incorrect)
		{
			cout << "     " << incorrect << " is incorrect, try again: ";
			getline(cin, cur);
		}
	}
	return cur;
}