#include <iostream>

using namespace std;

struct Node
{
	int data;
	Node* pNext;
};
typedef struct Node NODE;

struct Queue
{
	NODE* pHead;
	NODE* pTail;
};
typedef struct Queue QUEUE;

void KhoiTaoQueue(QUEUE& q)
{
	q.pHead = q.pTail = NULL;
}

NODE* KhoiTaoNode(int x)
{
	NODE* pNode = new NODE;
	if (!pNode)
		return NULL;
	pNode->data = x;
	pNode->pNext = NULL;
}

bool IsEmpty(QUEUE& q)
{
	return (q.pHead == NULL);
}

bool Push(QUEUE& q, NODE* pNode)
{
	if (!pNode)
		return false;
	if (IsEmpty(q))
		q.pHead = q.pTail = pNode;
	else
	{
		q.pTail->pNext = pNode;
		q.pTail = pNode;
	}
	return true;
}

void DelAll(QUEUE& q)
{
	if (IsEmpty(q))
		return;
	else
	{
		while (q.pHead)
		{
			NODE* pNode = q.pHead;
			q.pHead = q.pHead->pNext;
			delete pNode;
		}
	}
}

bool Pop(QUEUE& q, int& x)
{
	if (IsEmpty(q))
		return false;
	else
	{
		NODE* pNode = q.pHead;
		x = pNode->data;
		q.pHead = q.pHead->pNext;
		delete pNode;
	}
	return true;
}

bool Top(QUEUE& q, int& x)
{
	if (IsEmpty(q))
		return false;
	x = q.pHead->data;
	return true;
}

int CountNode(QUEUE& q, int x)
{
	int count = 0;
	for (NODE* i = q.pHead; i != NULL; i = i->pNext)
		if (i->data == x)
			count++;
	return count;
}

int FileReader(char* filename, QUEUE& q)
{
	ifstream in(filename);
	if (!in)
		return 0;
	KhoiTaoQueue(q);
	int x;
	while (!in.eof())
	{
		in >> x;
		NODE* pNode = KhoiTaoNode(x);
		Push(q, pNode);
	}
	in.close();
	return 1;
}

void Output(QUEUE q)
{
	if (IsEmpty(q))
		cout << "\nDanh sach rong!";
	cout << '\n';
	for (NODE* i = q.pHead; i != NULL; i = i->pNext)
		cout << ' ' << i->data;
	cout << '\n';
}