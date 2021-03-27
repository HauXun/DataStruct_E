#include <iostream>
#include <fstream>

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
    int soMenu = 6, menu, n;
    int a[MAX];
    do
    {
        system("cls");
        menu = ChonMenu(soMenu);
        XuLyMenu(menu, a, n);
    } while (menu > 0);
}