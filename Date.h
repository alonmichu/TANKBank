#pragma once
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

class Date
{
public:
	// конструктор
	Date(const int year = 1970, const int month = 1, const int day = 1);
	// конструктор копирования
	Date(const Date& d);
	// деструктор
	~Date() { ; }

	// високосный ли это год
	bool IsLeapYear(const int year) const;
	// Судите, если это законная дата
	bool IsInvalidDate(const int year, const int month, const int day) const;
	// Судите, если это законная дата
	bool IsInvalidDate() const;
	// определить, сколько дней в текущем месяце
	int YearsOfMonth(const int year, const int month) const;
	// исправление даты
	void ToCorrect();
	//output
	void Display() const;

	// Какая дата является текущей датой дней после?
	Date operator+(int days);
	// Какая дата является текущей датой дней?
	Date operator-(int days);
	// соотношение дат
	bool operator>(const Date& d);
	bool operator<(const Date& d);
	bool operator==(const Date& d);
	bool operator!=(const Date& d);
	bool operator>=(const Date& d);
	bool operator<=(const Date& d);
	// предварительно - ++
	Date& operator++();
	// post ++ 
	Date operator ++ (int);
	// ведущий
	Date& operator--();
	// пост --- 
	Date operator--(int);

	//сеттеры
	void set_year(const int year) { _year = year; }
	void set_month(const int month) { _month = month; }
	void set_day(const int day) { _day = day; }

	//геттеры
	int get_year() const { return _year; }
	int get_month() const { return _month; }
	int get_day() const { return _day; }

private:
	int _month = 1;
	int _day = 1;
	int _year = 1970;

};


