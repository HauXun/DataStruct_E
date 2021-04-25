#include <iostream>
#include <conio.h>
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
    int soMenu = 18, menu, n;
    LIST list;
    do
    {
        menu = ChonMenu(soMenu);
        XuLyMenu(menu, list);
    } while (menu > 0);
}