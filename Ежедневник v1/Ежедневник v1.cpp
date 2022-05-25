// Ежедневник v1
#include "calendar.h"
#include <iostream>

using namespace std;
int main()
{
	setlocale(LC_ALL, "russian");
	calendar h;
	h.calc_core();
}
