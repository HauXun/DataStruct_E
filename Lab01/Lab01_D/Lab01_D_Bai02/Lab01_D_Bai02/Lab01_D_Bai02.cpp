#include <iostream>
#include <conio.h>

using namespace std;

#include "thuvien.h"

void ChayChuongTrinh();

int main()
{
	ChayChuongTrinh();
	return 1;
}
void ChayChuongTrinh()
{
	int a[MAX], n;
	int m;
	cout << "\nn: ";
	cin >> n;
	NhapDay(a, n);
	cout << "\nm: ";
	cin >> m;
	cout << "Day ban dau:\n";
	XuatDay(a, n);
	Transpose(a, n, m);
	cout << "Day ket qua:\n";
	XuatDay(a, n);
	cout << "\n";
	_getch();
}