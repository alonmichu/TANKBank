#pragma once
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

class Date
{
public:
	// �����������
	Date(const int year = 1970, const int month = 1, const int day = 1);
	// ����������� �����������
	Date(const Date& d);
	// ����������
	~Date() { ; }

	// ���������� �� ��� ���
	bool IsLeapYear(const int year) const;
	// ������, ���� ��� �������� ����
	bool IsInvalidDate(const int year, const int month, const int day) const;
	// ������, ���� ��� �������� ����
	bool IsInvalidDate() const;
	// ����������, ������� ���� � ������� ������
	int YearsOfMonth(const int year, const int month) const;
	// ����������� ����
	void ToCorrect();
	//output
	void Display() const;

	// ����� ���� �������� ������� ����� ���� �����?
	Date operator+(int days);
	// ����� ���� �������� ������� ����� ����?
	Date operator-(int days);
	// ����������� ���
	bool operator>(const Date& d);
	bool operator<(const Date& d);
	bool operator==(const Date& d);
	bool operator!=(const Date& d);
	bool operator>=(const Date& d);
	bool operator<=(const Date& d);
	// �������������� - ++
	Date& operator++();
	// post ++ 
	Date operator ++ (int);
	// �������
	Date& operator--();
	// ���� --- 
	Date operator--(int);

	//�������
	void set_year(const int year) { _year = year; }
	void set_month(const int month) { _month = month; }
	void set_day(const int day) { _day = day; }

	//�������
	int get_year() const { return _year; }
	int get_month() const { return _month; }
	int get_day() const { return _day; }

private:
	int _month = 1;
	int _day = 1;
	int _year = 1970;

};


