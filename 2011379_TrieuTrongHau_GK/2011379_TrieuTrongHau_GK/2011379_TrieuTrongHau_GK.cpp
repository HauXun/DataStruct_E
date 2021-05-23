#include <iostream>
#include <conio.h>
#include <fstream>
#include <iomanip>

using namespace std;

#include "2011379_thuvien.h"
#include "2011379_menu.h"

void ChayChuongTrinh();

int main()
{
	ChayChuongTrinh();
	return 0;
}

void ChayChuongTrinh()
{
	int n = 0, menu, soMenu = 5;
	LIST list;

	do
	{
		menu = ChonMenu(soMenu, n);
		XuLyDuLieu(menu, list);
	} while (menu > 0);

	cout << "\nCam on da su dung chuong trinh";
	_getch();
}