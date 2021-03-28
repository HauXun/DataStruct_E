void XuatMenu()
{
	cout << "\n================ He thong chuc nang ===============";
	cout << "\n0. Thoat khoi chuong trinh";
	cout << "\n1. Tao danh sach sinh vien ";
	cout << "\n2. Xem danh sach sinh vien";
	cout << "\n3. Tim kiem theo ma sinh vien";
	cout << "\n4. Tim kiem theo ten-Xuat cac sinh vien cung ten";
	cout << "\n5. Tim kiem theo ho-Xuat cac sinh vien cung ho";
	cout << "\n6. Xuat sinh vien co diem trung binh >= dtb cho truoc";
	cout << "\n7. Tim kiem theo lop-Xuat danh sach sinh vien trong lop";
	cout << "\n8. Tim kiem nhi phan theo tich luy (neu truong tich luy co thu tu)";
	cout << "\n===================================================";
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

void XuLyMenu(int menu, SinhVien a[MAX], int& n)
{
	int result;
	char filename[MAX];
	char maSV[8];
	char hoSV[10];
	char ten[10];
	char lop[6];
	double dtb;

	switch (menu)
	{
	case 0:
		system("CLS");
		cout << "\n0. Thoat khoi chuong trinh\n";
		break;
	case 1:
		system("CLS");
		cout << "\n1. Tao Danh sach sinh vien.\n";
		do
		{
			cout << "\nNhap ten tap tin: ";
			cin >> filename;
			result = TapTin_MangCT(filename, a, n);
		} while (!result);
		cout << "\nDanh sach sinh vien vua nhap...";
		XuatDSNV(a, n);
		cout << endl;
		break;
	case 2:
		system("CLS");
		cout << "\n2. Xem Danh sach sinh vien.\n";
		cout << "\nDanh sach sinh vien hien hanh...";
		XuatDSNV(a, n);
		cout << endl;
		break;
	case 3:
		system("CLS");
		cout << "\n3. Tim kiem theo ma sinh vien\n";
		cout << "\nNhap ma sinh vien can tim : ";
		cin >> maSV;
		result = Tim_MaSo_DauTien(maSV, a, n);
		if (result == -1)
		{
			cout << "\nKhong tim thay sinh vien co ma sinh vien : " << maSV;
		}
		else
		{
			XuatTieuDe(a, n);
			XuatNhanVien(a[result]);
			cout << endl;
		}
		break;
	case 4:
		system("CLS");
		cout << "\n4. Tim kiem theo ten - Xuat cac sinh vien cung ten\n";
		cout << "\nNhap ten sinh vien can tim : ";
		cin >> ten;
		Tim_TheoTen(ten, a, n);
		break;
	case 5:
		system("CLS");
		cout << "\n5. Tim kiem theo ho - Xuat cac sinh vien cung ho\n";
		cout << "\nNhap ho sinh vien can tim : ";
		cin >> hoSV;
		Tim_TheoHo(hoSV, a, n);
		break;
	case 6:
		system("CLS");
		cout << "\n6. Xuat sinh vien co diem trung binh >= dtb cho truoc\n";
		cout << "\nNhap diem trung binh sinh vien can tim : ";
		cin >> dtb;
		Tim_TheoDTB(dtb, a, n);
		break;
	case 7:
		system("CLS");
		cout << "\n7. Tim kiem theo lop - Xuat cac sinh vien thuoc lop\n";
		cout << "\nNhap lop sinh vien can tim : ";
		cin >> lop;
		Tim_TheoLop(lop, a, n);
		break;
	case 8:
		system("CLS");
		cout << "\n8. Tim kien nhi phan theo tich luy\n";
		LinearSearch_Theo_DiemTichLuy(a, n);
		break;
	}
	system("pause");
}