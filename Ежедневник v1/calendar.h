#pragma once
class calendar
{
private:
	void output(int year, int month, int week, int is_leap_year);
	int calc_week(int year, int month, int day);
	int calc_leap_year(int year);
	int get_year();
	int get_month();
public:
	void calc_core();
};

