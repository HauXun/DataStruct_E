struct Node
{
	int data;
	Node* pNext;
};
typedef struct Node NODE;

struct Stack
{
	NODE* pTop;
};
typedef struct Stack STACK;

void KhoiTaoStack(STACK& s)
{
	s.pTop = NULL;
}

NODE* KhoiTaoNode(int x)
{
	NODE* pNode = new NODE;
	if (!pNode)
		return NULL;
	pNode->data = x;
	pNode->pNext = NULL;
}

bool IsEmpty(STACK& s)
{
	return (s.pTop == NULL);
}

bool Push(STACK& s, NODE* pNode)
{
	if (!pNode)
		return false;
	if (IsEmpty(s))
		s.pTop = pNode;
	else
	{
		pNode->pNext = s.pTop;
		s.pTop = pNode;
	}
	return true;
}

bool Pop(STACK& s, int& x)
{
	if (IsEmpty(s))
		return false;
	else
	{
		NODE* pNode = s.pTop;
		x = pNode->data;
		s.pTop = s.pTop->pNext;
		delete pNode;
	}
	return true;
}

bool Top(STACK& s, int& x)
{
	if (IsEmpty(s))
		return false;
	x = s.pTop->data;
	return true;
}

void Input(STACK& s)
{
	int n;
	cout << "\nNhap so luong phan tu cua Stack >> ";
	cin >> n;
	srand(365);
	for (int i = 0; i < n; i++)
	{
		NODE* pNode = KhoiTaoNode(rand() % 10);
		Push(s, pNode);
	}
}

void DoiCoSo(STACK& s, int coSo, int heThapPhan)
{
	while (heThapPhan)
	{
		int x = heThapPhan % coSo;
		NODE* pNode = KhoiTaoNode(x);
		Push(s, pNode);
		heThapPhan /= coSo;
	}
}

void Output(STACK s)
{
	cout << '\n';
	while (!IsEmpty(s))
	{
		int x;
		Pop(s, x);
		if (x < 10)
			cout << ' ' << x;
		else
		{
			switch (x)
			{
			case 10:
				cout << ' ' << 'A';
				break;
			case 11:
				cout << ' ' << 'B';
				break;
			case 12:
				cout << ' ' << 'C';
				break;
			case 13:
				cout << ' ' << 'D';
				break;
			case 14:
				cout << ' ' << 'E';
				break;
			case 15:
				cout << ' ' << 'F';
				break;
			}
		}
	}
	cout << '\n';
	if (IsEmpty(s))
		cout << "\nDanh sach hien tai rong!";
	else
		cout << "\nDanh sach con phan tu!";
}