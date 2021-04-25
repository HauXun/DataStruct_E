struct LLNV
{
	char maNV[8];
	char hoTen[15];
	char diaChi[15];
	unsigned TDVH;
	int luongCB;
	int luongPT;
	int luongTL;
};

struct CCNV
{
	char maNV[8];
	unsigned nghiKP;
	unsigned nghiCP;
	unsigned ngayLT;
};

struct NODELL
{
	LLNV data;
	NODELL* pNext;
};

struct LISTLL
{
	NODELL* pHead;
	NODELL* pTail;
};

struct NODECC
{
	CCNV data;
	NODECC* pNext;
};

struct LISTCC
{
	NODECC* pHead;
	NODECC* pTail;
};

void CreatListLL(LISTLL& list)
{
	list.pHead = list.pTail = NULL;
}

void CreatListCC(LISTCC& list)
{
	list.pHead = list.pTail = NULL;
}

NODELL* GetNodeLL(LLNV x)
{
	NODELL* pNode = new NODELL;
	if (pNode == NULL)
		return NULL;
	pNode->data = x;
	pNode->pNext = NULL;
}

NODECC* GetNodeCC(CCNV x)
{
	NODECC* pNode = new NODECC;
	if (pNode == NULL)
		return NULL;
	pNode->data = x;
	pNode->pNext = NULL;
}

void InsertTailLL(LISTLL& list, LLNV x)
{
	NODELL* pNode = GetNodeLL(x);
	if (pNode == NULL)
		return;
	if (list.pHead == NULL)
		list.pHead = list.pTail = pNode;
	list.pTail->pNext = pNode;
	list.pTail = pNode;
}

void InsertTailCC(LISTCC& list, CCNV x)
{
	NODECC* pNode = GetNodeCC(x);
	if (pNode == NULL)
		return;
	if (list.pHead == NULL)
		list.pHead = list.pTail = pNode;
	list.pTail->pNext = pNode;
	list.pTail = pNode;
}

void FileReaderLL(char* filename, LISTLL& list)
{
	int luongPT;
	LLNV x;

	ifstream in(filename);
	if (!in)
	{
		cout << "\nLoi mo file!\n";
		_getch();
		return;
	}
	CreatListLL(list);
	while (!in.eof())
	{
		in >> x.maNV;
		in >> x.hoTen;
		in >> x.diaChi;
		in >> x.TDVH;
		in >> x.luongCB;

		luongPT = 0;
		if (x.luongCB == 5)
			luongPT = 10 * x.luongCB / 100;
		else if (x.TDVH == 6)
			luongPT = 20 * x.luongCB / 100;
		x.luongPT = luongPT;
		x.luongTL = 0;
		InsertTailLL(list, x);
	}
	in.close();
}

void FileReaderCC(char* filename, LISTCC& listCC, LISTLL listLL)
{
	CCNV x;
	NODELL* i = listLL.pHead;
	ifstream in(filename);
	if (!in)
	{
		cout << "\nLoi mo file!\n";
		_getch();
		return;
	}
	CreatListCC(listCC);
	while (!in.eof())
	{
		in >> x.maNV;
		in >> x.nghiCP;
		in >> x.nghiKP;
		in >> x.ngayLT;

		if (_strcmpi(i->data.maNV, x.maNV) != 0)
		{
			cout << "\nLoi thu tu ma nhan vien dan den khong the doc file! Vui long kiem tra lai cac file du lieu...\n";
			_getch();
			return;
		}
		InsertTailCC(listCC, x);

		i->data.luongPT += x.ngayLT * 4 * i->data.luongCB / 100;
		i->data.luongPT -= x.nghiKP * 4 * i->data.luongCB / 100;
		if (x.nghiCP >= 15)
			i->data.luongPT -= 10 * i->data.luongCB / 100;
		i->data.luongTL = i->data.luongCB + i->data.luongPT;
		i = i->pNext;
	}
	in.close();
}


void XuatTieuDe()
{
	cout << '\n';
	for (int i = 0; i < 60; i++)
		cout << '=';
	cout << '\n';
	cout << setiosflags(ios::left) << " "
		<< setw(10) << "Ma NV"
		<< setw(19) << "Ho va ten"
		<< setw(9) << "Luong CB"
		<< setw(9) << "Phu troi"
		<< setw(9) << "Luong TL";
	cout << '\n';
	for (int i = 0; i < 60; i++)
		cout << '=';
}

void XuatBangLuongNV(LISTLL listLL, LISTCC listCC)
{
	XuatTieuDe();
	NODELL* iNode = listLL.pHead;
	while (iNode != NULL)
	{
		cout << '\n';
		cout << setiosflags(ios::left) << " "
			<< setw(10) << iNode->data.maNV
			<< setw(19) << iNode->data.hoTen
			<< setw(9) << setprecision(2) << setiosflags(ios::fixed) << iNode->data.luongCB
			<< setw(9) << setprecision(2) << setiosflags(ios::fixed) << iNode->data.luongPT
			<< setw(9) << setprecision(2) << setiosflags(ios::fixed) << iNode->data.luongTL;
		iNode = iNode->pNext;
	}
	cout << '\n';
	for (int i = 0; i < 60; i++)
		cout << '=';
	cout << '\n';
}

void SapXep(LISTLL& list)
{
	for (NODELL* i = list.pHead; i != list.pTail; i = i->pNext)
	{
		for (NODELL* j = i->pNext; j != NULL; j = j->pNext)
		{
			if (j->data.luongTL < i->data.luongTL)
				swap(i->data, j->data);
			else if (j->data.luongTL == i->data.luongTL)
				if (_strcmpi(j->data.maNV, i->data.maNV) < 0)
					swap(i->data, j->data);
		}
	}
}