struct LLSV
{
	char maSV[8];
	char ho[15];
	char ten[10];
	unsigned namsinh;
	char diaChi[15];
};

struct NODELL
{
	LLSV data;
	NODELL* pNext;
};

struct LL
{
	NODELL* pHead;
	NODELL* pTail;
};

struct DiemTP
{
	char maSV[8];
	double dBT1;
	double dBT2;
	double dGK;
	double dQT;
};

struct NODEBD
{
	DiemTP data;
	NODEBD* pNext;
};

struct BD
{
	NODEBD* pHead;
	NODEBD* pTail;
};

void CreatLL(LL& l)
{
	l.pHead = l.pTail = NULL;
}

void CreatBD(BD& l)
{
	l.pHead = l.pTail = NULL;
}

NODELL* GetNodeLL(LLSV x)
{
	NODELL* pNode = new NODELL;
	if (pNode == NULL)
		return NULL;
	pNode->data = x;
	pNode->pNext = NULL;
	return pNode;
}

NODEBD* GetNodeBD(DiemTP x)
{
	NODEBD* pNode = new NODEBD;
	if (pNode == NULL)
		return NULL;
	pNode->data = x;
	pNode->pNext = NULL;
	return pNode;
}

void AddHeadLL(LL& l, NODELL* pNode)
{
	if (l.pHead == NULL)
		l.pHead = l.pTail = pNode;
	else
	{
		pNode->pNext = l.pHead;
		l.pHead = pNode;
	}
}

void AddHeadBD(BD& l, NODEBD* pNode)
{
	if (l.pHead == NULL)
		l.pHead = l.pTail = pNode;
	else
	{
		pNode->pNext = l.pHead;
		l.pHead = pNode;
	}
}

void AddTailLL(LL& l, NODELL* pNode)
{
	if (l.pHead == NULL)
		l.pHead = l.pTail = pNode;
	else
	{
		l.pTail->pNext = pNode;
		l.pTail = pNode;
	}
}

void AddTailBD(BD& l, NODEBD* pNode)
{
	if (l.pHead == NULL)
		l.pHead = l.pTail = pNode;
	else
	{
		l.pTail->pNext = pNode;
		l.pTail = pNode;
	}
}

void InsertHeadLL(LL& l, LLSV x)
{
	NODELL* pNode = GetNodeLL(x);
	if (pNode == NULL)
		return;
	AddHeadLL(l, pNode);
}

void InsertTailLL(LL& l, LLSV x)
{
	NODELL* pNode = GetNodeLL(x);
	if (pNode == NULL)
		return;
	AddTailLL(l, pNode);
}

void InsertHeadBD(BD& l, DiemTP x)
{
	NODEBD* pNode = GetNodeBD(x);
	if (pNode == NULL)
		return;
	AddHeadBD(l, pNode);
}

void InsertTailBD(BD& l, DiemTP x)
{
	NODEBD* pNode = GetNodeBD(x);
	if (pNode == NULL)
		return;
	AddTailBD(l, pNode);
}

void FileReaderLL(char* filename, LL& l)
{
	LLSV x;
	ifstream in(filename);
	if (!in)
	{
		cout << "\nLoi mo file!\n";
		_getch();
		return;
	}
	CreatLL(l);
	while (!in.eof())
	{
		in >> x.maSV;
		in >> x.ho;
		in >> x.ten;
		in >> x.namsinh;
		in >> x.diaChi;
		InsertTailLL(l, x);
	}
	in.close();
}

void FileReaderBD(char* filename, BD& l)
{
	DiemTP x;
	ifstream in(filename);
	if (!in)
	{
		cout << "\nLoi mo file!\n";
		_getch();
		return;
	}
	CreatBD(l);
	while (!in.eof())
	{
		in >> x.maSV;
		in >> x.dBT1;
		in >> x.dBT2;
		in >> x.dGK;
		x.dQT = x.dBT1 + x.dBT2 + x.dGK;
		InsertTailBD(l, x);
	}
	in.close();
}

void XuatTieuDe()
{
	cout << '\n';
	for (int i = 0; i < 52; i++)
		cout << '=';
	cout << '\n';
	cout << setiosflags(ios::left) << " ";
	cout << setw(10) << "MaSV"
		<< setw(16) << "Ho"
		<< setw(11) << "Ten"
		<< setw(6) << "NSinh"
		<< setw(8) << "DiemGK";
	cout << '\n';
	for (int i = 0; i < 52; i++)
		cout << '=';
}

void XuatBangDiem(LL listLL, BD listBD)
{
	XuatTieuDe();
	NODELL* iNode = listLL.pHead;
	NODEBD* jNode = listBD.pHead;
	while (iNode != NULL & jNode != NULL)
	{
		cout << '\n';
		cout << setiosflags(ios::left) << " "
			<< setw(10) << iNode->data.maSV
			<< setw(16) << iNode->data.ho
			<< setw(11) << iNode->data.ten
			<< setw(6) << iNode->data.namsinh
			<< setw(8) << setiosflags(ios::fixed) << setprecision(2) << jNode->data.dQT;
		iNode = iNode->pNext;
		jNode = jNode->pNext;
	}
	cout << '\n';
	for (int i = 0; i < 52; i++)
		cout << '=';
}