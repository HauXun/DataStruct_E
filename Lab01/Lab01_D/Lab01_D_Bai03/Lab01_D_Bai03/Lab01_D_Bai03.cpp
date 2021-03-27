#include <iostream>
#include <conio.h>
#include <iomanip>
#include <time.h>

using namespace std;

#include "thuvien.h"
#include "menu.h"

void ChayChuongTrinh();

int main()
{
	ChayChuongTrinh();
	return 1;
}

void ChayChuongTrinh()
{
	int menu, soMenu = 5;
	do
	{
		menu = ChonMenu(soMenu);
		XuLyMenu(menu, n);
		_getch();
	} while (menu > 0);
	_getch();
}