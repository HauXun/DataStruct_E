#include <iostream>
#include <conio.h>
#include <fstream>

using namespace std;

#include "thuvien.h"
#include "menu.h"

void ChayChuongTrinh()
{
    int soMenu = 13, n = 0, menu;
    DaySo a;
    do
    {
        menu = ChonMenu(soMenu);
        XuLyMenu(menu, a, n);
    } while (menu > 0);
}

int main()
{
    ChayChuongTrinh();
    return 0;
}