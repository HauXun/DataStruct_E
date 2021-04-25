void XuatMenu()
{
	cout << "\n==================== HE THONG CHUC NANG ====================";
	cout << "\n0. Thoat khoi chuong trinh";
	cout << "\n1. Tao du lieu";
	cout << "\n2. Xem du lieu";
	cout << "\n\t\t\tTIM";
	cout << "\n3. Tim x Co/Khong";
	cout << "\n4. Tim x - Tra ve vi tri nut dau tien xuat hien neu co";
	cout << "\n5. Tim x - Tra ve vi tri nut cuoi cung xuat hien neu co";
	cout << "\n6. Tim x - Xuat cac vi tri xuat hien neu co";
	cout << "\n\t\t\tCHEN";
	cout << "\n7. Chen x vao dau danh sach";
	cout << "\n8. Chen x vao cuoi danh sach";
	cout << "\n9. Chen x vao danh sach sau nut co du lieu y xuat hien dau tien";
	cout << "\n10. Chen x vao danh sach sau nut co du lieu y xuat hien cuoi cung";
	cout << "\n\t\t\tHUY";
	cout << "\n11. Huy nut dau danh sach";
	cout << "\n12. Huy nut cuoi danh sach";
	cout << "\n13. Huy nut dau tien co x";
	cout << "\n14. Huy nut cuoi cung co x";
	cout << "\n15. Huy cac nut co x";
	cout << "\n16. Huy toan bo danh sach";
	cout << "\n\t\t\tSAP XEP";
	cout << "\n17. Sap tang - Chon truc tiep - Hoan doi du lieu";
	cout << "\n18. Sap tang - Chon truc tiep - Hoan doi lien ket";
	cout << "\n============================================================";
}

