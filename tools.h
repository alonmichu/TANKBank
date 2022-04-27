#pragma once
#include "Date.h"
#include <string>
#include <ctime>
using namespace std;

//Номер в идентификатор (len знаков)
string num_to_id(int num, const int len);
//Номер по идентификатору
int id_to_num(const string& id);
//Дата и время
string today_date();
//Возвращает сегодняшнюю дату
Date string_to_date(const string& date);
//Время на момент запуска функции
void time_now(int& hour, int& min, int& sec);
//Время на момент запуска функции
string str_time_now();
//
string is_correct_str(string s, char ch);
//
string is_correct_date(string s, char ch, int count);