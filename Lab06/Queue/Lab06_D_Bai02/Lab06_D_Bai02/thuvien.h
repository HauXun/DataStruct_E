#define MAX 100

struct NODE
{
	char data;
	NODE* pNext;
};

struct QUEUE
{
	NODE* pHead;
	NODE* pTail;
};

NODE* GetNode(char x)
{
	NODE* pNode = new NODE;
	if (!pNode)
		return NULL;
	pNode->data = x;
	pNode->pNext = NULL;
	return pNode;
}

void CreatQueue(QUEUE& q)
{
	q.pHead = q.pTail = NULL;
}

bool IsEmpty(QUEUE q)
{
	return (!q.pHead);
}

void Push(QUEUE& q, char x)
{
	NODE* pNode = GetNode(x);
	if (!pNode)
		return;
	if (!q.pHead)
		q.pHead = q.pTail = pNode;
	else
	{
		q.pTail->pNext = pNode;
		q.pTail = pNode;
	}
}

void EnQueue(QUEUE& q, char x)
{
	Push(q, x);
}

char DeQueue(QUEUE& q)
{
	if (!q.pHead)
		return ' ';
	NODE* pNode = q.pHead;
	char x = pNode->data;
	q.pHead = q.pHead->pNext;
	delete pNode;
	if (!q.pHead)
		q.pTail = NULL;
	return x;
}

int FileReader(char* filename, char a[MAX])
{
	ifstream in(filename);
	if (!in)
		return 0;
	in >> a;
	in.close();
	return 1;
}

void Output(QUEUE q)
{
	if (!q.pHead)
		cout << "\nDanh sach rong";
	cout << '\n';
	for (NODE* i = q.pHead; i != NULL; i = i->pNext)
		cout << ' ' << i->data;
	cout << '\n';
}

void XuLyThaoTac(char a[MAX])
{
	QUEUE q;
	CreatQueue(q);
	char x;
	for (int i = 0; a[i] != NULL; i++)
	{
		x = a[i];
		if ('A' <= x && x <= 'Z')
		{
			EnQueue(q, x);
			Output(q);
		}
		else if (x == '*')
		{
			if (DeQueue(q))
				Output(q);
		}
	}
	cout << "\nKet qua sau khi thuc hien chuoi thao tac \"" << a << "\":\n";
	Output(q);
	cout << endl;
	_getch();
}