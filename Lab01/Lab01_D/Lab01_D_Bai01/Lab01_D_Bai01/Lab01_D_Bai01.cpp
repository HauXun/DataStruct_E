#include <iostream>
#include <conio.h>
#include <time.h>

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
    int l, r;
    int min = 0, max = 0;
    cout << "\nn: ";
    cin >> n;
    NhapDay(a, n);
    cout << "\nl: ";
    cin >> l;
    cout << "\nr: ";
    cin >> r;
    cout << "\nDay da cho:\n";
    XuatDay(a, n);
    MinMax(a, l, r, min, max);
    cout << "\nMinA[" << l << ",..." << r << "] = " << min;
    cout << "\nMaxA[" << l << ",..." << r << "] = " << max;
    _getch();
}