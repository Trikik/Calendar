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
	//������� ��������� ������� ����|���|�����|����
	long long totalTime = 0;
	int get_total_time(string allTime);
	//���������� string � long long
	long long get_numb_from_string(string path, size_t lineNum);
	//�������� N-�� ����� �� �����
	string get_file_line_n(string path, size_t lineNum);
	//��������� ����� � ����
	void add_line_in_file(string path, string line);
	//������ �����
	int file_size(string path);
	// ������� ����
	void clear_file();
	//������� ���������� ������� �������
	int get_day(long long totalTime);
	int get_month(long long totalTime);
	int get_year(long long totalTime);
	//�������� �������� �������
	string get_event_string(string path, size_t place);
public:
	//��������� ������� �����
	bool empty = NULL;
	//��������� ������������ �������
	void check_valid_events(int year, int month);
	//���������� int ����� � string ��� �������� � ����
	string give_time(int totalTime);
	//���� ����� (����� ������)
	string path = "C:\\Users\\mrsel\\Desktop\\Test.txt";
	//������ ����
	void create_file();
	//���������� ��������������� �������
	void show_event(int year, int month, int day);
	//��������� �������
	void add_event(string eventName);
	//��������� ������� ������� � ����������� ����
	bool check_event(int year, int month, int day);
	//��������� �� ������� ����
	bool is_empty();
	//������ string ��� �������� � ����
	string make_event(string totalTime, string eventName, string eventTime);
	//���������� string � int ���� ��� / ������ � ������� �� �� �����
	void get_hour_min(string line);
	//��������� int ���� ��� / ������ � �� ����� � ���� ���|������ ��� �������� � ����
	int total_hour_min(int hour, int min);
	//������ ����� ���� ���|�����|���� ��� �������� � ����
	long long make_time(long long year, long long month, long long day);
};