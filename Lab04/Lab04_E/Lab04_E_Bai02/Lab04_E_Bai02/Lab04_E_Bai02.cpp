#include <iostream>
#include <conio.h>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

#include "thuvien.h"

void ChayChuongTrinh()
{
    LISTLL listLL;
    LISTCC listCC;

    char filenameLL[100] = "llnv.txt";
    char filenameCC[100] = "chamcong.txt";

    FileReaderLL(filenameLL, listLL);
    FileReaderCC(filenameCC, listCC, listLL);

    SapXep(listLL);
    XuatBangLuongNV(listLL, listCC);
    _getch();
}

int main()
{
    ChayChuongTrinh();
    return 1;
}