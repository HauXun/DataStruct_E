#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

#include "thuvien.h"
#include "menu.h"

void ChayChuongTrinh();

int main()
{
    ChayChuongTrinh();
}

void ChayChuongTrinh()
{
    SinhVien a[MAX];
    int soMenu = 9, menu, n;

    do
    {
        system("cls");
        menu = ChonMenu(soMenu);
        XuLyMenu(menu, a, n);
    } while (menu > 0);
}