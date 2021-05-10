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
	int count = 0;
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

void SortedInsertionIncrease(NODE** j, NODE* i)
{
	// Trường hợp đặc biệt nếu j rỗng hoặc j là NODE cuối cùng
	// Chèn ở vị trí đầu tiên
	if (*j == NULL || (*j)->data >= i->data)
	{
		i->pNext = *j;
		*j = i;
	}
	else
	{
		// Xác định NODE trước điểm chèn
		NODE* k = *j;
		while (k->pNext != NULL && k->pNext->data < i->data)
		{
			k = k->pNext;
		}
		i->pNext = k->pNext;
		k->pNext = i;
	}
}

void SortedInsertionDecrease(NODE** j, NODE* i)
{
	// Trường hợp đặc biệt nếu j rỗng hoặc j là NODE cuối cùng
	// Chèn ở vị trí đầu tiên
	if (*j == NULL || (*j)->data <= i->data)
	{
		i->pNext = *j;
		*j = i;
	}
	else
	{
		// Xác định NODE trước điểm chèn
		NODE* k = *j;
		while (k->pNext != NULL && k->pNext->data > i->data)
		{
			k = k->pNext;
		}
		i->pNext = k->pNext;
		k->pNext = i;
	}
}

void InsertionSortIncrease(LIST& list)
{
	// Khởi tạo danh sách liên kết được sắp xếp
	NODE* j = NULL;

	// Duyệt qua danh sách liên kết đã cho và chèn mọi NODE để sắp xếp
	NODE* i = list.pHead;
	while (i != NULL)
	{
		// Xác định lại pNext cho lần lặp tiếp theo
		NODE* iNext = i->pNext;

		// Chèn i vào danh sách liên kết được sắp xếp
		SortedInsertionIncrease(&j, i);

		// Cập nhập i
		i = iNext;
	}
	// Cập nhật pHead để trỏ đến danh sách liên kết đã sắp xếp
	list.pHead = j;
}

void InsertionSortDecrease(LIST& list)
{
	// Khởi tạo danh sách liên kết được sắp xếp
	NODE* j = NULL;

	// Duyệt qua danh sách liên kết đã cho và chèn mọi NODE để sắp xếp
	NODE* i = list.pHead;
	while (i != NULL)
	{
		// Xác định lại pNext cho lần lặp tiếp theo
		NODE* iNext = i->pNext;

		// Chèn i vào danh sách liên kết được sắp xếp
		SortedInsertionDecrease(&j, i);

		// Cập nhập i
		i = iNext;
	}
	// Cập nhật pHead để trỏ đến danh sách liên kết đã sắp xếp
	list.pHead = j;
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
	InsertionSortIncrease(posList);

	LIST negList;
	NegativeElementList(list, negList);
	InsertionSortDecrease(negList);

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