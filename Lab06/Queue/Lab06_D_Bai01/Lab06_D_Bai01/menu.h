void XuatMenu()
{
	cout << "\n==================== HE THONG CHUC NANG ====================";
	cout << "\n0. Thoat khoi chuong trinh";
	cout << "\n1. Tao du lieu";
	cout << "\n2. Xem du lieu";
	cout << "\n3. Them mot node cuoi queue";
	cout << "\n4. Dem so lan xuat hien node x trong danh sach";
	cout << "\n5. Huy mot node dau queue";
	cout << "\n6. Xoa toan bo nhung node co du lieu trong queue";
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

void XuLyMenu(int menu, QUEUE& q)
{
	NODE* kq;
	char filename[15];
	int result, x;
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

		result = FileReader(filename, q);
		if (result == 0)
		{
			cout << "\nMo tap tin khong thanh cong... !";
		}
		else
		{
			cout << "\nMo tap tin thanh cong !";
			Output(q);
		}
		break;
	case 2:
		system("cls");
		cout << "\n2. Xem du lieu\n";
		Output(q);
		break;
	case 3:
		system("cls");
		cout << "\n3. Them mot node cuoi queue";
		cout << "\nNhap gia tri node can them >> ";
		cin >> x;
		kq = KhoiTaoNode(x);
		Push(q, kq);
		cout << "\nQueue sau khi them node " << kq->data << " vao dau danh sach!";
		Output(q);
		break;
	case 4:
		system("cls");
		cout << "\n4. Dem so lan xuat hien node x trong danh sach";
		Output(q);
		cout << "\nNhap gia tri node can dem >> ";
		cin >> x;
		cout << " Node " << x << " xuat hien " << CountNode(q, x) << " lan trong queue";
		break;
	case 5:
		system("cls");
		cout << "\n5. Huy mot node dau queue";
		Pop(q, x);
		cout << "\nQueue sau khi xoa node dau danh sach";
		Output(q);
		break;
	case 6:
		system("cls");
		cout << "\n6. Xoa toan bo nhung node co du lieu trong queue";
		DelAll(q);
		Output(q);
		break;
	}
	_getch();
}