#define MAX 100

struct NODE
{
	int data;
	NODE* pNext;
};

struct QUEUE
{
	NODE* pHead;
	NODE* pTail;
};

void CreatQueue(QUEUE& q)
{
	q.pHead = q.pTail = NULL;
}

NODE* GetNode(int x)
{
	NODE* pNode = new NODE;
	if (!pNode)
		return NULL;
	pNode->data = x;
	pNode->pNext = NULL;
	return pNode;
}

void Push(QUEUE& q, int x)
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

void EnQueue(QUEUE& q, int x)
{
	Push(q, x);
}

int DeQueue(QUEUE& q)
{
	if (!q.pHead)
		return ' ';
	NODE* pNode = q.pHead;
	int x = pNode->data;
	q.pHead = q.pHead->pNext;
	delete pNode;
	if (!q.pHead)
		q.pTail = NULL;
	return x;
}

void Output(QUEUE q)
{
	if (!q.pHead)
		cout << "\nDanh sach rong!";
	cout << '\n';
	for (NODE* i = q.pHead; i != NULL; i = i->pNext)
		cout << ' ' << i->data;
	cout << '\n';
}

void FileReader(char* filename, QUEUE& q)
{
	ifstream in(filename);
	if (!in)
		return;
	int x;
	while (!in.eof())
	{
		in >> x;
		EnQueue(q, x);
	}
	in.close();
}

void Radix(QUEUE& q)
{
	if (!q.pHead)
	{
		cout << "\nDanh sach rong!";
		return;
	}
	int csMax = q.pHead->data;
	for (NODE* i = q.pHead; i != NULL; i = i->pNext)
		if (i->data > csMax)
			csMax = i->data;
	int coSo = 0;
	while (csMax)
	{
		csMax /= 10;
		coSo++;
	}
	QUEUE q0, q1, q2, q3, q4, q5, q6, q7, q8, q9;
	CreatQueue(q0);
	CreatQueue(q1);
	CreatQueue(q2);
	CreatQueue(q3);
	CreatQueue(q4);
	CreatQueue(q5);
	CreatQueue(q6);
	CreatQueue(q7);
	CreatQueue(q8);
	CreatQueue(q9);
	for (int i = 0; i < coSo; i++)
	{
		while (q.pHead)
		{
			int thuongSo = q.pHead->data;
			int soDu;
			for (int j = 0; j <= i; j++)
			{
				soDu = thuongSo % 10;
				thuongSo /= 10;
			}
			switch (soDu)
			{
			case 0:
				EnQueue(q0, q.pHead->data);
				DeQueue(q);
				break;
			case 1:
				EnQueue(q1, q.pHead->data);
				DeQueue(q);
				break;
			case 2:
				EnQueue(q2, q.pHead->data);
				DeQueue(q);
				break;
			case 3:
				EnQueue(q3, q.pHead->data);
				DeQueue(q);
				break;
			case 4:
				EnQueue(q4, q.pHead->data);
				DeQueue(q);
				break;
			case 5:
				EnQueue(q5, q.pHead->data);
				DeQueue(q);
				break;
			case 6:
				EnQueue(q6, q.pHead->data);
				DeQueue(q);
				break;
			case 7:
				EnQueue(q7, q.pHead->data);
				DeQueue(q);
				break;
			case 8:
				EnQueue(q8, q.pHead->data);
				DeQueue(q);
				break;
			case 9:
				EnQueue(q9, q.pHead->data);
				DeQueue(q);
				break;
			}
		}
		while (q0.pHead != NULL)
		{
			EnQueue(q, q0.pHead->data);
			DeQueue(q0);
		}
		while (q1.pHead != NULL)
		{
			EnQueue(q, q1.pHead->data);
			DeQueue(q1);
		}
		while (q2.pHead != NULL)
		{
			EnQueue(q, q2.pHead->data);
			DeQueue(q2);
		}
		while (q3.pHead != NULL)
		{
			EnQueue(q, q3.pHead->data);
			DeQueue(q3);
		}
		while (q4.pHead != NULL)
		{
			EnQueue(q, q4.pHead->data);
			DeQueue(q4);
		}
		while (q5.pHead != NULL)
		{
			EnQueue(q, q5.pHead->data);
			DeQueue(q5);
		}
		while (q6.pHead != NULL)
		{
			EnQueue(q, q6.pHead->data);
			DeQueue(q6);
		}
		while (q7.pHead != NULL)
		{
			EnQueue(q, q7.pHead->data);
			DeQueue(q7);
		}
		while (q8.pHead != NULL)
		{
			EnQueue(q, q8.pHead->data);
			DeQueue(q8);
		}
		while (q9.pHead != NULL)
		{
			EnQueue(q, q9.pHead->data);
			DeQueue(q9);
		}
	}
}