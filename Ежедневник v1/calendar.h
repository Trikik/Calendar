#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include "event.h"
#include "termcolor/termcolor.hpp"
#include <ctime>
#include <string>

using namespace std;

class calendar
{
private:
	void output(int year, int month, int week, int is_leap_year);
	int calc_week(int year, int month, int day);
	int calc_leap_year(int year);
	int get_year();
	int get_month();
	int get_day();
	void show_events(int day,int month,int year);
public:
	void calc_core();
	void menu();
};

