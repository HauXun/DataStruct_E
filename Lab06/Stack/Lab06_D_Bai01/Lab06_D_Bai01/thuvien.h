#include <iostream>

using namespace std;

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

void DelAll(STACK& s)
{
	if (IsEmpty(s))
		return;
	else
	{
		while (s.pTop)
		{
			NODE* pNode = s.pTop;
			s.pTop = s.pTop->pNext;
			delete pNode;
		}
	}
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

int CountNode(STACK& s, int x)
{
	int count = 0;
	for (NODE* i = s.pTop; i != NULL; i = i->pNext)
		if (i->data == x)
			count++;
	return count;
}

int FileReader(char* filename, STACK& s)
{
	ifstream in(filename);
	if (!in)
		return 0;
	KhoiTaoStack(s);
	int x;
	while (!in.eof())
	{
		in >> x;
		NODE* pNode = KhoiTaoNode(x);
		Push(s, pNode);
	}
	in.close();
	return 1;
}

void Output(STACK s)
{
	if (IsEmpty(s))
		cout << "\nDanh sach rong!";
	cout << '\n';
	for (NODE* i = s.pTop; i != NULL; i = i->pNext)
		cout << ' ' << i->data;
	cout << '\n';
}