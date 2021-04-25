#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>
#include <iomanip>

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
    LL listLL;
    BD listBD;

    char filenameLL[100] = "llsv.txt";
    char filenameBD[100] = "diemqt.txt";

    FileReaderLL(filenameLL, listLL);
    FileReaderBD(filenameBD, listBD);
    XuatBangDiem(listLL, listBD);
    _getch();
}