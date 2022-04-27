#include "Date.h"

Date::Date(const int year, const int month, const int day)
{
	_year = year;
	_month = month;
	_day = day;
	if (IsInvalidDate(_year, _month, _day))
	{
		_year = 1970;
		_month = 1;
		_day = 1;
	}
}

Date::Date(const Date& d)
{
	_year = d._year;
	_month = d._month;
	_day = d._day;
}

bool Date::IsLeapYear(const int year) const
{
	if (year % 400 == 0 || year % 4 == 0 && year % 100 != 0)
		return true;
	return false;
}

bool Date::IsInvalidDate(const int year, const int month, const int day) const
{
	if (year < 1000 || month < 0 || month > 12 || year>2022 ||
		day < 0 || day > YearsOfMonth(year, month))
	{
		return true;
	}
	return false;
}

bool Date::IsInvalidDate() const
{
	if (_year < 1000 || _month < 0 || _month > 12 || _year>2022 ||
		_day < 0 || _day > YearsOfMonth(_year, _month))
	{
		return true;
	}
	return false;
}

int Date::YearsOfMonth(const int year, const int month) const
{
	int day;
	int days[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	day = days[month];
	if (month == 2 && IsLeapYear(year))
		day += 1;
	return day;
}

void Date::ToCorrect()
{
	while (_day > YearsOfMonth(_year, _month) || _day <= 0)
	{
		if (_day <= 0)
		{
			_day += YearsOfMonth(_year, (_month - 1));
			if (_month == 1)
			{
				_month = 12;
				_year--;
			}
			else
				_month--;
		}
		else
		{
			_day -= YearsOfMonth(_year, _month);
			if (_month == 12)
			{
				_year++;
				_month = 1;
			}
			else
			{
				_month++;
			}
		}
	}
}

void Date::Display() const
{
	string res = "";
	if (_day >= 10)
		res += to_string(_day);
	else
		res += "0" + to_string(_day);
	res += ".";
	if (_month >= 10)
		res += to_string(_month);
	else
		res += "0" + to_string(_month);
	res += ".";
	res += to_string(_year);
	cout << res;
}

Date Date::operator+(int days)
{
	Date tmp(*this);
	tmp._day += days;
	tmp.ToCorrect();
	return tmp;
}

// Какая дата является текущей датой дней?
Date Date::operator-(int days)
{
	Date tmp(*this);
	tmp._day -= days;
	tmp.ToCorrect();
	return tmp;
}

// соотношение дат
bool Date::operator>(const Date& d)
{
	return (_year > d._year ||
		(_year == d._year && _month > d._month) ||
		(_year == d._year && _month == d._month && _day > d._day));
}

bool Date::operator<(const Date& d)
{
	return (_year < d._year ||
		(_year == d._year && _month < d._month) ||
		(_year == d._year && _month == d._month && _day < d._day));
}

bool Date::operator==(const Date& d)
{
	return  ((_year == d._year) && (_month == d._month) && (_day == d._day));
}

bool Date::operator!=(const Date& d)
{
	return !(*this == d);
}

bool Date::operator>=(const Date& d)
{
	return !(*this < d);
}

bool Date::operator<=(const Date& d)
{
	return !(*this > d);
}

// предварительно - ++
Date& Date::operator++()
{
	(*this)++;
	return *this;
}

// post ++ 
Date Date::operator ++ (int)
{
	Date tmp(*this);
	(*this) = (*this) + 1;
	return tmp;
}

// ведущий
Date& Date::operator--()
{
	(*this)--;
	return *this;
}

// пост --- 
Date Date::operator--(int)
{
	Date tmp(*this);
	(*this)--;
	return tmp;
}
