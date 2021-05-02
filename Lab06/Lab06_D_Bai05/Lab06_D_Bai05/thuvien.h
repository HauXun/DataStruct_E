#define MAX 100


struct Node
{
	char data;
	Node* pNext;
};

typedef Node NODE;

struct STACK
{
	NODE* pHead;
	NODE* pTail;
};

NODE* GetNode(char x)
{
	NODE* p;
	p = new NODE;
	if (p != NULL)
	{
		p->data = x;
		p->pNext = NULL;
	}
	return p;
}

void CreatSTACK(STACK& s)
{
	s.pHead = s.pTail = NULL;
}

void Push(STACK& s, char x)
{
	Node* pNode = GetNode(x);
	if (!pNode)
		return;
	if (!s.pHead)
	{
		s.pHead = pNode;
		s.pTail = s.pHead;
	}
	else
	{
		pNode->pNext = s.pHead;
		s.pHead = pNode;
	}
}

char Pop(STACK& s)
{
	char x;
	Node* p;
	if (!s.pHead)
		return NULL;
	x = s.pHead->data;
	p = s.pHead;
	s.pHead = s.pHead->pNext;
	delete p;
	if (!s.pHead)
		s.pTail = NULL;
	return x;
}

bool LaToanTu(char c)
{
	return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%');
}

int LaKySo(char c)
{
	return (c >= '0' && c <= '9');
}

int So(char c)
{
	return c - '0';
}

int Tinh_BT_HauTo(char a[MAX])
{
	int i;
	char c;
	char x, y;
	STACK s;
	CreatSTACK(s);
	for (i = 0; a[i] != NULL; i++)
	{
		c = a[i];
		if (LaKySo(c))
		{
			x = So(c);
			Push(s, x);
		}
		else
		{
			x = Pop(s);
			y = Pop(s);
			switch (c)
			{
			case '+':
				Push(s, y + x);
				break;
			case '-':
				Push(s, y - x);
				break;
			case '*':
				Push(s, y * x);
				break;
			case '/':
				Push(s, y / x);
				break;
			case '%':
				Push(s, y % x);
				break;
			}
		}
	}
	return s.pHead->data;
}