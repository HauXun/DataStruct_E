void XuatMenu(unsigned int n)
{
	cout << "\n=========== QUAN LY HOC VIEN ============";
	cout << "\n0. Thoat chuong trinh";
	cout << "\n1. Tao danh sach hoc vien ";
	cout << "\n2. Xem danh sach hoc vien ";
	cout << "\n3. Sua so tin chi cua hoc vien co ma hoc vien DL23452 thanh 35";
	cout << "\n4. Xuat danh sach hoc vien lop CTK36";
	cout << "\n5. Xoa tat ca cac hoc vien co nam sinh 1995 ra khoi danh sach hoc vien";
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

void XuLyDuLieu(int menu, LIST& list)
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

		ketQua = TaoDanhSachHocVien(filename, list);
		if (ketQua == 0)
		{
			cout << "\nMo tap tin khong thanh cong... !";
		}
		else
		{
			cout << "\nMo tap tin thanh cong !";
			cout << "\nDanh sach nhan vien hien hanh:\n\n";
			XuatDSHV(list);
		}
		break;
	case 2:
		system("cls");
		cout << "\n2. Xem danh sach hoc vien ";
		XuatDSHV(list);
		break;
	case 3:
		system("cls");
		cout << "\n3. Sua so tin chi cua hoc vien co ma hoc vien DL23452 thanh 35";
		cout << "\n Danh sach sau khi sua so tin chi cua hoc vien co ma hoc vien la DL23452";
		SuaTinChi_DL23452(list);
		XuatDSHV(list);
		break;
	case 4:
		system("cls");
		cout << "\n4. Xuat danh sach hoc vien lop CTK36";
		cout << "\n Danh sach hoc vien lop CTK36";
		XuatLopCTK36(list);
		break;
	case 5:
		system("cls");
		cout << "\n5. Xoa tat ca cac hoc vien co nam sinh 1995 ra khoi danh sach hoc vien";
		cout << "\n Danh sach hoc vien sau khi xoa cac hoc vien sinh nam 1995";
		XoaNamSinh(list, 1995);
		XuatDSHV(list);
		break;
	}
	_getch();
}