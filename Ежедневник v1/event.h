#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <list>
#include <fstream>
#include <sstream>
using namespace std;

class event
{
private:
	//функции получени€ времени типа|год|мес€ц|день
	long long totalTime = 0;
	int get_total_time(string allTime);
	//превращает string в long long
	long long get_numb_from_string(string path, size_t lineNum);
	//получает N-ую линию из файла
	string get_file_line_n(string path, size_t lineNum);
	//добовл€ет линию в файл
	void add_line_in_file(string path, string line);
	//размер файла
	int file_size(string path);
	// очищает файл
	void clear_file();
	//формулы нахождени€ точного времени
	int get_day(long long totalTime);
	int get_month(long long totalTime);
	int get_year(long long totalTime);
	//получает название событи€
	string get_event_string(string path, size_t place);
public:
	//провер€ет пустоту файла
	bool empty = NULL;
	//провер€ет существующие событи€
	void check_valid_events(int year, int month);
	//превращает int врем€ в string дл€ передачи в файл
	string give_time(int totalTime);
	//путь файла (можно мен€ть)
	string path = "C:\\Users\\mrsel\\Desktop\\Test.txt";
	//создаЄт файл
	void create_file();
	//показывает запланированные событи€
	void show_event(int year, int month, int day);
	//добовл€ет событи€
	void add_event(string eventName);
	//провер€ет наличи€ событи€ в определЄнный день
	bool check_event(int year, int month, int day);
	//провер€ет на пустоту файл
	bool is_empty();
	//создаЄт string дл€ переноса в файл
	string make_event(string totalTime, string eventName, string eventTime);
	//превращает string в int типа час / минута и выводит их на экран
	void get_hour_min(string line);
	//ревращает int типа час / минута в их сумму в виде час|минута дл€ передачи в файл
	int total_hour_min(int hour, int min);
	//создаЄт врем€ типа год|мес€ц|день дл€ переноса в файл
	long long make_time(long long year, long long month, long long day);
};