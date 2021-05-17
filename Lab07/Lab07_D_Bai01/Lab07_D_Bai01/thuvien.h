struct NODE
{
	int data;
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

NODE* GetNode(int x)
{
	NODE* pNode = new NODE;
	if (pNode)
	{
		pNode->data = x;
		pNode->pNext = NULL;
	}
	return pNode;
}

void AddHead(LIST& list, int x)
{
	NODE* pNode = GetNode(x);
	if (!pNode)
	{
		cout << "\nLoi cap phat bo nho!";
		return;
	}
	if (!list.pHead)
	{
		list.pHead = list.pTail = pNode;
		list.pTail->pNext = list.pHead;
	}
	else
	{
		pNode->pNext = list.pHead;
		list.pHead = pNode;
		list.pTail->pNext = list.pHead;
	}
}

void AddTail(LIST& list, int x)
{
	NODE* pNode = GetNode(x);
	if (!pNode)
	{
		cout << "\nLoi cap phat bo nho!";
		return;
	}
	if (!list.pHead)
	{
		list.pHead = list.pTail = pNode;
		list.pTail->pNext = list.pHead;
	}
	else
	{
		list.pTail->pNext = pNode;
		list.pTail = pNode;
		list.pTail->pNext = list.pHead;
	}
}

int FileReader(char* filename, LIST& list)
{
	ifstream in(filename);
	if (!in)
		return 0;
	CreatList(list);
	int x;
	while (!in.eof())
	{
		in >> x;
		AddTail(list, x);
	}
	in.close();
	return 1;
}

void Output(LIST list)
{
	if (!list.pHead)
	{
		cout << "\nDanh sach rong!";
		return;
	}
	cout << '\n';
	for (NODE* i = list.pHead; i != NULL; i = i->pNext)
		cout << ' ' << i->data;
	cout << '\n';
}

bool IsX(LIST list, int x)
{
	for (NODE* i = 0; i != NULL; i = i->pNext)
		if (i->data == x)
			return 1;
	return -1;
}

int FirstPosX(LIST list, int x)
{
	int i = 0;
	NODE* pNode = list.pHead;
	while (pNode)
	{
		if (pNode->data == x)
			return i;
		i++;
		pNode = pNode->pNext;
	}
	return -1;
}

int LastPosX(LIST list, int x)
{
	int i = 0;
	int kq = -1;
	NODE* pNode = list.pHead;
	while (pNode)
	{
		if (pNode->data == x)
			kq = i;
		i++;
		pNode = pNode->pNext;
	}
	return kq;
}

void AllPosX(LIST list, int x)
{
	if (!(IsX(list, x)))
	{
		cout << endl << x << " khong co trong danh sach!";
		return;
	}
	cout << endl << x << " xuat hien trong danh sach tai cac vi tri:\n";
	int i = 0;
	NODE* pNode = list.pHead;
	while (pNode)
	{
		if (pNode->data == x)
			cout << i << '\t';
		i++;
		pNode = pNode->pNext;
	}
}

NODE* LastNodeX(LIST list, int x)
{
	NODE* pNode, *xNode;
	xNode = NULL;
	pNode = list.pHead;
	while (pNode)
	{
		if (pNode->data == x)
			xNode = pNode;
		pNode = pNode->pNext;
	}
	return pNode;
}

int NewHead(LIST& list, int x)
{
	if (!list.pHead)
		return 0;
	NODE* pNode = LastNodeX(list, x);
	if (!pNode)
		return -1;
	NODE* i = NULL;
	list.pHead = pNode;
	do
	{
		i = pNode;
		pNode = pNode->pNext;
	} while (pNode);
	list.pTail = i;
	list.pTail->pNext = list.pHead;
	return 1;
}

void DelHead(LIST& list)
{
	NODE* pNode = list.pHead;
	if (!pNode)
		return;
	if (list.pHead == list.pTail)
		list.pHead = list.pTail = NULL;
	else
	{
		list.pHead = pNode->pNext;
		list.pTail->pNext = list.pHead;
	}
	delete pNode;
}

void DelTail(LIST& list)
{
	if (!list.pHead)
		return;
	if (!list.pTail)
		list.pHead = NULL;
	NODE* i = NULL;
	NODE* pNode = list.pHead;
	do
	{
		i = pNode;
		pNode = pNode->pNext;
	} while (pNode != list.pTail);
	list.pTail = i;
	list.pTail->pNext = list.pHead;
	delete pNode;
}

void DelList(LIST& list)
{
	if (!list.pHead)
		return;
	while (list.pHead)
	{
		NODE* pNode = list.pHead;
		list.pHead = list.pHead->pNext;
		delete pNode;
	}
}

int GetSize(LIST list)
{
	if (!list.pHead)
		return 0;
	int count = 0;
	NODE* pNode = list.pHead;
	while (pNode)
	{
		count++;
		pNode = pNode->pNext;
	}
	return count;
}

void Copy(LIST a, LIST& b)
{
	CreatList(b);
	if (!a.pHead)
		return;
	NODE* pNode = a.pHead;
	while (pNode)
	{
		AddTail(b, pNode->data);
		pNode = pNode->pNext;
	}
}