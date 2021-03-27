#include <iostream>
#include <iomanip>
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
	int n;//Kich thuoc ban co
	int x, y; //toa do dau
	int h[MAX][MAX]; //ma tran luu duong di cua ngua
	int slg = 0;
	system("CLS");
	cout << endl << "Nhap kich thuoc ban co: n = ";
	cin >> n;
	cout << "\nNhap toa do dau ";
	cout << "\nx = ";
	cin >> x;
	cout << "\ny = ";
	cin >> y;
	system("CLS");
	Init(h, n);
	h[x][y] = 1;
	Try(2, x, y, h, n, slg);
	if (!slg)
		cout << "\nKhong co loi giai!";
	else
		cout << "\nSo loi giai : " << slg;
	system("PAUSE");
}