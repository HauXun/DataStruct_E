struct HocVien
{
	char maNV[10];
	char hoHV[11];
	char tenLot[11];
	char tenHV[11];
	unsigned namSinh;
	unsigned luong;
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
		if (_strcmpi(root->data.maNV, x.maNV) == 0)
			return 0;
		if (_strcmpi(root->data.maNV, x.maNV) > 0)
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
		in >> x.maNV;
		in >> x.hoHV;
		in >> x.tenLot;
		in >> x.tenHV;
		in >> x.namSinh;
		in >> x.luong;
		kq = InsertNode(root, x);
		if (kq == 0 || kq == -1)
			return 0;
	}
	in.close();
	return 1;
}

void XuatDongKeNgangDoi()
{
	for (int i = 0; i <= 57; i++)
		cout << '=';
}

void XuatDongKeNgangDon()
{
	cout << "\n";
	for (int i = 0; i <= 57; i++)
		cout << '-';
}

void XuatTieuDe()
{
	cout << '\n';
	XuatDongKeNgangDoi();
	cout << "\n";
	cout << setiosflags(ios::left)
		<< setw(11) << "Ma NV"
		<< setw(8) << "Ho"
		<< setw(8) << "Ho Lot"
		<< setw(8) << "Ten"
		<< setw(12) << "Nam sinh"
		<< setw(10) << "Luong";
	cout << '\n';
	XuatDongKeNgangDoi();
}

void Xuat_1_NV(HocVien x)
{
	cout << '\n';
	cout << setiosflags(ios::left);
	cout << setw(11) << x.maNV
		<< setw(8) << x.hoHV
		<< setw(8) << x.tenLot
		<< setw(8) << x.tenHV
		<< setw(12) << x.namSinh
		<< setiosflags(ios::fixed) << setprecision(2) << setw(10) << x.luong << '|';
	cout << "\n";
}


void XuatLNR(TREE root)
{
	if (root != NULL)
	{
		XuatLNR(root->pLeft);
		Xuat_1_NV(root->data);
		XuatLNR(root->pRight);
	}
}