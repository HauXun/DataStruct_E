#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <conio.h>

using namespace std;

#include "thuvien.h"
#include "menu.h"

void ChayChuongTrinh()
{
	DaySo a;
	int menu, soMenu = 6, n = 0;
	do
	{
		menu = ChonMenu(soMenu);
		XuLyMenu(menu, a, n);
	} while (menu > 0);
}

int main()
{
	ChayChuongTrinh();
	return 1;
}