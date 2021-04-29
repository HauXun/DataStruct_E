#include <iostream>
#include <conio.h>
#include <string>
#include <iomanip>
#include <fstream>
#include <math.h>

using namespace std;

#include "thuvien.h"
#include "menu.h"

void ChayChuongTrinh()
{
    LISTLL listLL;
    LISTCC listCC;

    int menu, soMenu = 7;
    do
    {
        menu = ChonMenu(soMenu);
        XuLyMenu(menu, listLL, listCC);
    } while (menu > 0);
    _getch();
}

int main()
{
    ChayChuongTrinh();
    return 1;
}