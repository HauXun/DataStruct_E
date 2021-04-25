void XuatMenu()
{
	cout << "\n========================= HE THONG CHUC NANG =========================";
	cout << "\n0. Thoat khoi chuong trinh";
	cout << "\n1. Tao du lieu tu file";
	cout << "\n2. Xem lai du lieu da tao";
	cout << "\n3. Tinh gia tri nho nhat cua danh sach";
	cout << "\n4. Tinh gia tri lon nhat cua danh sach";
	cout << "\n5. Tinh tong cac gia tri trong danh sach";
	cout << "\n6. Tinh tong cac gia tri khac nhau trong danh sach";
	cout << "\n7. Dem gia tri x xuat hien bao nhieu lan trong danh sach";
	cout << "\n8. Xuat cac gia tri khac nhau trong danh sach va so lan xuat hien tuong ung";
	cout << "\n9. Sap danh sach tang dan bang thuat giai chon truc tiep";
	cout << "\n10. Sap danh sach theo yeu cau:";
	cout << "\n\t\t - Gia tri 0 xuat hien tai cac nut dau danh sach";
	cout << "\n\t\t - Tiep theo la cac node co gia tri am giam dan";
	cout << "\n\t\t - Cuoi cung la cac node duong co gia tri tang dan";
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
	LIST list2;
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
			Output(list);
		}
		break;
	case 2:
		system("cls");
		cout << "\n2. Xem lai du lieu da tao\n";
		Output(list);
		break;
	case 3:
		system("cls");
		cout << "\n3. Tinh gia tri nho nhat cua danh sach";
		Copy(list2, list);
		Output(list2);
		cout << "\nGia tri nho nhat trong danh sach la " << TimMin(list2);
		break;
	case 4:
		system("cls");
		cout << "\n4. Tinh gia tri lon nhat cua danh sach";
		Copy(list2, list);
		Output(list2);
		cout << "\nGia tri lon nhat trong danh sach la " << TimMax(list2);
		break;
	case 5:
		system("cls");
		cout << "\n5. Tinh tong cac gia tri trong danh sach";
		Copy(list2, list);
		Output(list2);
		cout << "\nTong cac gia tri trong danh sach la " << TinhTong(list2);
		break;
	case 6:
		system("cls");
		cout << "\n6. Tinh tong cac gia tri khac nhau trong danh sach";
		Copy(list2, list);
		Output(list2);
		cout << "\nTong cac gia tri khac nhau la " << SumIfDif(list2);
		break;
	case 7:
		system("cls");
		cout << "\n7. Dem gia tri x xuat hien bao nhieu lan trong danh sach";
		cout << "\nNhap vao x >> ";
		cin >> x;
		cout << "\n - So " << x << " xuat hien trong danh sach " << CountNumber(list, x) << " lan!";
		break;
	case 8:
		system("cls");
		cout << "\n8. Xuat cac gia tri khac nhau trong danh sach va so lan xuat hien tuong ung";
		Copy(list2, list);
		Output(list2);
		DemSLXH(list2);
		break;
	case 9:
		system("cls");
		cout << "\n9. Sap danh sach tang dan bang thuat giai chon truc tiep";
		Copy(list2, list);
		Output(list2);
		cout << "\nDanh sach sau khi sap xep...";
		SelectionSortIncrease(list2);
		Output(list2);
		break;
	case 10:
		system("cls");
		cout << "\n10. Sap danh sach theo yeu cau:";
		cout << "\n\t\t - Gia tri 0 xuat hien tai cac nut dau danh sach";
		cout << "\n\t\t - Tiep theo la cac node co gia tri am giam dan";
		cout << "\n\t\t - Cuoi cung la cac node duong co gia tri tang dan";
		Copy(list2, list);
		Output(list2);
		cout << "\nDanh sach sau khi sap xep...";
		Sort(list2);
		Output(list2);
		break;
	default:
		break;
	}
	_getch();
}