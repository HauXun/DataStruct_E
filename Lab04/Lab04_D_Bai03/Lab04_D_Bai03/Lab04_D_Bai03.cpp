#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>
#include <iomanip>

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
    LIST list;
    int menu, soMenu = 6;
    do
    {
        menu = ChonMenu(soMenu);
        XuLyMenu(menu, list);
    } while (menu > 0);
    _getch();
}