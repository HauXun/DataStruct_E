void XuatMenu()
{
	cout << "\n======================== HE THONG CHUC NANG ========================";
	cout << "\n0. Thoat khoi chuong trinh";
	cout << "\n1. Chuyen du lieu tu tap tin danh sach nhan vien vao BST";
	cout << "\n2. Xem bang luong nhan vien theo thu tu LNR";
	cout << "\n3. Tinh so nut cua cay";
	cout << "\n4. Xuat thong tin nhan vien co ma nhan vien la LD19022";
	cout << "\n5. Sua thong tin nam sinh cua nhan vien co ma nhan vien LD18041 thanh 1990";
	cout << "\n====================================================================";
}

int ChonMenu(int soMenu)
{
	int stt;
	while (true)
	{
		system("cls");
		XuatMenu();
		cout << "\nNhap mot so trong khoang tu [0,..," << soMenu << "] de chon chuc nang, stt = ";
		cin >> stt;
		if (0 <= stt && stt <= soMenu)
			break;
	}
	return stt;
}

void XuLyMenu(int menu, TREE& root)
{
	char filename[14] = "bangluong.txt";
	char maNV[10] = "LD19022";
	int kq;
	system("CLS");
	switch (menu)
	{
	case 0:
		cout << "\n0. Thoat khoi chuong trinh\n";
		break;
	case 1:
		cout << "\n1. Chuyen du lieu tu tap tin danh sach nhan vien vao BST\n";
		kq = File_BST(root, filename);
		if (kq == 1)
			cout << "\nChuyen du lieu thanh cong";
		else
			cout << "\nChuyen du lieu khong thanh cong";
		break;
	case 2:
		cout << "\n2. Xem bang luong nhan vien theo thu tu LNR";
		cout << "\n\nDanh sach nhan vien theo thu tu LNR:\n";
		XuatTieuDe();
		XuatLNR(root);
		XuatDongKeNgangDoi();
		break;
	case 3:
		cout << "\n3. Tinh so nut cua cay";
		cout << "\nCay BST xuat theo thu tu giua (LNR) :\n\n";
		XuatTieuDe();
		XuatLNR(root);
		XuatDongKeNgangDoi();
		cout << "\n\nSo nut trong cay : So nut = " << DemSoNut(root);
		cout << endl;
		break;
	case 4:
		cout << "\n4. Xuat thong tin nhan vien co ma nhan vien la LD19022";
		XuatTieuDe();
		XuatNhanVien(root);
		XuatDongKeNgangDoi();
		break;
	case 5:
		cout << "\n5. Sua thong tin nam sinh cua nhan vien co ma nhan vien LD18041 thanh 1990";
		cout << "\nDanh sach nhan vien theo thu tu LNR:\n";
		XuatTieuDe();
		XuatLNR(root);
		XuatDongKeNgangDoi();
		cout << "\n Danh sach hoc vien sau khi dieu chinh tin chi?\n\n";
		SuaNamSinh_DL23452(root);
		XuatTieuDe();
		XuatLNR(root);
		XuatDongKeNgangDoi();
		break;
	}
	_getch();
}