#pragma once
#include "Date.h"
#include <string>
#include <ctime>
using namespace std;

//����� � ������������� (len ������)
string num_to_id(int num, const int len);
//����� �� ��������������
int id_to_num(const string& id);
//���� � �����
string today_date();
//���������� ����������� ����
Date string_to_date(const string& date);
//����� �� ������ ������� �������
void time_now(int& hour, int& min, int& sec);
//����� �� ������ ������� �������
string str_time_now();
//
string is_correct_str(string s, char ch);
//
string is_correct_date(string s, char ch, int count);