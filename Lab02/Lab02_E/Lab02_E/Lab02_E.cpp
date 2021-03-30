#include <iostream>
#include <conio.h>
#include <iomanip>
#include <string.h>
#include <fstream>

using namespace std;

#include "thuvien.h"
#include "menu.h"

void ChayChuongTrinh();

int main()
{
    ChayChuongTrinh();
    return 1;
}

void ChayChuongTrinh()
{
    NhanVien a[MAX];
    int soMenu = 8, menu, n;
    do
    {
        menu = ChonMenu(soMenu);
        XuLyMenu(menu, a, n);
    } while (menu > 0);
}