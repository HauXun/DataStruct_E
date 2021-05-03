#include <iostream>
#include <conio.h>
#include <fstream>

using namespace std;

#include "thuvien.h"

int main()
{
	STACK s;
	KhoiTaoStack(s);
	int htp;
	cout << "\nNhap gia tri he thap phan can chuyen () >> ";
	cin >> htp;
	int coSo;
	cout << "\nNhap co so can chuyen (2 - 8 - 16) >> ";
	cin >> coSo;
	DoiCoSo(s, coSo, htp);
	Output(s);
	return 1;
}