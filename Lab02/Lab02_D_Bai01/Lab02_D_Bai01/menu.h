void XuatMenu()
{
	cout << "\n================ He thong chuc nang ===============";
	cout << "\n0. Thoat khoi chuong trinh";
	cout << "\n1. Tao du lieu";
	cout << "\n2. Xem du lieu";
	cout << "\n3. Tim kiem tuyen tinh - Tra ve chi so dau tien";
	cout << "\n4. Tim kiem tuyen tinh - Tra ve chi so i dau tien, neu co(Co linh canh)";
	cout << "\n5. Tim kiem tuyen tinh - Tra ve chi so cuoi cung, neu co";
	cout << "\n6. Tra ve tat ca chi so i neu co.";
}

int ChonMenu(int soMenu)
{
	int stt = -1;
	do
	{
		system("cls");
		XuatMenu();
		cout << "\nNhap tuy chon menu tuong ung: ";
		cin >> stt;
	} while (stt < 0 || stt > soMenu);
	return stt;
}

void XuLyMenu(int menu, int a[MAX], int& n)
{
	int result;
	int x;
	char filename[MAX];
	switch (menu)
	{
	case 0:
		cout << "\n0. Thoat khoi chuong trinh\n";
		break;
	case 1:
		cout << "\n1. Tao du lieu";
		do
		{
			cout << "\nNhap ten tap tin, filename = ";
			cin >> filename;
			result = TapTin_Mang1Chieu(filename, a, n);
		} while (!result);
		cout << "\nMang vua tao...\n";
		XuatMang(a, n);
		cout << endl;
		break;
	case 2:
		cout << "\n2. Xem du lieu";
		cout << "\nMang vua tao...\n";
		XuatMang(a, n);
		cout << endl;
		break;
	case 3:
		cout << "\n3. Tim kiem tuyen tinh - Tra ve chi so dau tien";
		cout << "\nMang du lieu ban dau...\n";
		XuatMang(a, n);
		cout << "\nNhap x: ";
		cin >> x;
		result = LinearSearch_First(a, n, x);
		if (result == -1)
			cout << endl << x << " Khong co trong mang";
		else
			cout << endl << x << " Xuat hien trong mang tai vi tri dau tien la : " << result;
		cout << endl;
		break;
	case 4:
		cout << "\n4. Tim kiem tuyen tinh - Tra ve chi so i dau tien, neu co(Co linh canh)";
		cout << "\nMang du lieu ban dau...\n";
		cout << "\nNhap x: ";
		cin >> x;
		result = LinearSearch_First_Guards(a, n, x);
		if (result == -1)
			cout << endl << x << " Khong co trong mang";
		else
			cout << endl << x << " Xuat hien trong mang tai vi tri dau tien la : " << result;
		cout << endl;
		break;
	case 5:
		cout << "\n5. Tim kiem tuyen tinh - Tra ve chi so cuoi cung, neu co";
		cout << "\nMang du lieu ban dau...\n";
		XuatMang(a, n);
		cout << "\nNhap x: ";
		cin >> x;
		result = LinearSearch_Last(a, n, x);
		if (result == -1)
			cout << endl << x << " Khong co trong mang";
		else
			cout << endl << x << " Xuat hien trong mang tai vi tri dau tien la : " << result;
		cout << endl;
		break;
	case 6:
		cout << "\n6. Tra ve tat ca chi so i neu co.";
		cout << "\nMang du lieu ban dau...\n";
		cout << "\nNhap x: ";
		cin >> x;
		LinearSearch_Index(a, n, x);
		cout << endl;
		break;
	}
	system("pause");
}