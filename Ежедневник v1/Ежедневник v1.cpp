// Ежедневник v1
#include <iostream>
#include "calendar.h"
#include "event.h"
using namespace std;


int main()
{
	setlocale( 0, "russian");
    event tmp;
    ifstream file;
    file.open(tmp.path);
    file.close();
    if (!file)
    {
        tmp.create_file();
    }
	calendar cal;
    cal.menu();
}
