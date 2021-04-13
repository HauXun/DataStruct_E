void XuatMenu()
{
	cout << "\n======================= HE THONG CHUC NANG =======================";
	cout << "\n0. Thoat khoi chuong trinh";
	cout << "\n1. Tao du lieu";
	cout << "\n2. Xem du lieu";
	cout << "\n3. Thuat giai Chon Truc tiep - tai moi buoc dua GTNN ve dau mang";
	cout << "\n4. Thuat giai Chon Truc tiep - tai moi buoc dua GTLN ve cuoi mang";
	cout << "\n5. Thuat giai Chon hai dau";
	cout << "\n6. Thuat giai Chen Truc tiep - chen vao day con tang ben trai";
	cout << "\n7. Thuat giai Chen Truc tiep - chen vao day con tang ben phai";
	cout << "\n8. Thuat giai Chen nhi phan";
	cout << "\n9. Thuat giai Doi cho Truc tiep - tai moi buoc dua GTNN ve dau mang";
	cout << "\n10. Thuat giai Doi cho Truc tiep - tai moi buoc dua GTLN ve cuoi mang";
	cout << "\n11. Thuat giai Bubble - tai moi buoc dua GTNN ve dau mang";
	cout << "\n12. Thuat giai i Bubble - tai moi buoc dua GTLN ve cuoi mang";
	cout << "\n==================================================================";
}

int ChonMenu(int soMenu)
{
	int stt = -1;
	while (stt < 0 || stt > soMenu)
	{
		system("cls");
		XuatMenu();
		cout << "\nNhap vao tuy chon menu tuong ung >> ";
		cin >> stt;
	}
	return stt;
}

void XuLyMenu(int menu, DaySo a, int& n)
{
	char filename[15];
	int ketQua;
	DaySo b;
	Copy(b, a, n);
	switch (menu)
	{
	case 0:
		system("cls");
		cout << "\n0. Thoat khoi chuong trinh";
		break;
	case 1:
		system("cls");
		cout << "\n1. Tao du lieu\n";
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
		ketQua = File_Array(filename, a, n);
		if (ketQua == 0)
		{
			cout << "\nMo tap tin khong thanh cong... !";
		}
		else
		{
			cout << "\nMo tap tin thanh cong !";
			cout << "\nDay da tao...";
			XuatMang(a, n);
		}
		break;
	case 2:
		system("cls");
		cout << "\n2. Xem du lieu\n";
		cout << "\nDay da tao...";
		XuatMang(a, n);
		break;
	case 3:
		system("cls");
		cout << "\n3. Thuat giai Chon Truc tiep - tai moi buoc dua GTNN ve dau mang\n";
		cout << "\nDay so truoc khi sap xep...";
		XuatMang(a, n);
		Selection_Left(b, n);
		cout << "\nDay so sau khi sap xep...";
		XuatMang(b, n);
		break;
	case 4:
		system("cls");
		cout << "\n4. Thuat giai Chon Truc tiep - tai moi buoc dua GTLN ve cuoi mang\n";
		cout << "\nDay so truoc khi sap xep...";
		XuatMang(a, n);
		Selection_Right(b, n);
		cout << "\nDay so sau khi sap xep...";
		XuatMang(b, n);
		break;
	case 5:
		system("cls");
		cout << "\n5. Thuat giai Chon hai dau\n";
		cout << "\nDay so truoc khi sap xep...";
		XuatMang(a, n);
		Selection_Right_Left(b, n);
		cout << "\nDay so sau khi sap xep...";
		XuatMang(b, n);
		break;
	case 6:
		system("cls");
		cout << "\n6. Thuat giai Chen Truc tiep - chen vao day con tang ben trai\n";
		cout << "\nDay so truoc khi sap xep...";
		XuatMang(a, n);
		Insertion_Left(b, n);
		cout << "\nDay so sau khi sap xep...";
		XuatMang(b, n);
		break;
	case 7:
		system("cls");
		cout << "\n7. Thuat giai Chen Truc tiep - chen vao day con tang ben phai\n";
		cout << "\nDay so truoc khi sap xep...";
		XuatMang(a, n);
		Insertion_Right(b, n);
		cout << "\nDay so sau khi sap xep...";
		XuatMang(b, n);
		break;
	case 8:
		system("cls");
		cout << "\n8. Thuat giai Chen nhi phan\n";
		cout << "\nDay so truoc khi sap xep...";
		XuatMang(a, n);
		BinaryInsertion(b, n);
		cout << "\nDay so sau khi sap xep...";
		XuatMang(b, n);
		break;
	case 9:
		system("cls");
		cout << "\n9. Thuat giai Doi cho Truc tiep - tai moi buoc dua GTNN ve dau mang\n";
		cout << "\nDay so truoc khi sap xep...";
		XuatMang(a, n);
		Interchange_Left(b, n);
		cout << "\nDay so sau khi sap xep...";
		XuatMang(b, n);
		break;
	case 10:
		system("cls");
		cout << "\n10. Thuat giai Doi cho Truc tiep - tai moi buoc dua GTLN ve cuoi mang\n";
		cout << "\nDay so truoc khi sap xep...";
		XuatMang(a, n);
		Interchange_Right(b, n);
		cout << "\nDay so sau khi sap xep...";
		XuatMang(b, n);
		break;
	case 11:
		system("cls");
		cout << "\n11. Thuat giai Bubble - tai moi buoc dua GTNN ve dau mang\n";
		cout << "\nDay so truoc khi sap xep...";
		XuatMang(a, n);
		Bubble_Left(b, n);
		cout << "\nDay so sau khi sap xep...";
		XuatMang(b, n);
		break;
	case 12:
		system("cls");
		cout << "\n12. Thuat giai i Bubble - tai moi buoc dua GTLN ve cuoi mang\n";
		cout << "\nDay so truoc khi sap xep...";
		XuatMang(a, n);
		Bubble_Right(b, n);
		cout << "\nDay so sau khi sap xep...";
		XuatMang(b, n);
		break;
	default:
		break;
	}
	_getch();
}