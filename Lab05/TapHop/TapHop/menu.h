void XuatMenu()
{
	cout << "\n==================== HE THONG CHUC NANG ====================";
	cout << "\n0. Thoat khoi chuong trinh";
	cout << "\n1. Nhap du lieu tu tap tin";
	cout << "\n2. Xem du lieu tap hop";
	cout << "\n\t\tCAC THAO TAC TREN TAP HOP SO NGUYEN";
	cout << "\n3. Giao 2 tap hop";
	cout << "\n4. Hop 2 tap hop";
	cout << "\n5. Hieu 2 tap hop";
	cout << "\n6. Hieu doi xung 2 tap hop";
	cout << "\n7. Tich Descartes 2 tap hop";
	cout << "\n8. Kiem tra phan tu co thuoc vao tap hop";
	cout << "\n9. Kiem tra quan he bao ham giua 2 tap hop";
	cout << "\n10. Tinh luc luong tap hop";
	cout << "\n============================================================";
}

int ChonMenu(int soMenu)
{
	int stt;
	while (1)
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

void XuLyMenu(int menu, LIST& a, LIST& b)
{
	LIST result;
	CreatList(result);
	int x;

	char filenameA[10] = "A.txt";
	char filenaemB[10] = "B.txt";

	system("cls");
	switch (menu)
	{
	case 0:
		cout << "\n0. Thoat khoi chuong trinh";
		break;
	case 1:
		cout << "\n1. Nhap du lieu tu tap tin\n";
		FileReader(filenameA, a);
		FileReader(filenaemB, b);
		cout << "\nDu lieu A - B hien hanh...\n";
		cout << "\nTap hop A = ";
		Output(a);
		cout << "\nTap hop B = ";
		Output(b);
		break;
	case 2:
		cout << "\n2. Xem du lieu tap hop\n";
		cout << "\nDu lieu A - B hien hanh...\n";
		cout << "\nTap hop A = ";
		Output(a);
		cout << "\nTap hop B = ";
		Output(b);
		break;
	case 3:
		cout << "\n3. Giao 2 tap hop\n";
		cout << "\nTap hop A = ";
		Output(a);
		cout << "\nTap hop B = ";
		Output(b);
		cout << "\nA n B = ";
		result = Giao2TapHop(a, b);
		Output(result);
		break;
	case 4:
		cout << "\n4. Hop 2 tap hop\n";
		cout << "\nTap hop A = ";
		Output(a);
		cout << "\nTap hop B = ";
		Output(b);
		cout << "\nA u B = ";
		result = Hop2TapHop(a, b);
		Output(result);
		break;
	case 5:
		cout << "\n5. Hieu 2 tap hop\n";
		cout << "\nTap hop A = ";
		Output(a);
		cout << "\nTap hop B = ";
		Output(b);
		cout << "\nA \\ B = ";
		result = Hieu2TapHop(a, b);
		Output(result);
		break;
	case 6:
		cout << "\n6. Hieu doi xung 2 tap hop\n";
		cout << "\nTap hop A = ";
		Output(a);
		cout << "\nTap hop B = ";
		Output(b);
		cout << "\nA /\\ B = ";
		result = HieuDanhSach2TapHop(a, b);
		Output(result);
		break;
	case 7:
		cout << "\n7. Tich Descartes 2 tap hop\n";
		cout << "\nTap hop A = ";
		Output(a);
		cout << "\nTap hop B = ";
		Output(b);
		cout << "\nA x B = \n";
		TichDescrates(a, b);
		break;
	case 8:
		cout << "\n8. Kiem tra phan tu co thuoc vao tap hop\n";
		cout << "\nTap hop A = ";
		Output(a);
		cout << "\nTap hop B = ";
		Output(b);
		cout << "\nNhap phan tu x = ";
		cin >> x;
		if (CheckDependent(a, x) && CheckDependent(b, x))
			cout << "\nPhan tu x thuoc 2 tap hop A va B";
		else if (CheckDependent(a, x))
			cout << "\nPhan tu x thuoc tap hop A";
		else if (CheckDependent(b, x))
			cout << "\nPhan tu x thuoc tap hop B";
		else if (!(CheckDependent(a, x) && CheckDependent(b, x)))
			cout << "\nPhan tu x khong thuoc 2 tap hop A va B";
		break;
	case 9:
		cout << "\n9. Kiem tra quan he bao ham giua 2 tap hop\n";
		cout << "\nTap hop A = ";
		Output(a);
		cout << "\nTap hop B = ";
		Output(b);
		if (RelationshipTest(a, b) && RelationshipTest(b, a))
			cout << "\nTap hop a bang tap hop b";
		else if (RelationshipTest(a, b))
			cout << "\nTap hop a bao ham trong tap hop b";
		else if (RelationshipTest(b, a))
			cout << "\nTap hop b bao ham trong tap hop a";
		else cout << "\nHai tap hop khong bao ham lan nhau";;
		break;
	case 10:
		cout << "\n10. Tinh luc luong tap hop\n";
		cout << "\nTap hop A = ";
		Output(a);
		cout << "\nTap hop B = ";
		Output(b);
		cout << "\nLuc luong cua tap hop a : " << LucLuongTapHop(a);
		cout << "\nLuc luong cua tap hop b : " << LucLuongTapHop(b);
		break;
	default:
		break;
	}
	_getch();
}