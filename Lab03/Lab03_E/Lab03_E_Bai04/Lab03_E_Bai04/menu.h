void XuatMenu()
{
	cout << "\n========================= HE THONG CHUC NANG =========================";
	cout << "\n0. Thoat khoi chuong trinh";
	cout << "\n1. Tao du lieu tu file";
	cout << "\n2. Xem lai du lieu da tao";
	cout << "\n\t\tTHUAT TOAN SAP XEP DANH SACH DU LIEU";
	cout << "\n3. Thuat giai chon truc tiep";
	cout << "\n4. Thuat giai chen truc tiep";
	cout << "\n5. Thuat giai doi cho truc tiep";
	cout << "\n6. Thuat giai Bubble";
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

void XuLyMenu(int menu, DaySo a, int& n)
{
	DaySo b;
	Copy(b, a, n);
	char filename[15];
	int ketQua;
	switch (menu)
	{
	case 0:
		system("cls");
		cout << "\n0. Thoat khoi chuong trinh\n";
		break;
	case 1:
		system("cls");
		cout << "\n1. Tao du lieu tu file\n";
		cout << "\nNhap vao ten tep tin de mo: ";
		cin >> filename;

		ketQua = 0;
		for (int i = 0; filename[i] != NULL; i++)
			if (filename[i] == '.')
			{
				ketQua = 1;
				break;
			}
		if (!ketQua)
			strcat_s(filename, ".txt");
		ketQua = FileStream(filename, a, n);
		if (ketQua == 0)
		{
			cout << "\nMo tap tin khong thanh cong... !";
		}
		else
		{
			cout << "\nMo tap tin thanh cong !";
			cout << "\nDay da tao...";
			Output(a, n);
		}
		break;
	case 2:
		system("cls");
		cout << "\n2. Xem lai du lieu da tao\n";
		cout << "\nDanh sach du lieu hien co : \n";
		Output(a, n);
		break;
	case 3:
		system("cls");
		cout << "\n3. Thuat giai chon truc tiep";
		cout << "\nDanh sach du lieu truoc khi sap xep : \n";
		Output(a, n);
		cout << "\nDanh sach du lieu sau khi sap xep : \n";
		SelectionSort(b, n);
		Output(b, n);
		cout << "\nSo luong cac phep toan so sanh cua thuat giai nay la >> " << compare;
		cout << "\nSo luong cac phep toan hoan vi cua thuat giai nay la >> " << swapper;
		compare = 0;
		swapper = 0;
		break;
	case 4:
		system("cls");
		cout << "\n4. Thuat giai chen truc tiep";
		cout << "\nDanh sach du lieu truoc khi sap xep : \n";
		Output(a, n);
		cout << "\nDanh sach du lieu sau khi sap xep : \n";
		InsertionSort(b, n);
		Output(b, n);
		cout << "\nSo luong cac phep toan so sanh cua thuat giai nay la >> " << compare;
		cout << "\nSo luong cac phep toan hoan vi cua thuat giai nay la >> " << swapper;
		compare = 0;
		swapper = 0;
		break;
	case 5:
		system("cls");
		cout << "\n4. Thuat giai doi cho truc tiep";
		cout << "\nDanh sach du lieu truoc khi sap xep : \n";
		Output(a, n);
		cout << "\nDanh sach du lieu sau khi sap xep : \n";
		InterchangeSort(b, n);
		Output(b, n);
		cout << "\nSo luong cac phep toan so sanh cua thuat giai nay la >> " << compare;
		cout << "\nSo luong cac phep toan hoan vi cua thuat giai nay la >> " << swapper;
		compare = 0;
		swapper = 0;
		break;
	case 6:
		system("cls");
		cout << "\n4. Thuat giai Bubble";
		cout << "\nDanh sach du lieu truoc khi sap xep : \n";
		Output(a, n);
		cout << "\nDanh sach du lieu sau khi sap xep : \n";
		BubbleSort(b, n);
		Output(b, n);
		cout << "\nSo luong cac phep toan so sanh cua thuat giai nay la >> " << compare;
		cout << "\nSo luong cac phep toan hoan vi cua thuat giai nay la >> " << swapper;
		compare = 0;
		swapper = 0;
		break;
	default:
		break;
	}
	_getch();
}