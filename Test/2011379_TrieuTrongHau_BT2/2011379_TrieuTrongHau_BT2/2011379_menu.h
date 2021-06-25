void XuatMenu(unsigned int n)
{
	cout << "\n=========== QUAN LY HOC VIEN ============";
	cout << "\n0. Thoat chuong trinh";
	cout << "\n1. Tao danh sach hoc vien ";
	cout << "\n2. Xem danh sach hoc vien ";
	cout << "\n3. Sap danh sach hoc vien tang dan theo ma hoc vien bang thuat giai chon truc tiep";
	cout << "\n4. Sap danh sach hoc vien tang dan theo ma hoc vien bang thuat giai QuickSort";
	cout << "\n5. Sap danh sach hoc vien theo yeu cau:"
		<< "\n\t- Tang dan theo ten hoc vien"
		<< "\n\t- Trung ten thi tang dan theo ho"
		<< "\n\t- Trung ca 2 thi tang dan theo ho lot";
	cout << "\n============================================\n";
}

int ChonMenu(int soMenu, unsigned int n)
{
	int stt = -1;
	while (stt < 0 || stt > soMenu)
	{
		system("cls");
		XuatMenu(n);
		cout << "\nChon chuc nang tuong ung : ";
		cin >> stt;
	}

	return stt;
}

void XuLyDuLieu(int menu, HocVien a[MAX], int& n)
{
	int ketQua;
	char filename[MAX];

	switch (menu)
	{
	case 0:
		cout << "\n0. Thoat chuong trinh";
		break;
	case 1:
		system("cls");
		cout << "\n1. Tao danh sach hoc vien ";
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

		ketQua = TaoDanhSachHocVien(a, n, filename);
		if (ketQua == 0)
		{
			cout << "\nMo tap tin khong thanh cong... !";
		}
		else
		{
			cout << "\nMo tap tin thanh cong !";
			cout << "\nSo luong nhan vien la: " << n;
			cout << "\nDanh sach nhan vien hien hanh:\n\n";
			XuatDSHV(a, n);
		}
		break;
	case 2:
		system("cls");
		cout << "\n2. Xem danh sach hoc vien ";
		XuatDSHV(a, n);
		break;
	case 3:
		system("cls");
		cout << "\n3. Sap danh sach hoc vien tang dan theo ma hoc vien bang thuat giai chon truc tiep";
		SelectionSort_MaHV(a, n);
		XuatDSHV(a, n);
		break;
	case 4:
		system("cls");
		cout << "\n4. Sap danh sach hoc vien tang dan theo ma hoc vien bang thuat giai QuickSort";
		QuickSort_MaHV(a, 0, n - 1);
		XuatDSHV(a, n);
		break;
	case 5:
		system("cls");
		cout << "\n5. Sap danh sach hoc vien theo yeu cau:"
			<< "\n\t- Tang dan theo ten hoc vien"
			<< "\n\t- Trung ten thi tang dan theo ho"
			<< "\n\t- Trung ca 2 thi tang dan theo ho lot";
		BubbleSort_Options(a, n);
		XuatDSHV(a, n);
		break;
	}
	_getch();
}