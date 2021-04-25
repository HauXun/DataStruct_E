#include <iostream>
#include <conio.h>
#include <fstream>

using namespace std;

#include "thuvien.h"
#include "menu.h"

void ChayChuongTrinh()
{
    LIST list;
    int menu, soMenu = 11;
    do
    {
        menu = ChonMenu(soMenu);
        XuLyMenu(menu, list);
    } while (menu > 0);
    _getch();
}

int main()
{
    ChayChuongTrinh();
    return 1;
}