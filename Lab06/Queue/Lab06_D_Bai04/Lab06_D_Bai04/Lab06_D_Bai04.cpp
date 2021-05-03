#include <iostream>
#include <conio.h>
#include <iomanip>
#include <fstream>

using namespace std;

#include "thuvien.h"

int main()
{
	QUEUE q;
	CreatQueue(q);
	int m;
	char filename[100] = "Test.txt";
	FileReader(filename, q);
	cout << "\nNhap vao so ngay truc : ";
	cin >> m;
	cout << "\nDanh sach ban dau : \n\n";
	Output(q);
	SapTang_TTruc(q);
	cout << "\nDanh sach sau khi sap xep : \n\n";
	Output(q);
	cout << "\nLich truc : \n";
	XuatLichTruc(q, m);
}