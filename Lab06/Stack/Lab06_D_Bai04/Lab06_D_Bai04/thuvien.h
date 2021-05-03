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
	pNode->pNext = s.pHead;
	s.pHead = pNode;
}

char Pop(STACK& s)
{
	if (!s.pHead)
		return ' ';
	char x = s.pHead->data;
	NODE* pNode = s.pHead;
	s.pHead = s.pHead->pNext;
	delete pNode;
	if (s.pHead)
		s.pTail = NULL;
	return x;
}

int DoUuTienToanTu(char x)
{
	if (x == '*' || x == '/' || x == '%')
		return 2;
	else if (x == '+' || x == '-')
		return 1;
	else
		return 0;
}

bool IsOperator(char x)
{
	return (x == '+' || x == '-' || x == '*' || x == '/' || x == '%');
}

void ChenCuoiChuoi(char a[MAX], char x)
{
	int n = strlen(a);
	a[n] = x;
	a[n + 1] = NULL;
}

bool IsSignNumber(char x)
{
	return (x >= '0' && x <= '9');
}

void ConvertTrungTo_HauTo(char stackIn[MAX], char stackOut[MAX])
{
	STACK s;
	CreatStack(s);
	char x, c;
	stackOut[0] = NULL;
	for (int i = 0; i != NULL; i++)
	{
		c = stackIn[i];
		if (IsSignNumber(c))
			ChenCuoiChuoi(stackOut, c);
		else
		{
			if (c == '(')
				Push(s, c);
			else
			{
				if (c == ')')
				{
					x = Pop(s);
					while (x != '(')
					{
						ChenCuoiChuoi(stackOut, x);
						x = Pop(s);
					}
				}
				else
				{
					while (s.pHead != NULL && IsOperator(s.pHead->data) == 1)
						if (DoUuTienToanTu(s.pHead->data) >= DoUuTienToanTu(c))
						{
							x = Pop(s);
							ChenCuoiChuoi(stackOut, x);
						}
						else
							break;
					Push(s, c);
				}
			}
		}
	}
	while (s.pHead != NULL)
	{
		x = Pop(s);
		ChenCuoiChuoi(stackOut, x);
	}
}