#include <iostream>
#include <fstream>
#include <conio.h>

using namespace std;

#include "BSTree.h"
#include "List.h"

void ChayChuongTrinh();

int main()
{
	ChayChuongTrinh();
	return 1;
}

void ChayChuongTrinh()
{
	char* filename;
	filename = new char[50];
	BSTree root;
	int kq;
	do
	{
		cout << "\nNhap ten filename can mo : ";
		cin >> filename;
		kq = FileBST(root, filename);
	} while (!kq);
	cout << "\nXuat BST theo thu tu truoc : \n\n";
	NLROrder(root);
	_getch();
	cout << "\n\nXuat BST theo thu tu giua : \n\n";
	LNROrder(root);
	_getch();
	cout << "\n\nXuat BST theo thu tu sau : \n\n";
	LRNOrder(root);
	_getch();
	cout << "\n\nXuat BST theo chieu sau : \n\n";
	DFS(root);
	_getch();
	cout << "\n\nXuat BST theo chieu rong : \n\n";
	BFS(root);
	_getch();
	BFS_TheoMuc(root);
	_getch();
}