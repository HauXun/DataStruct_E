void XuatMenu()
{
	cout << "\n========================= HE THONG CHUC NANG =========================";
	cout << "\n0. Thoat khoi chuong trinh";
	cout << "\n1. Tao du lieu tu file";
	cout << "\n2. Xem lai du lieu da tao";
	cout << "\n3. Sap xep bang luong nhan vien - SelectionSort";
	cout << "\n4. Sap xep bang luong nhan vien - InsertionSort";
	cout << "\n5. Sap xep bang luong nhan vien - BubbleSort";
	cout << "\n6. Sap xep bang luong nhan vien - MergeSort";
	cout << "\n7. Sap xep bang luong nhan vien - RadixSort";
	cout << "\n======================================================================";
}

int ChonMenu(int soMenu)
{
	int stt;
	for (;;)
	{
		system("cls");
		XuatMenu();
		cout << "\nNhap 1 so trong khoang tu [0,..," << soMenu << "] de chon chuc nang, stt = ";
		cin >> stt;
		if (0 <= stt && stt <= soMenu)
			break;
	}
	return stt;
}

void XuLyMenu(int menu, LISTLL& listLL, LISTCC& listCC)
{
	LISTLL listLL2;
	char filenameLL[100] = "llnv.txt";
	char filenameCC[100] = "chamcong.txt";
	int ketQua, x;
	switch (menu)
	{
	case 0:
		system("cls");
		cout << "\n0. Thoat khoi chuong trinh\n";
		break;
	case 1:
		system("cls");
		cout << "\n1. Tao du lieu tu file\n";
		FileReaderLL(filenameLL, listLL);
		FileReaderCC(filenameCC, listCC, listLL);
		cout << "\n\t\t    BANG LUONG NHAN VIEN";
		XuatBangLuongNV(listLL);
		break;
	case 2:
		system("cls");
		cout << "\n2. Xem lai du lieu da tao\n";
		cout << "\n\t\t    BANG LUONG NHAN VIEN";
		Copy(listLL2, listLL);
		XuatBangLuongNV(listLL2);
		break;
	case 3:
		system("cls");
		cout << "\n3. Sap xep bang luong nhan vien - SelectionSort";
		cout << "\n\tBANG LUONG NHAN VIEN TRUOC KHI SAP XEP";
		Copy(listLL2, listLL);
		XuatBangLuongNV(listLL2);
		cout << "\n\tBANG LUONG NHAN VIEN SAU KHI SAP XEP";
		SelectionSort(listLL2);
		XuatBangLuongNV(listLL2);
		break;
	case 4:
		system("cls");
		cout << "\n4. Sap xep bang luong nhan vien - InsertionSort";
		cout << "\n\tBANG LUONG NHAN VIEN TRUOC KHI SAP XEP";
		XuatBangLuongNV(listLL);
		cout << "\n\tBANG LUONG NHAN VIEN SAU KHI SAP XEP";
		InsertionSort(listLL);
		XuatBangLuongNV(listLL);
		break;
	case 5:
		system("cls");
		cout << "\n5. Sap xep bang luong nhan vien - BubbleSort";
		break;
	case 6:
		system("cls");
		cout << "\n6. Sap xep bang luong nhan vien - MergeSort";
		break;
	case 7:
		system("cls");
		cout << "\n7. Sap xep bang luong nhan vien - RadixSort";
		break;
	default:
		break;
	}
	_getch();
}