int ChonMenu(int soMenu)
{
	int stt;
	for (;;)
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

void XuLyMenu(int menu, LIST& list)
{
	LIST list2;
	NODE* kq;
	char filename[15];
	int result, x, y;
	switch (menu)
	{
	case 0:
		system("cls");
		cout << "\n0. Thoat khoi chuong trinh\n";
		break;
	case 1:
		system("cls");
		cout << "\n1. Tao du lieu\n";
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

		result = File_List(filename, list);
		if (result == 0)
		{
			cout << "\nMo tap tin khong thanh cong... !";
		}
		else
		{
			cout << "\nMo tap tin thanh cong !";
			cout << "\nDanh sach co " << SoNut(list) << " phan tu...\n";
			XuatDSLK(list);
		}
		break;
	case 2:
		system("cls");
		cout << "\n2. Xem du lieu\n";
		cout << "\nDanh sach co " << SoNut(list) << " phan tu...\n";
		XuatDSLK(list);
		break;
	case 3:
		system("cls");
		cout << "\n3. Tim x Co/Khong";
		cout << "\nDanh sach co " << SoNut(list) << " phan tu...\n";
		XuatDSLK(list);
		cout << "\nNhap x >> ";
		cin >> x;
		kq = Search_First(list, x);
		if (kq != NULL)
			cout << endl << x << " co trong danh sach";
		else
			cout << endl << x << " khong co trong danh sach";
		cout << '\n';
		break;
	case 4:
		system("cls");
		cout << "\n4. Tim x - Tra ve vi tri nut dau tien xuat hien neu co";
		cout << "\nDanh sach co " << SoNut(list) << " phan tu...\n";
		XuatDSLK(list);
		cout << "\nNhap x >> ";
		cin >> x;
		result = SearchNode_First(list, x);
		if (result)
			cout << endl << x << " xuat hien dau tien trong danh sach tai nut thu " << result;
		else
			cout << endl << x << " khong co trong danh sach";
		break;
	case 5:
		system("cls");
		cout << "\n5. Tim x - Tra ve vi tri nut cuoi cung xuat hien neu co";
		cout << "\nDanh sach co " << SoNut(list) << " phan tu...\n";
		XuatDSLK(list);
		cout << "\nNhap x >> ";
		cin >> x;
		result = SearchNode_End(list, x);
		if (result)
			cout << endl << x << " xuat hien cuoi cung trong danh sach tai nut thu " << result;
		else
			cout << endl << x << " khong co trong danh sach";
		break;
	case 6:
		system("cls");
		cout << "\n6. Tim x - Xuat cac vi tri xuat hien neu co";
		cout << "\nDanh sach co " << SoNut(list) << " phan tu...\n";
		XuatDSLK(list);
		cout << "\nNhap vao x de kiem tra >> ";
		cin >> x;
		SearchNodeX(list, x);
		cout << endl;
		break;
	case 7:
		system("cls");
		cout << "\n7. Chen x vao dau danh sach";
		cout << "\nDanh sach co " << SoNut(list) << " phan tu...\n";
		XuatDSLK(list);
		cout << "\nNhap node x can chen >> ";
		cin >> x;
		InsertHead(list, x);
		cout << "\nDanh sach moi co " << SoNut(list) << " phan tu sau khi chen node " << x << " vao dau danh sach...\n";
		XuatDSLK(list);
		break;
	case 8:
		system("cls");
		cout << "\n8. Chen x vao cuoi danh sach";
		cout << "\nDanh sach co " << SoNut(list) << " phan tu...\n";
		XuatDSLK(list);
		cout << "\nNhap node x can chen >> ";
		cin >> x;
		InsertTail(list, x);
		cout << "\nDanh sach moi co " << SoNut(list) << " phan tu sau khi chen node " << x << " vao cuoi danh sach...\n";
		XuatDSLK(list);
		break;
	case 9:
		system("cls");
		cout << "\n9. Chen x vao danh sach sau nut co du lieu y xuat hien dau tien";
		cout << "\nDanh sach co " << SoNut(list) << " phan tu...\n";
		XuatDSLK(list);
		cout << "\nNhap node can chen >> ";
		cin >> x;
		cout << "\nNhap node can tim trong danh sach de chen >> ";
		cin >> y;
		InsertNodeXAfter_FirstYLocation(list, x, y);
		XuatDSLK(list);
		cout << "\nDanh sach moi co " << SoNut(list) << " phan tu sau khi chen node " << x << " vao vi tri dau tien node " << y << " xuat hien...\n";
		break;
	case 10:
		system("cls");
		cout << "\n10. Chen x vao danh sach sau nut co du lieu y xuat hien cuoi cung";
		cout << "\nDanh sach co " << SoNut(list) << " phan tu...\n";
		XuatDSLK(list);
		cout << "\nNhap node can chen >> ";
		cin >> x;
		cout << "\nNhap node can tim trong danh sach de chen >> ";
		cin >> y;
		InssertNodexAfter_EndYLocation(list, x, y);
		XuatDSLK(list);
		cout << "\nDanh sach moi co " << SoNut(list) << " phan tu sau khi chen node " << x << " vao vi tri cuoi cung node " << y << " xuat hien...\n";
		break;
	case 11:
		system("CLS");
		cout << "\n11. Huy nut dau danh sach";
		cout << "\nDanh sach co " << SoNut(list) << " phan tu...\n";
		XuatDSLK(list);
		cout << endl;
		RemoveHead(list);
		cout << "\nDanh sach moi co " << SoNut(list) << " phan tu sau khi xoa node dau danh sach...\n";
		XuatDSLK(list);
		break;
	case 12:
		system("CLS");
		cout << "\n12. Huy nut cuoi danh sach";
		cout << "\nDanh sach co " << SoNut(list) << " phan tu...\n";
		XuatDSLK(list);
		cout << endl;
		RemoveTail(list);
		cout << "\nDanh sach moi co " << SoNut(list) << " phan tu sau khi xoa node cuoi danh sach...\n";
		XuatDSLK(list);
		break;
	case 13:
		system("CLS");
		cout << "\n13. Huy nut dau tien co x";
		cout << "\nDanh sach co " << SoNut(list) << " phan tu...\n";
		XuatDSLK(list);
		cout << "\nNhap node x de xoa >> ";
		cin >> x;
		result = RemoveFirstNode(list, x);
		if (!result)
			cout << endl << x << " khong co trong danh sach";
		else
		{
			cout << "\nDanh sach moi co " << SoNut(list) << " phan tu sau khi xoa node " << x << " dau tien trong danh sach...\n";
			XuatDSLK(list);
		}
		break;
	case 14:
		system("CLS");
		cout << "\n14. Huy nut cuoi cung co x";
		cout << "\nDanh sach co " << SoNut(list) << " phan tu...\n";
		XuatDSLK(list);
		cout << "\nNhap node x de xoa >> ";
		cin >> x;
		result = RemoveEndNode(list, x);
		if (!result)
			cout << endl << x << " khong co trong danh sach";
		else
		{
			cout << "\nDanh sach moi co " << SoNut(list) << " phan tu sau khi xoa node " << x << " cuoi cung trong danh sach...\n";
			XuatDSLK(list);
		}
		break;
	case 15:
		system("CLS");
		cout << "\n15. Huy cac nut co x";
		cout << "\nDanh sach co " << SoNut(list) << " phan tu...\n";
		XuatDSLK(list);
		cout << "\nNhap node x de xoa >> ";
		cin >> x;
		if (!RemoveFirstNode(list, x))
			cout << "Khong co " << x << " trong danh sach! Du lieu trong danh sach se khong thay doi...";
		else
		{
			RemoveX(list, x);
			cout << "\nDanh sach moi co " << SoNut(list) << " phan tu sau khi xoa tat ca node " << x << " trong danh sach...\n";
			XuatDSLK(list);
		}
		break;
	case 16:
		system("CLS");
		cout << "\n16. Huy toan bo danh sach";
		Copy(list2, list);
		cout << "\nDanh sach co " << SoNut(list) << " phan tu...\n";
		XuatDSLK(list);
		RemoveList(list);
		cout << "\nDanh sach sau khi huy tat ca node...\n";
		XuatDSLK(list);
		cout << "\nNhan phim bat ky de phuc hoi lai danh sach lien ket >> ";
		system("pause");
		Copy(list, list2);
		cout << "\nDanh sach sau khi phuc hoi...\n";
		cout << "\nDanh sach co " << SoNut(list) << " phan tu...\n";
		XuatDSLK(list);
		break;
	case 17:
		system("CLS");
		cout << "\n17. Sap tang - Chon truc tiep - Hoan doi du lieu";
		Copy(list2, list);
		cout << "\nDanh sach ban dau co " << SoNut(list2) << " phan tu...\n";
		XuatDSLK(list2);
		SelectionSortList(list2);
		cout << "\nDanh sach sau khi sap tang...\n";
		XuatDSLK(list2);
		break;
	case 18:
		system("CLS");
		cout << "\n18. Sap tang - Chon truc tiep - Hoan doi lien ket";
		Copy(list2, list);
		cout << "\nDanh sach ban dau co " << SoNut(list2) << " phan tu...\n";
		XuatDSLK(list2);
		SelectionSortList2(list2);
		cout << "\nDanh sach sau khi sap tang...\n";
		XuatDSLK(list2);
		break;
	}
	_getch();
}