void XuatMenu()
{
	cout << "\n========================= HE THONG CHUC NANG =========================";
	cout << "\n0. Thoat khoi chuong trinh";
	cout << "\n1. Tao du lieu tu file";
	cout << "\n2. Xem lai du lieu da tao";
	cout << "\n3. Tach danh sach nhan vien theo luong";
	cout << "\n4. Tach danh sach nhan vien theo luan phien";
	cout << "\n5. Dao nguoc danh sach nhan vien";
	cout << "\n6. Sap xep danh sach nhan vien - Tang dan theo ten:";
	cout << "\n   Neu cung ten, xep tang dan theo ho";
	cout << "\n   Neu cung ten, ho, xep tang dan theo hoLot";
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

void XuLyMenu(int menu, LIST& list)
{
	char filename[15];
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
		ketQua = FileReader(filename, list);
		if (ketQua == 0)
		{
			cout << "\nMo tap tin khong thanh cong... !";
		}
		else
		{
			cout << "\nMo tap tin thanh cong !";
			cout << "\nDay da tao...";
			XuatDSNV(list);
		}
		break;
	case 2:
		system("cls");
		cout << "\n2. Xem lai du lieu da tao\n";
		XuatDSNV(list);
		break;
	case 3:
		system("cls");
		cout << "\n3. Tach danh sach nhan vien theo luong";
		cout << "\nNhap vao muc luong de sap xep >> ";
		cin >> x;
		TachDSNV_LuongX(list, x);
		break;
	case 4:
		system("cls");
		cout << "\n4. Tach danh sach nhan vien theo luan phien";
		TachDSNV_LuanPhien(list);
		break;
	case 5:
		system("cls");
		cout << "\n5. Dao nguoc danh sach nhan vien";
		cout << "\nDanh sach nhan vien hien tai...\n";
		XuatDSNV(list);
		cout << "\nDanh sach dao nguoc...\n";
		DaoNguocDanhSach(list);
		break;
	case 6:
		system("cls");
		cout << "\n6. Sap xep danh sach nhan vien - Tang dan theo ten:";
		cout << "\n   Neu cung ten, xep tang dan theo ho";
		cout << "\n   Neu cung ten, ho, xep tang dan theo hoLot";
		SapTang(list);
		XuatDSNV(list);
		break;
	default:
		break;
	}
	_getch();
}