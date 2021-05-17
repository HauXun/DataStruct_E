int TaoSoNgauNhien()
{
	int n;
	srand(time(NULL));
	n = rand() % 30 + 1;
	return n;
}

// Hàm trả về con trỏ đến node thứ n - 1
NODE* Node_pNode(LIST list, int n)
{
	int dem = 1; // Đếm node đã qua
	NODE* pNode = list.pHead;
	if (pNode)
	{
		while (dem < n - 1)
		{
			dem++;
			pNode = pNode->pNext;
		}
	}
	return pNode;
}

// Hủy node sau node q: hủy xong chuyển node kế tiếp là node đầu, q là node cuối
void RemoveNodeAfterpNode(LIST& list, NODE* q)
{
	if (!list.pHead)
	{
		cout << "\nDanh sach rong!";
		_getch();
		return;
	}
	NODE* pNode = q->pNext;
	q->pNext = pNode->pNext;
	delete pNode;

	list.pHead = q->pNext;
	if (!list.pHead)
		list.pTail = NULL;
	else if (list.pHead != list.pTail) // Không phải còn lại 1 node
		list.pTail = q;
}

int GetSize(LIST list)
{
	if (!list.pHead)
		return 0;
	int count = 0;
	NODE* pNode = list.pHead;
	while (pNode)
	{
		count++;
		pNode = pNode->pNext;
	}
	return count;
}

// Xuất các binh sĩ ra khỏi vòng, binh sĩ chọn đi cầu cứu
void CryForHelp(LIST list)
{
	int n = TaoSoNgauNhien();
	int size = GetSize(list);
	NODE* pNode;
	int lan = 0;
	cout << "\n So ngau nhien: n >> " << n;
	cout << "\n\t\tKET QUA TUYEN CHON\n";
	while (size > 1)
	{
		pNode = Node_pNode(list, n);	// Trỏ đến node thứ n - 1
		lan++;
		cout << setiosflags(ios::left);
		cout << setw(21) << "\nRa khoi vong lan thu " << setw(4) << lan << setw(13)
			<< " la binh si: " << pNode->pNext->data;
		RemoveNodeAfterpNode(list, pNode);
		size--;
	}
	cout << "\n\n\tBinh si duoc cu di cau cuu la >> " << list.pHead->data;
}