#define MAX 100

struct tagNode
{
	int data;
	tagNode* pNext;
};
typedef struct tagNode NODE;

struct LIST
{
	NODE* pHead;
	NODE* pTail;
};

void CreatList(LIST& list)
{
	list.pHead = list.pTail = NULL;
}

NODE* GetNode(int x)
{
	NODE* pNode = new NODE;
	if (pNode == NULL)
		return NULL;
	pNode->data = x;
	pNode->pNext = NULL;
	return pNode;
}

int IsEmpty(LIST list)
{
	if (list.pHead == NULL)
		return 1;
	return 0;
}

// Chèn đầu
void AddHead(LIST& list, NODE* pNode)
{
	if (pNode == NULL)
		list.pHead = list.pTail = pNode;
	else
	{
		pNode->pNext = list.pHead;
		list.pHead = pNode;
	}
}

void InsertHead(LIST& list, int x)
{
	NODE* pNode = GetNode(x);
	if (pNode == NULL)
		return;
	AddHead(list, pNode);
}

// Chèn cuối
void AddTail(LIST& list, NODE* pNode)
{
	if (list.pHead == NULL)
		list.pHead = list.pTail = pNode;
	else
	{
		list.pTail->pNext = pNode;
		list.pTail = pNode;
	}
}
void InsertTail(LIST& list, int x)
{
	NODE* pNode = GetNode(x);
	if (pNode == NULL)
		return;
	AddTail(list, pNode);
}

void XuatDSLK(LIST list)
{
	if (IsEmpty(list))
	{
		cout << "\nDanh sach rong";
		return;
	}
	for (NODE* i = list.pHead; i != NULL; i = i->pNext)
		cout << '\t' << i->data;
	cout << '\n';
}

// Tập tin -> List: dùng chèn cuối
int File_List(char* filename, LIST& list)
{
	ifstream in(filename);
	if (!in)
		return 0;
	CreatList(list);
	int x;
	while (!in.eof())
	{
		in >> x;
		InsertTail(list, x);
	}
	in.close();
	return 1;
}

// Đếm số lượng nút
int SoNut(LIST list)
{
	int count = 0;
	for (NODE* i = list.pHead; i != NULL; i = i->pNext)
		count++;
	return count;
}

NODE* Search_First(LIST list, int x)
{
	NODE* i = list.pHead;
	for (i = list.pHead; i != NULL; i = i->pNext)
		if (i->data == x)
			break;
	return i;
}

NODE* Search_End(LIST list, int x)
{
	NODE* k = NULL;
	for (NODE* i = list.pHead; i != NULL; i = i->pNext)
		if (i->data == x)
			k = i;
	return k;
}

int SearchNode_First(LIST list, int x)
{
	int count = 0;
	for (NODE* i = list.pHead; i != NULL; i = i->pNext)
	{
		if (i->data == x)
			return count;
		count++;
	}
	return -1;
}

int SearchNode_End(LIST list, int x)
{
	int result = -1, count = 0;
	for (NODE* i = list.pHead; i != NULL; i = i->pNext)
	{
		if (i->data == x)
			result = count;
		count++;
	}
	return result;
}

void SearchNodeX(LIST list, int x)
{
	NODE* k = Search_First(list, x);
	if (k == NULL)
	{
		cout << endl << x << " khong co trong danh sach";
		return;
	}
	cout << endl << "\tSo " << x << " xuat hien trong danh sach tai nhung vi tri...\n";

	int j = 0;
	for (NODE* i = list.pHead; i != NULL; i = i->pNext)
	{
		if (i->data == x)
			cout << '\t' << j;
		j++;
	}
}

// Chèn sau node x
void InsertAfter(LIST& list, NODE* xNode, int x)
{
	NODE* pNode = GetNode(x);
	if (pNode == NULL)
		return;
	if (xNode != NULL)
	{
		pNode->pNext = xNode->pNext;
		xNode->pNext = pNode;
		if (xNode == list.pTail)
			list.pTail = pNode;
	}
	else
		InsertHead(list, x);
}

// Chèn node x vào sau vị trí y đầu tiên xuất hiện trong danh sách nếu có, nếu không có thì chèn vào đầu danh sách
void InsertNodeXAfter_FirstYLocation(LIST& list, int x, int y)
{
	NODE* pNode = Search_First(list, y);
	InsertAfter(list, pNode, x);
}

// Chèn node x vào sau vị trí y cuối cùng xuất hiện trong danh sách nếu có, nếu không có thì chèn vào đầu danh sách
void InssertNodexAfter_EndYLocation(LIST& list, int x, int y)
{
	NODE* pNode = Search_End(list, y);
	InsertAfter(list, pNode, x);
}

