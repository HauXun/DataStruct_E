#include <conio.h>
#include <iostream>
#include <fstream>

using namespace std;

#include "Thuvien.h"

void ChayChuongTrinh()
{
	char a[MAX];
	char filename[MAX] = "Text.txt";
	FileReader(filename, a);
	XuLyThaoTac(a);
}

int main()
{
	ChayChuongTrinh();
	_getch();
	return 1;
}