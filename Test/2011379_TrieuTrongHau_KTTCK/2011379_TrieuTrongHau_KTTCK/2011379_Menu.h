void XuatMenu()
{
	cout << "\n======================== HE THONG CHUC NANG ========================";
	cout << "\n0. Thoat khoi chuong trinh";
	cout << "\n1. Chuyen du lieu tu tap tin danh sach nhan vien vao BST";
	cout << "\n2. Xem danh sach nhan vien theo cac thu tu NLR, LNR, LRN";
	cout << "\n3. Sua so tin chi cua hoc vien co ma hoc vien DL23452 thanh 35";
	cout << "\n4. Xoa hoc vien co ma hoc vien DL42032 ra khoi danh sach hoc vien";
	cout << "\n5. Xuat danh sach hoc vien lop CTK36";
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
	char filename[12] = "hocvien.txt";
	char maHV[10] = "DL42032";
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
		cout << "\n2. Xem danh sach nhan vien theo cac thu tu NLR, LNR, LRN\n";
		cout << "\nDanh sach nhan vien theo thu tu NLR:\n";
		XuatTieuDe();
		XuatNLR(root);
		XuatDongKeNgangDoi();
		cout << "\n\nDanh sach nhan vien theo thu tu LNR:\n";
		XuatTieuDe();
		XuatLNR(root);
		XuatDongKeNgangDoi();
		cout << "\n\nDanh sach nhan vien theo thu tu LRN:\n";
		XuatTieuDe();
		XuatLRN(root);
		XuatDongKeNgangDoi();
		break;
	case 3:
		cout << "\n3. Sua so tin chi cua hoc vien co ma hoc vien DL23452 thanh 35";
		cout << "\nDanh sach nhan vien theo thu tu NLR:\n";
		XuatTieuDe();
		XuatNLR(root);
		XuatDongKeNgangDoi();
		cout << "\n Danh sach hoc vien sau khi dieu chinh tin chi?\n\n";
		SuaTinChi_DL23452(root);
		XuatTieuDe();
		XuatNLR(root);
		XuatDongKeNgangDoi();
		break;
	case 4:
		cout << "\n4. Xoa hoc vien co ma hoc vien DL42032 ra khoi danh sach hoc vien";
		cout << "\n Danh sach sau xoa hoc vien co ma hoc vien DL42032 ra khoi danh sach hoc vien \n\n";
		DeleteNode(root, maHV);
		XuatTieuDe();
		XuatNLR(root);
		XuatDongKeNgangDoi();
		break;
	case 5:
		cout << "\n5. Xuat danh sach hoc vien lop CTK36";
		cout << "\n Danh sach hoc vien lop CTK36 \n\n";
		XuatTieuDe();
		XuatLopCTK36(root);
		XuatDongKeNgangDoi();
		break;
	default:
		break;
	}
	_getch();
}