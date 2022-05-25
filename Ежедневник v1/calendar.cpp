// отключает оповещение об ошибке
#define _CRT_SECURE_NO_WARNINGS
#include "calendar.h"
#include "termcolor/termcolor.hpp"
#include <iostream>
#include <ctime>

using namespace std;
void calendar::output(int year, int month, int week, int is_leap_year) {
	string month_name[12] = { "Январь","Февраль","Март",
	"Апрель","Май","Июнь","Июль","Август","Сентябрь","Октябрь",
	"Ноябрь","Декабрь" };
	string week_name[7] = { "Вс ","Пон ","Вт ","Ср ","Чт ",
	"Пн ","Сб" };
	int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	// В високосном году установите февраль на 29 дней
	if (is_leap_year) {
		days[1] = 29;
	}
	cout << endl;
	// Отображение года и месяца
	cout << "Год: " << year << endl;
	cout << "Месяц: " << month_name[month] << endl;
	// Отображение названия недели
	int i = 0;
	for (i = 0; i < 7; i++) {
		cout << week_name[i] << " ";
	}
	cout << endl;
	// Отображение пустого поля перед 1-м числом каждого месяца
	for (i = 0; i < week % 7; i++) {
		cout << "    ";
	}
	// Отображение даты
	for (i = 1; i <= days[month]; i++) {
		if (i < 10) cout << "  " << i << " ";
		else cout << " " << i << " ";
		if ((i + week) % 7 == 0) {
			cout << endl;
		}
	}
	cout << endl;
}

// Формула Целера вычисляет день недели по году, месяцу и дню
int calendar::calc_week(int year, int month, int day) {
	if (month <= 2) {// Согласно формуле Цайлера, если месяц меньше 2, он должен рассматриваться как 13, 14 
		month += 12;
		year--;
	}
	int century = year / 100;
	year %= 100;
	int days = (year + year / 4 + century / 4 -
		2 * century + 26 * (month + 1) / 10 + day - 1) % 7;
	while (days < 0) {
		days += 7;
	}
	return days;
}

// Рассчитываем, високосный ли год
int calendar::calc_leap_year(int year) {
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
		return 1;
	}
	return 0;
}
// Получение текущего года
int calendar::get_year()
{
	int year;
	time_t now = time(0);
	tm* ltm = localtime(&now);
	year = 1900 + ltm->tm_year;
	return year;
}
//Получение текущего месяца
int calendar::get_month()
{
	int month;
	time_t now = time(0);
	tm* ltm = localtime(&now);
	month = 1 + ltm->tm_mon;
	return month;
}
// Основная функция календаря
void calendar::calc_core() {
	int year = get_year();
	int month = get_month();
	int is_leap_year = calc_leap_year(year);
	int week = calc_week(year, month, 1);
	month--; // соответствует индексу массива в выходной функции
	output(year, month, week, is_leap_year);
}