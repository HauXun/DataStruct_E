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

NODE* GetNode(int data)
{
	NODE* pNode = new NODE;
	if (!pNode)
		return NULL;
	pNode->data = data;
	pNode->pNext = NULL;
	return pNode;
}

bool IsEmpty(LIST list)
{
	if (list.pHead == NULL)
		return true;
	return false;
}

void InsertTail(LIST& list, int data)
{
	NODE* pNode = GetNode(data);
	if (!pNode)
		return;
	if (IsEmpty(list))
		list.pHead = list.pTail = pNode;
	else
	{
		list.pTail->pNext = pNode;
		list.pTail = pNode;
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
		InsertTail(list, x);
	}
	in.close();
	return 1;
}

void Output(LIST list)
{
	NODE* pNode = list.pHead;
	if (IsEmpty(list))
		return;
	cout << "{ ";
	while (pNode)
	{
		cout << pNode->data;
		pNode = pNode->pNext;
		if (pNode)
			cout << ", ";
	}
	cout << " }\n";
}

bool CheckDependent(LIST list, int x)
{
	NODE* pNode = list.pHead;
	while (pNode)
	{
		if (pNode->data == x)
			return true;
		pNode = pNode->pNext;
	}
	return false;
}

void Copy(LIST& b, LIST a)
{
	NODE* pNode = a.pHead;
	while (pNode)
	{
		InsertTail(b, pNode->data);
		pNode = pNode->pNext;
	}
}

LIST Giao2TapHop(LIST a, LIST b)
{
	LIST result;
	CreatList(result);
	NODE* pNode = a.pHead;
	while (pNode)
	{
		if (CheckDependent(b, pNode->data))
			InsertTail(result, pNode->data);
		pNode = pNode->pNext;
	}
	return result;
}

LIST Hop2TapHop(LIST a, LIST b)
{
	LIST result;
	CreatList(result);
	Copy(result, a);
	NODE* pNode = b.pHead;
	while (pNode)
	{
		if (!CheckDependent(a, pNode->data))
			InsertTail(result, pNode->data);
		pNode = pNode->pNext;
	}
	return result;
}

LIST Hieu2TapHop(LIST a, LIST b)
{
	LIST result;
	CreatList(result);
	NODE* pNode = a.pHead;
	while (pNode)
	{
		if (!CheckDependent(b, pNode->data))
			InsertTail(result, pNode->data);
		pNode = pNode->pNext;
	}
	return result;
}

LIST HieuDanhSach2TapHop(LIST a, LIST b)
{
	LIST result, D, E;
	CreatList(result);
	CreatList(D);
	CreatList(E);
	D = Hieu2TapHop(a, b);
	E = Hieu2TapHop(b, a);
	result = Hop2TapHop(D, E);
	return result;
}

void TichDescrates(LIST a, LIST b)
{
	int i = 0;
	if (!a.pHead || !b.pHead)
		return;
	cout << "{ ";
	NODE* pNode = a.pHead;
	while (pNode)
	{
		i++;
		if ((i + 1) % 2 == 0)
			cout << '\n';
		NODE* kNode = b.pHead;
		while (kNode)
		{
			cout << '(' << pNode->data << ',' << kNode->data << ')';
			if (pNode != a.pHead && kNode != b.pTail)
				cout << ", ";
			kNode = kNode->pNext;
		}
		pNode = pNode->pNext;
	}
	cout << "} ";
}

int RelationshipTest(LIST a, LIST b)
{
	NODE* pNode = a.pHead;
	int result = -1;
	while (pNode)
	{
		if (!CheckDependent(b, pNode->data))
			result = 0;
		pNode = pNode->pNext;
	}
	return result;
}

int LucLuongTapHop(LIST list)
{
	int result = 0;
	NODE* pNode = list.pHead;
	if (!pNode)
		return 0;
	while (pNode)
	{
		result++;
		pNode = pNode->pNext;
	}
	return result;
}