
#include "calendar.h"
int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
void calendar::output(int year, int month, int week, int is_leap_year) {
	string month_name[12] = { "������","�������","����",
	"������","���","����","����","������","��������","�������",
	"������","�������" };
	string week_name[7] = { "��","���","��","��","��",
	"�� ","��" };
	event calend;
	// � ���������� ���� ���������� ������� �� 29 ����
	if (is_leap_year) {
		days[1] = 29;
	}
	cout << endl;
	// ����������� ���� � ������
	cout << "���: " << year << endl;
	cout << "�����: " << month_name[month] << endl;
	// ����������� �������� ������
	cout << '\t';
	int i = 0;
	for (i = 0; i < 7; i++) {
		cout << week_name[i] << '\t' << '\t';
	}
	cout << endl;
	// ����������� ������� ���� ����� 1-� ������ ������� ������
	for (i = 0; i < week % 7; i++) {
		cout << '\t';
	}
	// ����������� ����
	for (i = 1; i <= days[month]; i++) {
		if (i < 10) {
			if (calend.check_event(year, month, i)) {
				cout << '\t'; cout << termcolor::red << i;
				cout << termcolor::reset << '\t';
			}
			else	cout << '\t' << i << '\t';
		}
		else {
			if (calend.check_event(year, month + 1, i)) {
				cout << '\t'; cout << termcolor::red << i;
				cout << termcolor::reset << '\t';
		    }
			else	cout << '\t' << i << '\t';
		}
		if ((i + week) % 7 == 0) {
			cout << endl;
		}
	}
	cout << endl;
}

// ������� ������ ��������� ���� ������ �� ����, ������ � ���
int calendar::calc_week(int year, int month, int day) {
	if (month <= 2) {// �������� ������� �������, ���� ����� ������ 2, �� ������ ��������������� ��� 13, 14 
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

// ������������, ���������� �� ���
int calendar::calc_leap_year(int year) {
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
		return 1;
	}
	return 0;
}
// ��������� �������� ����
int calendar::get_year()
{
	int year;
	time_t now = time(0);
	tm* ltm = localtime(&now);
	year = 1900 + ltm->tm_year;
	return year;
}
//��������� �������� ������
int calendar::get_month()
{
	int month;
	time_t now = time(0);
	tm* ltm = localtime(&now);
	month = 1 + ltm->tm_mon;
	return month;
}
int calendar::get_day()
{
	int day;
	time_t now = time(0);
	tm* ltm = localtime(&now);
	day = ltm->tm_mday;
	return day;
}
void calendar::show_events(int day, int month, int year)
{
	event top;
	if (top.check_event(year, month, day)) {
		top.show_event(year, month, day);
	}
	else cout << "��� ������" << endl;
}
// �������� ������� ���������
void calendar::calc_core() {
	event ent;
	int year = get_year();
	int month = get_month();
	int is_leap_year = calc_leap_year(year);
	int week = calc_week(year, month, 1);
	month--; // ������������� ������� ������� � �������� �������
	ent.check_valid_events(year,month+1);
	output(year, month, week, is_leap_year);
}

void calendar::menu()
{
	event ev;
	ifstream file;
	file.open(ev.path);
	file.close();
	if (!file)
	{
		ev.create_file();
	}
	bool work = true;
	int choise;
	do {
		ev.empty = ev.is_empty();
		system("CLS");
		calc_core();
		cout << endl;
		cout << "�������� ��������:" << endl
			<< "1 - �������� � ���������� ����" << endl
			<< "2 - ���������� ���� �� ����������� ����" << endl
			<< "3 - ���������� ���� �� ��������� ����" << endl
			<< "0 - ����� �� ���������" << endl;
		cin >> choise;
		switch (choise) {
		case 1: {
			int year, month, day, hour, min;
			string eventName;
			string tmp;
			cout << endl << "������� �������" << endl;
			cin >> eventName;
			cout << endl;
			cout << "������� ���: "; cin >> year; cout << endl;
			int tmpYear = get_year();
			if (year < tmpYear) {
				cout << "��� �� ������������� ������� ������� ���������� �������� ���� ��� ��� ���������";
				system("pause");
				break;
			};

			int tmpMonth = get_month();
			cout << "������� �����: "; cin >> month; cout << endl;
			if(((month < tmpMonth) && (tmpYear == year)) && ((month < 0) || (month > 12))){
				cout << "����� �� ������������� ������� ������� ���������� �������� ���� ����� ��� ���������";
				system("pause");
				break;
			}
			int tmpDay = get_day();
			cout << "������� ����: "; cin >> day; cout << endl;
			if(((day < tmpDay)&&(month == tmpMonth)) || ((day < 0) && (day > 31) || (days[month - 1] <= day )))
			{
				cout << "���� �� ������������� ������� ������� ���������� �������� ����������� ���� ��� ���������";
				system("pause");
				break;
			}
			cout << "������� ���: "; cin >> hour; cout << endl;
			if (hour < 0 || hour > 24)
			{
				cout << "��� �� ������������� 24� �������� ����� ������� ���������!";
				system("pause");
				break;
			}
			cout << "������� ������: "; cin >> min; cout << endl;
			if (min < 0 || min > 60)
			{
				cout << "������ �� ������� ���������!";
				system("pause");
				break;
			}
			tmp = ev.make_event(ev.give_time(ev.make_time(year,month,day)),eventName,ev.give_time(ev.total_hour_min(hour,min)));
			ev.add_event(tmp);
			break;
		}
		case 2: {
			int tmpYear = get_year();
			int tmpMonth = get_month();
			int tmpDay = get_day();
			ev.show_event(tmpYear,tmpMonth,tmpDay);
			cout << endl;
			system("pause");
			break;
		}
		case 3: {
			int year;
			int month;
			int day;
			cout << "������� ���: "; cin >> year; cout << endl;
			int tmpYear = get_year();
			if (year < tmpYear) {
				cout << "��� �� ������������� ������� ������� ���������� �������� ���� ��� ��� ���������";
				system("pause");
				break;
			};
			cout << "������� �����: "; cin >> month; cout << endl;
			if ((month < 0) || (month > 12)) {
				cout << "����� �� ������������� ������� ������� ���������� �������� ���� ����� ��� ���������";
				system("pause");
				break;
			}
			cout << "������� ����: "; cin >> day; cout << endl;
			if (((day < 0) && (day > 31) || (days[month - 1] <= day)))
			{
				cout << "���� �� ������������� ������� ������� ���������� �������� ����������� ���� ��� ���������";
				system("pause");
				break;
			}
			if (ev.check_event(year, month, day)) {
				ev.show_event(year, month, day);
				cout << endl;
				system("pause");
			}
			else cout << "��� �������" << endl;
			system("pause");
			break;
		}
		case 0: {
			work = false;
			break;
		}
		default: {
			cout << "������ �������� ���"; 
			break;
		}
		}
	} while (work);
	system("CLS");
	cout << "����������";
}
