struct NhanVien
{
	char maNV[8];
	char hoNV[10];
	char tenLot[10];
	char ten[10];
	char diaChi[15];
	unsigned namsinh;
	double luong;
};
typedef struct NhanVien DATA;

struct NODE
{
	DATA data;
	NODE* pNext;
};

struct LIST
{
	NODE* pHead;
	NODE* pTail;
};

void CreatList(LIST& list)
{
	list.pHead = list.pTail = NULL;
}

NODE* GetNode(DATA x)
{
	NODE* pNode = new NODE;
	if (pNode == NULL)
		return NULL;
	pNode->data = x;
	pNode->pNext = NULL;
}

int IsEmpty(LIST list)
{
	if (list.pHead == NULL)
		return 1;
	return 0;
}

void InsertHead(LIST& list, DATA x)
{
	NODE* pNode = GetNode(x);
	if (pNode == NULL)
		return;
	if (IsEmpty(list))
		list.pHead = list.pTail = pNode;
	else
	{
		pNode->pNext = list.pHead;
		list.pHead = pNode;
	}
}

void InsertTail(LIST& list, DATA x)
{
	NODE* pNode = GetNode(x);
	if (pNode == NULL)
		return;
	if (IsEmpty(list))
		list.pHead = list.pTail = pNode;
	list.pTail->pNext = pNode;
	list.pTail = pNode;
}

int FileReader(char* filename, LIST& list)
{
	DATA x;
	ifstream in(filename);
	if (!in)
		return 0;
	CreatList(list);
	while (!in.eof())
	{
		in >> x.maNV;
		in >> x.hoNV;
		in >> x.tenLot;
		in >> x.ten;
		in >> x.diaChi;
		in >> x.namsinh;
		in >> x.luong;
		InsertTail(list, x);
	}
	in.close();
	return 1;
}

void XuatTieuDe()
{
	cout << "\n";
	for (int i = 0; i <= 82; i++)
		cout << '=';
	cout << "\n";
	cout << setiosflags(ios::left) << " "
		<< setw(11) << "Ma NV"
		<< setw(8) << "Ho"
		<< setw(8) << "Ho Lot"
		<< setw(8) << "Ten"
		<< setw(15) << "Dia Chi"
		<< setw(12) << "Nam sinh"
		<< setw(17) << "Luong";
	cout << "\n";
	for (int i = 0; i <= 82; i++)
		cout << '=';
}

void XuatNhanVien(DATA a)
{
	cout << setiosflags(ios::left) << " ";
	cout << setw(11) << a.maNV
		<< setw(8) << a.tenLot
		<< setw(8) << a.tenLot
		<< setw(8) << a.ten
		<< setw(15) << a.diaChi
		<< setw(12) << a.namsinh
		<< setiosflags(ios::fixed) << setprecision(2) << setw(17) << a.luong << '|';
	cout << "\n";
}

void XuatDSNV(LIST& list)
{
	XuatTieuDe();
	for (NODE* i = list.pHead; i != NULL; i = i->pNext)
	{
		cout << "\n\n";
		XuatNhanVien(i->data);
	}
	cout << "\n";
	for (int i = 0; i <= 82; i++)
		cout << '=';
}

void TachDSNV_LuongX(LIST list, double x)
{
	LIST list1, list2;
	if (IsEmpty(list))
	{
		cout << "\nDanh sach rong! Vui long kiem tra lai du lieu!\n";
		_getch();
		return;
	}
	CreatList(list1);
	CreatList(list2);
	for (NODE* i = list.pHead; i != NULL; i = i->pNext)
	{
		if (i->data.luong <= x)
			InsertTail(list1, i->data);
		else
			InsertTail(list2, i->data);
	}
	cout << "\nDanh sach nhan vien (Luong <= " << x << " )...\n";
	XuatDSNV(list1);
	cout << "\nDanh sach nhan vien (Luong > " << x << " )...\n";
	XuatDSNV(list2);
	cout << '\n';
}

void TachDSNV_LuanPhien(LIST& list)
{
	LIST list1, list2;
	if (IsEmpty(list))
	{
		cout << "\nDanh sach rong! Vui long kiem tra lai du lieu!";
		_getch();
		return;
	}
	CreatList(list1);
	CreatList(list2);
	int k = 1;
	for (NODE* i = list.pHead; i != NULL; i = i->pNext)
	{
		if (k == 1)
			InsertTail(list1, i->data);
		else
			InsertTail(list2, i->data);
		k = 3 - k;
	}
	cout << "\nDanh sach 1...\n";
	XuatDSNV(list1);
	cout << "\nDanh sach 2...\n";
	XuatDSNV(list2);
	cout << '\n';
}

void DaoNguocDanhSach(LIST list)
{
	LIST list1;
	if (IsEmpty(list))
	{
		cout << "\nDanh sach rong! Vui long kiem tra lai du lieu!";
		_getch();
		return;
	}
	CreatList(list1);
	for (NODE* i = list.pHead; i != NULL; i = i->pNext)
		InsertHead(list1, i->data);
	cout << "\nDanh sach sinh vien dao nguoc...\n";
	XuatDSNV(list1);
}

void SelectionSort(LIST& list)
{
	NODE* csMin;
	for (NODE* i = list.pHead; i != list.pTail; i = i->pNext)
	{
		csMin = i;
		for (NODE* j = i->pNext; j != NULL; j = j->pNext)
		{
			if (_strcmpi(i->data.ten, csMin->data.ten) < 0)
				csMin = j;
		}
		swap(csMin->data, i->data);
	}
}

void SapTang(LIST& list)
{
	SelectionSort(list);
	for (NODE* i = list.pHead; i != list.pTail; i = i->pNext)
	{
		for (NODE* j = i->pNext; j != NULL; j = j->pNext)
		{
			if (_strcmpi(i->data.ten, j->data.ten) > 0)
				swap(i->data, j->data);
			else if (_strcmpi(i->data.ten, j->data.ten) == 0)
			{
				if (_strcmpi(i->data.hoNV, j->data.hoNV) > 0)
					swap(i->data, j->data);
				else if (_strcmpi(i->data.hoNV, j->data.hoNV) == 0)
				{
					if (_strcmpi(i->data.tenLot, j->data.tenLot) > 0)
						swap(i->data, j->data);
				}
			}
		}
	}
}