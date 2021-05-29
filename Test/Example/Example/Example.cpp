#include <iostream>
#include <iomanip>
#include <string.h>

using namespace std;

struct HocSinh
{
	char ten[30];
	char ngaySinh[10];
	char thangSinh[10];
	char namSinh[10];
};

struct BSNode
{
	HocSinh data;
	BSNode* pLeft;
	BSNode* pRight;
};
typedef BSNode* BSTree;

void CreatBST(BSTree& root)
{
	root = NULL;
}

BSNode* CreatNode(HocSinh x)
{
	BSNode* pNode = new BSNode;
	if (pNode)
	{
		pNode->data = x;
		pNode->pLeft = NULL;
		pNode->pRight = NULL;
	}
	return pNode;
}

int InsertNode(BSTree& root, HocSinh x)
{
	if (root)
	{
		if (_strcmpi(root->data.ten, x.ten) == 0)
			return 0;
		else if (_strcmpi(root->data.ten, x.ten) > 0)
			return InsertNode(root->pLeft, x);
		else
			return InsertNode(root->pRight, x);
	}
	root = CreatNode(x);
	if (!root)
		return -1;
	return 1;
}

int TonTaiHocSinh(BSTree root, HocSinh x)
{
	if (root)
	{
		if (_strcmpi(root->data.ten, x.ten) == 0)
			return 1;
		else if (_strcmpi(root->data.ten, x.ten) > 0)
			return TonTaiHocSinh(root->pLeft, x);
		else
			return TonTaiHocSinh(root->pRight, x);
	}
	if (!root)
		return -1;
	return -1;
}

void Nhap(BSTree& root)
{
	while (true)
	{
		HocSinh x;
		cout << "\nNhap ten hoc sinh: ";
		_flushall();
		gets_s(x.ten, 30);

		cout << "\nNhap ngay sinh cua hoc sinh: ";
		_flushall();
		gets_s(x.ngaySinh, 10);

		cout << "\nNhap thang sinh cua hoc sinh: ";
		_flushall();
		gets_s(x.thangSinh, 10);

		cout << "\nNhap nam sinh cua hoc sinh: ";
		_flushall();
		gets_s(x.namSinh, 10);

		if (TonTaiHocSinh(root, x) == 1)
			break;
		else
			InsertNode(root, x);
	}
}

void Xuat_KeDoi()
{
	cout << endl;
	cout << ':';
	for (size_t i = 0; i < 20; i++)
		cout << '=';
	cout << ':';
}

void Xuat_TieuDe()
{
	Xuat_KeDoi();
	cout << '\n';
	cout << setiosflags(ios::left)
		<< setw(11) << "Ten"
		<< ':'
		<< setw(2) << "NS"
		<< '/'
		<< setw(2) << "TS"
		<< '/'
		<< setw(4) << "NS";
	Xuat_KeDoi();
}

void Xuat_1HV(HocSinh x)
{
	cout << '\n';
	cout << setiosflags(ios::left);
	cout << setw(11) << x.ten
		<< setw(2) << x.ngaySinh << '/'
		<< setw(2) << x.thangSinh << '/'
		<< setw(4) << x.namSinh;
}

void XuatHocSinh(BSTree root)
{
	if (root != NULL)
	{
		Xuat_1HV(root->data);
		XuatHocSinh(root->pLeft);
		XuatHocSinh(root->pRight);
	}
}

int main()
{
	BSTree root;
	CreatBST(root);
	Nhap(root);

	Xuat_TieuDe();
	XuatHocSinh(root);
	Xuat_KeDoi();

	return 1;
}