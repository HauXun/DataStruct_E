void NghiemTucMode()
{
	_setmode(_fileno(stdin), _O_U16TEXT);
	_setmode(_fileno(stdout), _O_U16TEXT);
}

void BinhThuongMode()
{
	_setmode(_fileno(stdin), _O_WTEXT);
	_setmode(_fileno(stdout), _O_WTEXT);
}

wstring PadRight(wstring const& str, size_t s, char c)
{
	return str + wstring(s, c);
}

wstring PadLeft(wstring const& str, size_t s, char c)
{
	return wstring(s, c) + str;
}

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
	NODE* pLeft;
	NODE* pRight;
};
typedef NODE* TREE;

void CreatBST(TREE& root)
{
	root = NULL;
}

NODE* CreatNode(HocVien x)
{
	NODE* pNode = new NODE;
	if (pNode)
	{
		pNode->data = x;
		pNode->pLeft = NULL;
		pNode->pRight = NULL;
	}
	return pNode;
}

int InsertNode(TREE& root, HocVien x)
{
	if (root)
	{
		if (_strcmpi(root->data.maHV, x.maHV) == 0)
			return 0;
		if (_strcmpi(root->data.maHV, x.maHV) > 0)
			return InsertNode(root->pLeft, x);
		else
			return InsertNode(root->pRight, x);
	}
	root = CreatNode(x);
	if (!root)
		return -1;
	return 1;
}

int File_BST(TREE& root, char* filename)
{
	ifstream in(filename);
	if (!in)
		return 0;

	HocVien x;
	int kq;
	CreatBST(root);

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
		kq = InsertNode(root, x);
		if (kq == 0 || kq == -1)
			return 0;
	}
	in.close();
	return 1;
}

void XuatDongKeNgangDoi()
{
	wcout << "\n";
	for (int i = 0; i <= 82; i++)
		wcout << '=';
}

void XuatDongKeNgangDon()
{
	wcout << "\n";
	for (int i = 0; i <= 82; i++)
		wcout << '-';
}

void XuatTieuDe()
{
	XuatDongKeNgangDoi();
	wcout << "\n";
	wcout << setiosflags(ios::left)
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

void Xuat_1_HV(HocVien x)
{
	wcout << '\n';
	wcout << setiosflags(ios::left);
	wcout << setw(11) << x.maHV
		<< setw(8) << x.hoHV
		<< setw(8) << x.tenLot
		<< setw(8) << x.tenHV
		<< setw(8) << x.lop
		<< setw(12) << x.namSinh
		<< setw(17) << x.diemTB
		<< setiosflags(ios::fixed) << setprecision(2) << setw(10) << x.tcTichLuy << '|';
	wcout << "\n";
}

void XuatNLR(TREE root)
{
	if (root != NULL)
	{
		Xuat_1_HV(root->data);
		XuatNLR(root->pLeft);
		XuatNLR(root->pRight);
	}
}

void XuatLNR(TREE root)
{
	if (root != NULL)
	{
		XuatLNR(root->pLeft);
		Xuat_1_HV(root->data);
		XuatLNR(root->pRight);
	}
}

void XuatLRN(TREE root)
{
	if (root != NULL)
	{
		XuatLRN(root->pLeft);
		XuatLRN(root->pRight);
		Xuat_1_HV(root->data);
	}
}