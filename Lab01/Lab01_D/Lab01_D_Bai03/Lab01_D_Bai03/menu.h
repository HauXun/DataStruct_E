void XuatMenu()
{
	cout << "\n========He thong menu ======";
	cout << "\n0. Thoat khoi chuong trinh";
	cout << "\n1. Nhap du lieu n";
	cout << "\n2. Xem du lieu n";
	cout << "\n3. Liet ke day nhi phan";
	cout << "\n4. Liet ke to hop ";
	cout << "\n5. Liet ke hoan vi";
}

int ChonMenu(int soMenu)
{
	int stt = -1;
	while (stt < 0 || stt > soMenu)
	{
		system("cls");
		XuatMenu();
		cout << "\nNhap tuy chon menu tuong ung: ";
		cin >> stt;
	}
	return stt;
}

void XuLyMenu(int menu, int& n)
{
	switch (menu)
	{
	case 0:
		system("CLS");
		cout << "\n0. Thoat khoi chuong trinh\n";
		break;
	case 1:
		system("CLS");
		cout << "\n1. Nhap du lieu";
		cout << "\nn: ";
		cin >> n;
		break;
	case 2:
		system("CLS");
		cout << "\n2. Xem du lieu";
		cout << "\nn= " << n;
		break;
	case 3:
		system("CLS");
		cout << "\n3. Liet ke day nhi phan";
		cout << "\n";
		dem = 0;
		LietKe_DayNP(1);
		break;
	case 4:
		system("CLS");
		cout << "\n4. Liet ke to hop";
		a[0] = 0;
		dem = 0;
		cout << "\nNhap k =";
		cin >> k;
		LietKe_TH(1);
		break;
	case 5:
		system("CLS");
		cout << "\n5. Liet ke hoan vi";
		dem = 0;
		KhoiTao_danhdau();
		LietKe_HV(1);
		break;
	}
}