void RemoveHead(LIST& list)
{
	if (list.pHead == NULL)
	{
		cout << "\nDanh sach rong! Khong xoa duoc, vui long chon thao tac khac!!!\n";
		return;
	}
	NODE* pNode = list.pHead;
	list.pHead = list.pHead->pNext;
	delete pNode;
	if (list.pHead == NULL)
		list.pTail = NULL;
}

void RemoveTail(LIST& list)
{
	if (list.pHead == NULL)
	{
		cout << "\nDanh sach rong! Khong xoa duoc, vui long chon thao tac khac!!!\n";
		return;
	}
	for (NODE* i = list.pHead; i != NULL; i = i->pNext)
	{
		if (i->pNext == list.pTail)
		{
			delete list.pTail;
			i->pNext = NULL;
			list.pTail = i;
		}
	}
	if (list.pTail == NULL)
		list.pHead = NULL;
}

int RemoveFirstNode(LIST& list, int x)
{
	NODE* j = NULL;
	NODE* i = list.pHead;
	for (i = list.pHead; i != NULL; i = i->pNext)
	{
		if (i->data == x)
			break;
		j = i;
	}
	if (i == NULL)
		return 0;
	if (j != NULL)
	{
		if (i == list.pTail)
			list.pTail = j;
		j->pNext = i->pNext;
	}
	else
	{
		list.pHead = i->pNext;
		if (list.pHead == NULL)
			list.pTail = NULL;
	}
	delete i;
	return 1;
}

int RemoveEndNode(LIST& list, int x)
{
	NODE* i = list.pHead;
	NODE* j = NULL;		// Node trước node i <=> node k
	NODE* k = NULL;
	NODE* g = NULL;		// Node trước node k <=> node i
	for (i = list.pHead; i != NULL; i = i->pNext)
	{
		if (i->data == x)
		{
			k = i;
			g = j;
		}
		j = i;
	}
	if (k == NULL)
		return 0;

	// Xóa node sau node g
	if (g != NULL)
	{
		if (k == list.pTail)
			list.pTail = g;		// Xóa node cuối
		g->pNext = k->pNext;
	}
	else	// Xóa node đầu
	{
		list.pHead = k->pNext;
		if (list.pHead == NULL)
			list.pTail = NULL;
	}
	delete i;
	return 1;
}

void RemoveX(LIST& list, int x)
{
	while (RemoveFirstNode(list, x));
}

void RemoveList(LIST& list)
{
	NODE* delNode;
	while (list.pHead != NULL)
	{
		delNode = list.pHead;
		list.pHead = delNode->pNext;
		delete delNode;
	}
	list.pTail = NULL;
}

void Copy(LIST& list2, LIST list)
{
	CreatList(list2);
	if (IsEmpty(list))
	{
		cout << "\nDanh sach dang rong! Vui long kiem tra lai du lieu";
		return;
	}
	int x;
	for (NODE* i = list.pHead; i != NULL; i = i->pNext)
	{
		x = i->data;
		InsertTail(list2, x);
	}
}

void SelectionSortList(LIST& list)
{
	NODE* csMin;
	for (NODE* i = list.pHead; i != list.pTail; i = i->pNext)
	{
		csMin = i;
		for (NODE* j = i->pNext; j != NULL; j = j->pNext)
		{
			if (csMin->data > j->data)
				csMin = j;
		}
		swap(csMin->data, i->data);
	}
}

// Sắp tăng - Hoán đổi liên kết
void SelectionSortList2(LIST& list)
{
	LIST listResult;	// Danh sách kêt quả trung gian
	CreatList(listResult);

	NODE* csMin;		// Lưu node đầu tiên có giá trị min tại mỗi bước
	NODE* preCsMin;		// Node trước node csMin

	NODE* i;	// Node trước node j
	NODE* j;	// Node j duyệt tìm csMin tại mỗi bước, mỗi bước xác định bởi pHead, sau mỗi bước giảm 1 node;
	while (list.pHead != NULL)
	{
		i = list.pHead;
		j = i->pNext; // Node sau node i

		csMin = i;
		preCsMin = NULL;
		while (j != NULL)
		{
			if (j->data < csMin->data)
			{
				csMin = j;
				preCsMin = i;
			}
			i = j;
			j = j->pNext;
		}
		if (preCsMin != NULL)
			preCsMin->pNext = csMin->pNext;
		else	// Node đầu là csMin, sẽ cắt bỏ lớp này nên ta cập nhập lại pHead
			list.pHead = csMin->pNext;
		csMin->pNext = NULL;
		AddTail(listResult, csMin);
	}
	Copy(list, listResult);
}