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