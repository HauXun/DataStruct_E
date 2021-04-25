#define MAX 100

typedef int DaySo[MAX];

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
	if (pNode == NULL)
		return NULL;
	pNode->data = x;
	pNode->pNext = NULL;
	return pNode;
}

bool IsEmpty(LIST& list)
{
	if (list.pHead == NULL)
		return 1;
	return 0;
}

void AddHead(LIST& list, NODE* pNode)
{
	if (IsEmpty(list))
		list.pHead = list.pTail = pNode;
	pNode->pNext = list.pHead;
	list.pHead = pNode;
}

void InsertHead(LIST& list, int x)
{
	NODE* pNode = GetNode(x);
	if (pNode == NULL)
		return;
	AddHead(list, pNode);
}

void AddTail(LIST& list, NODE* pNode)
{
	if (IsEmpty(list))
		list.pHead = list.pTail = pNode;
	list.pTail->pNext = pNode;
	list.pTail = pNode;
}

void InsertTail(LIST& list, int x)
{
	NODE* pNode = GetNode(x);
	if (pNode == NULL)
		return;
	AddTail(list, pNode);
}

void Output(LIST list)
{
	cout << '\n';
	for (NODE* i = list.pHead; i != NULL; i = i->pNext)
		cout << '\t' << i->data;
	cout << '\n';
}

int FileReader(char* filename, LIST& list)
{
	int x;
	ifstream in(filename);
	if (!in)
		return 0;
	CreatList(list);
	while (!in.eof())
	{
		in >> x;
		InsertTail(list, x);
	}
	in.close();
	return 1;
}

void Copy(LIST& list2, LIST list)
{
	CreatList(list2);
	for (NODE* i = list.pHead; i != NULL; i = i->pNext)
		InsertTail(list2, i->data);
}

double TimMin(LIST list)
{
	double min = list.pHead->data;
	for (NODE* i = list.pHead; i != NULL; i = i->pNext)
		if (i->data < min)
			min = i->data;
	return min;
}

double TimMax(LIST list)
{
	double max = list.pHead->data;
	for (NODE* i = list.pHead; i != NULL; i = i->pNext)
		if (i->data > max)
			max = i->data;
	return max;
}

double TinhTong(LIST list)
{
	int sum = 0;
	for (NODE* i = list.pHead; i != NULL; i = i->pNext)
		sum += i->data;
	return sum;
}

int CountNumber(LIST list, int x)
{
	int count = 0;
	for (NODE* i = list.pHead; i != NULL; i = i->pNext)
	{
		if (i->data == x)
			count++;
	}
	return count;
}

bool Exist(LIST list, int x)
{
	for (NODE* i = list.pHead; i != NULL; i = i->pNext)
	{
		if (list.pHead == list.pTail)
			return false;
		if (i->data == x)
		{
			return true;
		}
	}
	return false;
}

void DifElement(LIST list, LIST& difList)
{
	for (NODE* i = list.pHead; i != NULL; i = i->pNext)
		if (!Exist(difList, i->data))
			InsertTail(difList, i->data);
}

double SumIfDif(LIST list)
{
	LIST listResult;
	CreatList(listResult);
	DifElement(list, listResult);
	double sum = 0;
	for (NODE* i = listResult.pHead; i != NULL; i = i->pNext)
		sum += i->data;
	return sum;
}

void DemSLXH(LIST& list)
{
	LIST listResult;
	CreatList(listResult);
	DifElement(list, listResult);
	int count;
	for (NODE* i = listResult.pHead; i != NULL; i = i->pNext)
	{
		int x = i->data;
		for (NODE* j = list.pHead; j != NULL; j = j->pNext)
		{
			count = CountNumber(list, x);
		}
		cout << " - So " << x << " xuat hien trong danh sach " << count << " lan" << endl;
	}
}

void SelectionSortIncrease(LIST& list)
{
	NODE* csMin;
	for (NODE* i = list.pHead; i != list.pTail; i = i->pNext)
	{
		csMin = i;
		for (NODE* j = i->pNext; j != NULL; j = j->pNext)
		{
			if (j->data < csMin->data)
				csMin = j;
		}
		swap(csMin->data, i->data);
	}
}

void SelectionSortDecrease(LIST& list)
{
	NODE* csMax;
	for (NODE* i = list.pHead; i != list.pTail; i = i->pNext)
	{
		csMax = i;
		for (NODE* j = i->pNext; j != NULL; j = j->pNext)
		{
			if (j->data > csMax->data)
				csMax = j;
		}
		swap(csMax->data, i->data);
	}
}

void PositiveElementList(LIST list, LIST& posList)
{
	CreatList(posList);
	for (NODE* i = list.pHead; i != NULL; i = i->pNext)
		if (i->data > 0)
			InsertTail(posList, i->data);
}

void NegativeElementList(LIST list, LIST& negList)
{
	CreatList(negList);
	for (NODE* i = list.pHead; i != NULL; i = i->pNext)
		if (i->data < 0)
			InsertTail(negList, i->data);
}

void ZeroElementList(LIST list, LIST& zeroList)
{
	CreatList(zeroList);
	for (NODE* i = list.pHead; i != NULL; i = i->pNext)
		if (i->data == 0)
			InsertTail(zeroList, i->data);
}

void Sort(LIST& list)
{
	LIST posList;
	PositiveElementList(list, posList);
	SelectionSortIncrease(posList);

	LIST negList;
	NegativeElementList(list, negList);
	SelectionSortDecrease(negList);

	LIST zeroList;
	ZeroElementList(list, zeroList);

	LIST listResult;
	CreatList(listResult);
	for (NODE* i = zeroList.pHead; i != NULL; i = i->pNext)
		InsertTail(listResult, i->data);
	for (NODE* i = negList.pHead; i != NULL; i = i->pNext)
		InsertTail(listResult, i->data);
	for (NODE* i = posList.pHead; i != NULL; i = i->pNext)
		InsertTail(listResult, i->data);
	Copy(list, listResult);
}