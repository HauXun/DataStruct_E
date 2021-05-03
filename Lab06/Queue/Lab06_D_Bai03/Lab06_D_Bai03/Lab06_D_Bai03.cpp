#include <iostream>
#include <fstream>
#include <conio.h>

using namespace std;

#include "Thuvien.h"

void ChayChuongTrinh()
{
	char filename[MAX];
	QUEUE q;
	CreatQueue(q);
	cout << "\nNhap ten tap tin can mo : ";
	cin >> filename;
	FileReader(filename, q);
	cout << "\nDanh sach ban dau : \n";
	Output(q);
	Radix(q);
	cout << "\nDanh sach sau khi sap xep : \n";
	Output(q);
}

int main()
{
	ChayChuongTrinh();
	_getch();
	return 1;
}