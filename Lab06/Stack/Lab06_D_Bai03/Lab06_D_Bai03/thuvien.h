#define MAX 100

struct NODE
{
	char data;
	NODE* pNext;
};

struct STACK
{
	NODE* pHead;
	NODE* pTail;
};

NODE* GetNode(char x)
{
	NODE* pNode = new NODE;
	if (!pNode)
		return NULL;
	else
	{
		pNode->data = x;
		pNode->pNext = NULL;
	}
}

void CreatStack(STACK& s)
{
	s.pHead = s.pTail = NULL;
}

void Push(STACK& s, char x)
{
	NODE* pNode = GetNode(x);
	if (!pNode)
		return;
	if (!s.pHead)
		s.pHead = s.pTail = pNode;
	else
	{
		pNode->pNext = s.pHead;
		s.pHead = pNode;
	}
}

void Input(STACK& s)
{
	int n;
	cout << "\nNhap vao so luong phan tu cua stack >> ";
	cin >> n;
	srand(time(NULL));
	for (int i = 0; i < n; i++)
		Push(s, ((char)rand() % (126 - 32 + 1) + 32));
}

void Output(STACK s)
{
	cout << '\n';
	if (!s.pHead)
		cout << "\nDanh sach rong!";
	for (NODE* i = s.pHead; i != NULL; i = i->pNext)
		cout << ' ' << i->data;
	cout << '\n';
}

void ChepChuoiSangStack(STACK& s, char x[MAX])
{
	CreatStack(s);
	if (!x[0])
		return;
	for (int i = 0; i != NULL; i++)
		Push(s, x[i]);
}

void ChepStackSangChuoi(STACK s, char y[MAX])
{
	y[0] = NULL;
	if (!s.pHead)
		return;
	else
	{
		NODE* pNode = s.pHead;
		int i = 0;
		while (pNode)
		{
			y[i++] = pNode->data;
			pNode = pNode->pNext;
		}
		y[i] = NULL;
	}
}