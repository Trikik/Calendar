#include "event.h"

void event::clear_file()
{
	string FileName = this->path;
	remove(FileName.c_str());

	ofstream File;
	File.open(this->path);
	File.close();
}

void event::create_file()
{
	ofstream oFile(this->path);
}

void event::show_event(int year, int month, int day)
{
	for (int i = 0; i < file_size(this->path); i++) {
		if ((get_numb_from_string(this->path, i)) == (make_time(year, month, day))) {
			cout << get_event_string(this->path, i) << "\tвремя события "; get_hour_min(get_file_line_n(this->path, i)); cout << endl;
		}
	}
}

void event::add_event(string eventName)
{
	event tmp;
	int j = tmp.file_size(this->path);
	vector<string> allEvents;
	for (int i = 0; i < j; i++)
	{
		allEvents.push_back(tmp.get_file_line_n(this->path, i));
	}
	//проверяем размеры
	allEvents.push_back(eventName);
	for (int i = 0; i < allEvents.size() - 1; i++)
		for (int j = 0; j < allEvents.size() - i - 1; j++)
			if (allEvents[j] > allEvents[j + 1])
				swap(allEvents[j], allEvents[j + 1]);

	//чистим файл
	tmp.clear_file();
	//возвращаем массив в файл переписывая его
	for (int i = 0; i < allEvents.size(); i++) {
		tmp.add_line_in_file(this->path, allEvents[i]);
	}
}



string event::give_time(int totalTime)
{
	stringstream ss;
	ss << totalTime;
	return ss.str();
}

int event::get_total_time(string allTime)
{

	return stoi(allTime);
}

string event::make_event(string totalTime, string eventName, string eventTime)
{
	string middle = "|";
	return totalTime + middle + eventTime + middle + eventName;
}

void event::get_hour_min(string line)
{
	int h = line.size();
	string tmp;
	int time;
	time = get_total_time(line.substr(9, 12));
	cout << time / 100 << ':' << time % 100;
}

int event::total_hour_min(int hour, int min)
{
	return (hour * 100 + min);
}


string event::get_file_line_n(string path, size_t lineNum)
{
	ifstream f(this->path);
	string line;
	bool notreached = true;
	while ((getline(f, line)) && (notreached = (lineNum-- > 0)));
	if (!notreached)
		return line;
}
long long event::get_numb_from_string(string path, size_t lineNum)
{
	string tmp = get_file_line_n(this->path, lineNum);
	char tmpStr[8] = {};
	int pos = tmp.find("|");
	for (int i = 0; i < pos; i++) {
		tmpStr[i] = tmp[i];
	}
	return get_total_time(tmpStr);
}

long long event::make_time(long long year, long long month, long long day)
{
	return this->totalTime = year * 10000 + month * 100 + day;
}

void event::check_valid_events(int year, int month)
{
	if (empty){
		return;
	}
	//clear_empty_lines();
	//длина файла j
	int j = file_size(this->path);
	vector<string> allEvents;
	string tmp;
	long long tmpInt;
	//j == длина файла
	for (int i = 0; i < j; i++)
	{
		//добавляем линию файла в tmp
		tmp = get_file_line_n(this->path,i);
		//получаем время этой линии
		tmpInt = get_numb_from_string(this->path,i);
		//проверяем на возможность события (совпадение или будующие время)
		int yearS;
		yearS = get_year(tmpInt);
		int monthS;
		monthS = get_month(tmpInt);
		if (year <= yearS) {
			if (month <= monthS) {
				allEvents.push_back(tmp);
			}
		}
	}
	//очищаем файл
	clear_file();
	//запихиваем элементы в файл переписывая его
	for (int i = 0; i < allEvents.size(); i++) {
		add_line_in_file(this->path, allEvents[i]);
	}
	if (empty);
}

void event::add_line_in_file(string path, string line)
{
	ofstream file;     //создаем поток 
	file.open(path, ios::app);  // открываем файл для записи 
	file << line << endl; // сама запись
	file.close();
}

int event::file_size(string path)
{
	list<string> lst;
	string str;
	ifstream file(path);
	while (!file.eof()) {
		file >> str;
		lst.push_back(str);
	}
	return lst.size() - 1;
}



int event::get_day(long long time)
{
	return (time % 100);
}

int event::get_month(long long time)
{
	return ((time % 10000 - time % 100) / 100);
}

int event::get_year(long long time)
{
	return (time / 10000);
}

string event::get_event_string(string path, size_t place)
{
	int h;
	string tmp;
	string origin = get_file_line_n(path, place);
	h = origin.size();
	return origin.substr(14, h);
}
bool event::check_event(int year, int month, int day)
{
	if (is_empty()) return false;
	ifstream file(this->path);
	event ev;
	int j = ev.file_size(this->path);
	for (int i = 0; i < j; i++)
	{
		this->totalTime = ev.get_numb_from_string(this->path, i);
		int a = get_day(this->totalTime);
		if (day == a) {
			int b = get_month(this->totalTime);
			if (month == b) {
				int c = get_year(this->totalTime);
				if (year == c) {
					return true;
				}
			}
		}
	}
	return false;
}

bool event::is_empty()
{
	ifstream file(path);
	long fileSize;
	file.seekg(0, ios::end);
	fileSize = file.tellg();
	if (fileSize == 0) return true;
	else return false;
}