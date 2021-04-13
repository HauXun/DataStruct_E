void XuatMenu(unsigned int n)
{
	cout << "\n=========== QUAN LY HOC VIEN ============";
	cout << "\n0. Thoat chuong trinh";
	cout << "\n1. Tao danh sach hoc vien ";
	cout << "\n2. Xem danh sach hoc vien ";
	cout << "\n3. Tim kiem theo lop va so tin chi ";
	cout << "\n4. Tim kiem theo ten";
	cout << "\n5. Tim kiem theo nam sinh va diem trung binh";
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
		cout << "\n3. Tim kiem theo lop va so tin chi ";
		XuatHocVien_Lop_STC(a, n);
		break;
	case 4:
		system("cls");
		cout << "\n4. Tim kiem theo ten";
		XuatHocVien_TenHoa(a, n);
		break;
	case 5:
		system("cls");
		cout << "\n5. Tim kiem theo nam sinh va diem trung binh";
		XuatHocVienTheoNamSinh_DTB(a, n);
		break;
	}
	_getch();
}