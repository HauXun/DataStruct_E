#define MAX 100

struct HocVien
{
	char maHV[10];
	char hoHV[11];
	char tenLot[11];
	char tenHV[11];
	char lop[7];
	unsigned namSinh;
	double diemTB;
	unsigned tcTichLuy;
};

struct NODE
{
	HocVien data;
	NODE* pNext;
};

struct LIST
{
	NODE* pHead;
	NODE* pTail;
};

void KhoiTaoList(LIST& list)
{
	list.pHead = list.pTail = NULL;
}

NODE* GetNode(HocVien x)
{
	NODE* pNode = new NODE;
	if (pNode)
	{
		pNode->data = x;
		pNode->pNext = NULL;
	}
	return pNode;
}

void InsertHead(LIST& list, HocVien x)
{
	NODE* pNode = GetNode(x);
	if (!pNode)
		return;
	if (!list.pHead)
		list.pHead = list.pTail = pNode;
	else
	{
		pNode->pNext = list.pHead;
		list.pHead = pNode;
	}
}

void InsertTail(LIST& list, HocVien x)
{
	NODE* pNode = GetNode(x);
	if (pNode == NULL)
		return;
	if (list.pHead == NULL)
		list.pHead = list.pTail = pNode;
	else
	{
		list.pTail->pNext = pNode;
		list.pTail = pNode;
	}
}

int TaoDanhSachHocVien(char* filename, LIST& list)
{
	ifstream in(filename);
	if (!in)
	{
		return 0;
	}
	else
	{
		KhoiTaoList(list);
		HocVien x;
		while (!in.eof())
		{
			in >> x.maHV;
			in >> x.hoHV;
			in >> x.tenLot;
			in >> x.tenHV;
			in >> x.lop;
			in >> x.namSinh;
			in >> x.diemTB;
			in >> x.tcTichLuy;
			InsertTail(list, x);
		}
		in.close();
		return 1;
	}
}

void XuatDongKeNgangDoi()
{
	cout << "\n";
	for (int i = 0; i <= 82; i++)
		cout << '=';
}

void XuatDongKeNgangDon()
{
	cout << "\n";
	for (int i = 0; i <= 82; i++)
		cout << '-';
}

void XuatTieuDe()
{
	XuatDongKeNgangDoi();
	cout << "\n";
	cout << setiosflags(ios::left)
		<< setw(11) << "Ma HV"
		<< setw(8) << "Ho"
		<< setw(8) << "Ho Lot"
		<< setw(8) << "Ten"
		<< setw(8) << "Lop"
		<< setw(12) << "Nam sinh"
		<< setw(17) << "Diem TB"
		<< setw(10) << "TCTL";
	XuatDongKeNgangDoi();
}

void XuatDSHV(LIST list)
{
	XuatTieuDe();
	NODE* pNode = list.pHead;
	if (!list.pHead)
		return;
	while (pNode)
	{
		cout << '\n';
		cout << setiosflags(ios::left);
		cout << setw(11) << pNode->data.maHV
			<< setw(8) << pNode->data.hoHV
			<< setw(8) << pNode->data.tenLot
			<< setw(8) << pNode->data.tenHV
			<< setw(8) << pNode->data.lop
			<< setw(12) << pNode->data.namSinh
			<< setw(17) << pNode->data.diemTB
			<< setiosflags(ios::fixed) << setprecision(2) << setw(10) << pNode->data.tcTichLuy << '|';
		cout << "\n";
		pNode = pNode->pNext;
	}
	XuatDongKeNgangDoi();
}

void SuaTinChi_DL23452(LIST& list)
{
	NODE* pNode = list.pHead;
	while (pNode)
	{
		if (_strcmpi(pNode->data.maHV, "DL23452") == 0)
			pNode->data.tcTichLuy = 35;
		pNode = pNode->pNext;
	}
}

void XuatLopCTK36(LIST& list)
{
	LIST ctk36;
	KhoiTaoList(ctk36);
	for (NODE* i = list.pHead; i; i = i->pNext)
	{
		if (_strcmpi(i->data.lop, "CTK36") == 0)
			InsertTail(ctk36, i->data);
	}
	XuatDSHV(ctk36);
}

int XoaTheoNamSinh(LIST& list, int namsinh)
{
	NODE* i = list.pHead;
	NODE* j = NULL;
	NODE* k = NULL;
	NODE* g = NULL;
	for (i = list.pHead; i != NULL; i = i->pNext)
	{
		if (i->data.namSinh == namsinh)
		{
			k = i;
			g = j;
		}
		j = i;
	}
	if (k == NULL)
		return 0;

	if (g != NULL)
	{
		if (k == list.pTail)
			list.pTail = g;
		g->pNext = k->pNext;
	}
	else
	{
		list.pHead = k->pNext;
		if (list.pHead == NULL)
			list.pTail = NULL;
	}
	delete i;
	return 1;
}

void XoaNamSinh(LIST& list, int namsinh)
{
	while (XoaTheoNamSinh(list, namsinh));
}