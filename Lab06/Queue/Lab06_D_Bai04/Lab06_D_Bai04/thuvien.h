struct Nhom
{
	char ns[5];
	int stt;
};
typedef struct Nhom DATA;

struct NODE
{
	DATA data;
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

NODE* GetNode(DATA x)
{
	NODE* pNode = new NODE;
	if (!pNode)
		return NULL;
	pNode->data = x;
	pNode->pNext = NULL;
	return pNode;
}

void Push(QUEUE& q, DATA x)
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

void EnQueue(QUEUE& q, DATA x)
{
	Push(q, x);
}

DATA DeQueue(QUEUE& q)
{
	NODE* pNode = q.pHead;
	DATA x;
	x = pNode->data;
	q.pHead = q.pHead->pNext;
	if (!q.pHead)
		q.pTail = NULL;
	return x;
}

void FileReader(char* filename, QUEUE& q)
{
	ifstream in(filename);
	if (!in)
		return;
	DATA x;
	while (!in.eof())
	{
		in >> x.ns;
		in >> x.stt;
		EnQueue(q, x);
	}
	in.close();
}

int SoNhom(QUEUE q)
{
	int sn = 0;
	if (!q.pHead)
		return sn;
	for (NODE* i = q.pHead; i != NULL; i = i->pNext)
		sn++;
	return sn;
}

void Output(QUEUE q)
{
	if (!q.pHead)
		cout << "\nDanh sach rong!";
	for (NODE* i = q.pHead; i != NULL; i = i->pNext)
		cout << i->data.ns << '\t' << i->data.stt << '\n';
}

void SapTang_TTruc(QUEUE& q)
{
	for (NODE* i = q.pHead; i != NULL; i = i->pNext)
		for (NODE* j = q.pHead; j != NULL; j = j->pNext)
			if (i->data.stt > j->data.stt)
				swap(i->data, j->data);
}

void XuatLichTruc(QUEUE& q, int day)
{
	DATA x;
	int vong = 1;
	int sn = SoNhom(q);
	SapTang_TTruc(q);
	cout << "\nVong " << vong << " :\n";
	for (int i = 0; i <= day; i++)
	{
		cout << setiosflags(ios::left);
		cout << setw(13) << "\nTruc ngay thu " << setw(4) << i << setw(10) << " la nhom: ";
		x = DeQueue(q);
		cout << setw(5);
		cout << x.ns;
		EnQueue(q, x);
		if (i % sn == 0)
		{
			cout << "\n========================";
			vong++;
			cout << "\nVong " << vong << ":\n";
		}
	}
	cout << '\n';
}