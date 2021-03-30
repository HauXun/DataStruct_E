void XuatMenu()
{
	cout << "\n=========================HE THONG CHUC NANG=========================";
	cout << "\n0. Thoat khoi chuong trinh";
	cout << "\n1. Tao danh sach sinh vien";
	cout << "\n2. Xem danh sach sinh vien";
	cout << "\n3. Tim kiem theo ho, ten";
	cout << "\n4. Tim kiem theo nam sinh";
	cout << "\n5. Tim kiem theo ho, ten va nam sinh";
	cout << "\n6. Tim kiem theo ten va dia chi";
	cout << "\n7. Tim kiem theo nam sinh va luong";
	cout << "\n8. Tim kiem nhi phan theo ma nhan vien";
	cout << "\n====================================================================";
}

int ChonMenu(int soMenu)
{
	int stt = -1;
	while (stt < 0 || stt > soMenu)
	{
		system("cls");
		XuatMenu();
		cout << "\nNhap vao tuy chon menu tuong ung: ";
		cin >> stt;
	}
	return stt;
}

void XuLyMenu(int menu, NhanVien a[MAX], int& n)
{
	char filename[MAX];
	char ho[8];
	char ten[8];
	char diachi[15];
	char maNV[8];
	unsigned int namsinh;
	double luong;
	int result;
	switch (menu)
	{
	case 0:
		system("cls");
		cout << "\n0. Thoat khoi chuong trinh\n";
		break;
	case 1:
		system("cls");
		cout << "\n1. Tao danh sach sinh vien\n";
		cout << "\nNhap vao ten tep tin de mo: ";
		cin >> filename;

		result = 0;
		for (int i = 0; filename[i] != NULL; i++)
			if (filename[i] == '.')
			{
				result = 1;
				break;
			}
		if (!result)
			strcat_s(filename, ".txt");

		result = File_Reader(filename, a, n);
		if (result == 0)
		{
			cout << "\nMo tap tin khong thanh cong... !";
		}
		else
		{
			cout << "\nMo tap tin thanh cong !";
			cout << "\nSo luong nhan vien la: " << n;
			cout << "\nDanh sach nhan vien hien hanh:\n\n";
			XuatDSNV(a, n);
		}
		break;
	case 2:
		system("cls");
		cout << "\n2. Xem danh sach sinh vien\n";
		cout << "\nDanh sach nhan vien hien hanh...\n";
		XuatDSNV(a, n);
		break;
	case 3:
		system("cls");
		cout << "\n3. Tim kiem theo ho va ten\n";
		cout << "\nDanh sach nhan vien hien hanh...\n";
		XuatDSNV(a, n);
		cout << "\nNhap ho nhan vien: ";
		cin >> ho;
		cout << "\nNhap ten nhan vien: ";
		cin >> ten;
		TimNhanVien_Ho_Ten(a, n, ho, ten);
		break;
	case 4:
		system("cls");
		cout << "\n4. Tim kiem theo nam sinh\n";
		cout << "\nDanh sach nhan vien hien hanh...\n";
		XuatDSNV(a, n);
		cout << "\nNhap nam sinh nhan vien: ";
		cin >> namsinh;
		TimNhanVien_NamSinh(a, n, namsinh);
		break;
	case 5:
		system("cls");
		cout << "\n5. Tim kiem theo ho, ten va nam sinh\n";
		cout << "\nDanh sach nhan vien hien hanh...\n";
		XuatDSNV(a, n);
		cout << "\nNhap ho nhan vien : ";
		cin >> ho;
		cout << "\nNhap ten nhan vien: ";
		cin >> ten;
		cout << "\nNhap nam sinh nhan vien: ";
		cin >> namsinh;
		TimNhanVien_Ho_Ten_NamSinh(a, n, ho, ten, namsinh);
		break;
	case 6:
		system("cls");
		cout << "\n6. Tim kiem theo ten va dia chi\n";
		cout << "\nDanh sach nhan vien hien hanh...\n";
		XuatDSNV(a, n);
		cout << "\nNhap ten : ";
		cin >> ten;
		cout << "\nNhap dia chi : ";
		cin >> diachi;
		TimNhanVien_Ten_DiaChi(a, n, ten, diachi);
		break;
	case 7:
		system("cls");
		cout << "\n7. Tim kiem theo nam sinh va luong\n";
		cout << "\nDanh sach nhan vien hien hanh...\n";
		XuatDSNV(a, n);
		cout << "\nNhap nam sinh : ";
		cin >> namsinh;
		cout << "\nNhap luong : ";
		cin >> luong;
		TimNhanVien_Luong_NamSinh(a, n, luong, namsinh);
		break;
	case 8:
		system("cls");
		cout << "\n8. Tim kiem nhi phan theo ma nhan vien\n";
		cout << "\nDanh sach nhan vien hien hanh...\n";
		XuatDSNV(a, n);
		cout << "\nNhap ma nhan vien cua nhan vien: ";
		cin >> maNV;
		LinearSearch_MaNV(a, n, maNV);
		break;
	default:
		break;
	}
	_getch();
}