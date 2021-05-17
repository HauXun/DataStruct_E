#include <iostream>
#include <fstream>
#include <conio.h>
#include <math.h>

using namespace std;

#include "Thuvien.h"
#include "Menu.h"

void ChayChuongTrinh()
{
	int soMenu = 13, menu;
	LIST list;
	char filename[10];
	do
	{
		system("cls");
		cout << "\nNhap ten tap tin, filename = ";
		_flushall();
		cin >> filename;
		if (!FileReader(filename, list))
		{
			cout << "\nLoi mo file! Nhap lai...\n";
			_getch();
		}
		else
		{
			cout << "\nDu lieu tap tin " << filename << " da duoc chuyen vao DSLK don vong";
			cout << "\nNhap phim bat ky de tiep tuc!";
			_getch();
			break;
		}
	} while (true);
	do
	{
		system("cls");
		menu = ChonMenu(soMenu);
		XuLyMenu(menu, list);
	} while (menu > 0);
}

int main()
{
	ChayChuongTrinh();
	return 1;
}