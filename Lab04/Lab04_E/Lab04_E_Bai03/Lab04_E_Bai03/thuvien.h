struct LLNV
{
	char maNV[8];
	char hoTen[15];
	char diaChi[15];
	unsigned TDVH;
	int luongCB;
	int luongPT;
	int luongTL;
};

struct CCNV
{
	char maNV[8];
	unsigned nghiKP;
	unsigned nghiCP;
	unsigned ngayLT;
};

struct NODELL
{
	LLNV data;
	NODELL* pNext;
};

struct LISTLL
{
	NODELL* pHead;
	NODELL* pTail;
};

struct NODECC
{
	CCNV data;
	NODECC* pNext;
};

struct LISTCC
{
	NODECC* pHead;
	NODECC* pTail;
};

void CreatListLL(LISTLL& list)
{
	list.pHead = list.pTail = NULL;
}

void CreatListCC(LISTCC& list)
{
	list.pHead = list.pTail = NULL;
}

NODELL* GetNodeLL(LLNV x)
{
	NODELL* pNode = new NODELL;
	if (pNode == NULL)
		return NULL;
	pNode->data = x;
	pNode->pNext = NULL;
}

NODECC* GetNodeCC(CCNV x)
{
	NODECC* pNode = new NODECC;
	if (pNode == NULL)
		return NULL;
	pNode->data = x;
	pNode->pNext = NULL;
}

void AddHeadLL(LISTLL& list, NODELL* pNode)
{
	if (list.pHead == NULL)
		list.pHead = list.pTail = pNode;
	pNode->pNext = list.pHead;
	list.pHead = pNode;
}

void InsertHeadLL(LISTLL& list, LLNV x)
{
	NODELL* pNode = GetNodeLL(x);
	if (pNode == NULL)
		return;
	AddHeadLL(list, pNode);
}

void AddTailLL(LISTLL& list, NODELL* pNode)
{
	if (list.pHead == NULL)
		list.pHead = list.pTail = pNode;
	list.pTail->pNext = pNode;
	list.pTail = pNode;
}

void InsertTailLL(LISTLL& list, LLNV x)
{
	NODELL* pNode = GetNodeLL(x);
	if (pNode == NULL)
		return;
	AddTailLL(list, pNode);
}

void InsertTailCC(LISTCC& list, CCNV x)
{
	NODECC* pNode = GetNodeCC(x);
	if (pNode == NULL)
		return;
	if (list.pHead == NULL)
		list.pHead = list.pTail = pNode;
	list.pTail->pNext = pNode;
	list.pTail = pNode;
}

void SplitList(NODELL* headList, NODELL** leftRef, NODELL** rightRef);
NODELL* SortedMerge(NODELL* left, NODELL* right);

void FileReaderLL(char* filename, LISTLL& list)
{
	int luongPT;
	LLNV x;

	ifstream in(filename);
	if (!in)
	{
		cout << "\nLoi mo file!\n";
		_getch();
		return;
	}
	CreatListLL(list);
	while (!in.eof())
	{
		in >> x.maNV;
		in >> x.hoTen;
		in >> x.diaChi;
		in >> x.TDVH;
		in >> x.luongCB;

		luongPT = 0;
		if (x.luongCB == 5)
			luongPT = 10 * x.luongCB / 100;
		else if (x.TDVH == 6)
			luongPT = 20 * x.luongCB / 100;
		x.luongPT = luongPT;
		x.luongTL = 0;
		InsertTailLL(list, x);
	}
	in.close();
}

void FileReaderCC(char* filename, LISTCC& listCC, LISTLL listLL)
{
	CCNV x;
	NODELL* i = listLL.pHead;
	ifstream in(filename);
	if (!in)
	{
		cout << "\nLoi mo file!\n";
		_getch();
		return;
	}
	CreatListCC(listCC);
	while (!in.eof())
	{
		in >> x.maNV;
		in >> x.nghiCP;
		in >> x.nghiKP;
		in >> x.ngayLT;

		if (_strcmpi(i->data.maNV, x.maNV) != 0)
		{
			cout << "\nLoi thu tu ma nhan vien dan den khong the doc file! Vui long kiem tra lai cac file du lieu...\n";
			_getch();
			return;
		}
		InsertTailCC(listCC, x);

		i->data.luongPT += x.ngayLT * 4 * i->data.luongCB / 100;
		i->data.luongPT -= x.nghiKP * 4 * i->data.luongCB / 100;
		if (x.nghiCP >= 15)
			i->data.luongPT -= 10 * i->data.luongCB / 100;
		i->data.luongTL = i->data.luongCB + i->data.luongPT;
		i = i->pNext;
	}
	in.close();
}


void XuatTieuDe()
{
	cout << '\n';
	for (int i = 0; i < 60; i++)
		cout << '=';
	cout << '\n';
	cout << setiosflags(ios::left) << " "
		<< setw(10) << "Ma NV"
		<< setw(19) << "Ho va ten"
		<< setw(9) << "Luong CB"
		<< setw(9) << "Phu troi"
		<< setw(9) << "Luong TL";
	cout << '\n';
	for (int i = 0; i < 60; i++)
		cout << '=';
}

void XuatBangLuongNV(LISTLL listLL)
{
	XuatTieuDe();
	NODELL* iNode = listLL.pHead;
	while (iNode != NULL)
	{
		cout << '\n';
		cout << setiosflags(ios::left) << " "
			<< setw(10) << iNode->data.maNV
			<< setw(19) << iNode->data.hoTen
			<< setw(9) << setprecision(2) << setiosflags(ios::fixed) << iNode->data.luongCB
			<< setw(9) << setprecision(2) << setiosflags(ios::fixed) << iNode->data.luongPT
			<< setw(9) << setprecision(2) << setiosflags(ios::fixed) << iNode->data.luongTL;
		iNode = iNode->pNext;
	}
	cout << '\n';
	for (int i = 0; i < 60; i++)
		cout << '=';
	cout << '\n';
}

void SelectionSort(LISTLL& list)
{
	NODELL* csMin;
	for (NODELL* i = list.pHead; i != list.pTail; i = i->pNext)
	{
		csMin = i;
		for (NODELL* j = i->pNext; j != NULL; j = j->pNext)
		{
			if (j->data.luongTL < csMin->data.luongTL)
				csMin = j;
		}
		swap(csMin->data, i->data);
	}
}

// Chức năng sắp xếp một danh sách liên kết đơn bằng cách sử dụng sắp xếp chèn Insertion

// Chức năng chèn một nút mới trong danh sách. 
// Lưu ý rằng hàm này chờ một con trỏ trỏ tới j
// vì điều này có thể sửa đổi phần đầu của danh sách liên kết đầu vào (tương tự như push ())
void SortedInsertion(NODELL** j, NODELL* i)
{
	// Trường hợp đặc biệt nếu j rỗng hoặc j là node cuối cùng
	// Chèn ở vị trí đầu tiên
	if (*j == NULL || (*j)->data.luongTL >= i->data.luongTL)
	{
		i->pNext = *j;
		*j = i;
	}
	else
	{
		// Xác định node trước điểm chèn
		NODELL* k = *j;
		while (k->pNext != NULL && k->pNext->data.luongTL < i->data.luongTL)
		{
			k = k->pNext;
		}
		i->pNext = k->pNext;
		k->pNext = i;
	}
}

void InsertionSort(LISTLL& list)
{
	// Khởi tạo danh sách liên kết được sắp xếp
	NODELL* j = NULL;

	// Duyệt qua danh sách liên kết đã cho và chèn mọi node để sắp xếp
	NODELL* i = list.pHead;
	while (i != NULL)
	{
		// Xác định lại pNext cho lần lặp tiếp theo
		NODELL* iNext = i->pNext;

		// Chèn i vào danh sách liên kết được sắp xếp
		SortedInsertion(&j, i);

		// Cập nhâp i
		i = iNext;
	}
	// Cập nhật pHead để trỏ đến danh sách liên kết đã sắp xếp
	list.pHead = j;
}

//void BubbleSort(LISTLL& list)
//{
//	NODELL* i = list.pHead;
//	int temp;
//	while (i->pNext != NULL)	// while (i && i.pNext != NULL)
//	{
//		NODELL* j = i->pNext;
//		while (j != NULL)		// while (j)
//		{
//			if (i->data.luongTL > j->data.luongTL)
//				swap(i->data, j->data);
//			j = j->pNext;
//		}
//		i = i->pNext;
//	}
//}

void BubbleSort(LISTLL& list)
{
	for (NODELL* i = list.pHead; i != NULL; i = i->pNext)
		for (NODELL* j = i->pNext; j != NULL; j = j->pNext)
			if (i->data.luongTL > j->data.luongTL)
				swap(i->data, j->data);
}

//void BubbleSort(LISTLL& list)
//{
//	NODELL* i = list.pHead;
//	NODELL* j = list.pHead;
//	while (i != NULL)
//	{
//		while (j->pNext != NULL)
//		{
//			if (i->data.luongTL > j->data.luongTL)
//				swap(i->data, j->data);
//			j = j->pNext;
//		}
//		j = list.pHead;
//		i = i->pNext;
//	}
//}

// Sắp xếp một danh sách được liên kết nhất định bằng cách sử dụng thuật toán sắp xếp hợp nhất MergeSort
void MergeSort(NODELL** headList)
{
	// Temp 1:
	// Trường hợp cơ sở - Kích thước 0 hoặc 1
	NODELL* head = *headList;
	if (head == NULL || head->pNext == NULL)
		return;

	// Temp 2:	
	// Trường hợp cơ sở - Kích thước 0 hoặc 1
	if (*headList == NULL || (*headList)->pNext == NULL)
		return;

	NODELL* left;
	NODELL* right;
	
	// Chia danh sách ra thành 2 danh sách phụ là left và right
	SplitList(*headList, &left, &right);

	// Sắp xếp đệ quy hai danh sách.
	// Sắp xếp các danh sách con
	MergeSort(&left);
	MergeSort(&right);

	// Sắp xếp danh sách
	*headList = SortedMerge(left, right);
}

// Chia đôi danh sách thành 2 nửa
// Nếu kích thước của danh sách là lẻ, thì phần tử phụ sẽ nằm trong danh sách đầu tiên.
// Hoặc nói cách khác
// Chia các nút của danh sách đã cho thành các nửa trước và sau và trả về hai danh sách bằng cách sử dụng các tham số tham chiếu.
// Nếu độ dài là lẻ, nút phụ sẽ nằm trong danh sách phía trước. Nó sử dụng chiến lược con trỏ nhanh / chậm
void SplitList(NODELL* headList, NODELL** leftRef, NODELL** rightRef)
{
	// Nếu chiều dài nhỏ hơn 2, xử lý riêng
	if (headList == NULL || headList->pNext == NULL)
	{
		*leftRef = headList;
		*rightRef = NULL;
		return;
	}

	NODELL* left;
	NODELL* right;
	left = headList;
	right = headList->pNext;

	// right được tăng 2 lần và left được tăng 1 lần
	// Hiểu đơn giản là
	// right tiến 2 bước và left tiến 1 bước
	while (right != NULL)
	{
		right = right->pNext;
		if (right != NULL)
		{
			left = left->pNext;
			right = right->pNext;
		}
	}

	// left nằm ở điểm giữa
	// left nằm trước điểm giữa trong danh sách vì vậy hãy chia nó ra làm 2 tại điểm đó
	*leftRef = headList;
	*rightRef = left->pNext;
	left->pNext = NULL;
}

// Hợp nhất hai danh sách đã sắp xếp
// Lấy hai danh sách được sắp xếp theo thứ tự tăng dần và hợp nhất các nút của chúng
// để tạo thành một danh sách lớn được sắp xếp, danh sách này được trả về
NODELL* SortedMerge(NODELL* left, NODELL* right)
{
	NODELL* result = NULL;

	// Trường hợp cơ sở
	if (left == NULL) return right;

	if (right == NULL) return left;

	// Sử dụng đệ quy hợp nhất 2 danh sách lại
	// Chọn left hoặc right và lặp lại
	if (left->data.luongTL <= right->data.luongTL)
	{
		result = left;
		result->pNext = SortedMerge(left->pNext, right);
	}
	else
	{
		result = right;
		result->pNext = SortedMerge(left, right->pNext);
	}
	return result;
}

void Copy(LISTLL& listLL2, LISTLL listLL)
{
	CreatListLL(listLL2);
	LLNV x;
	for (NODELL* i = listLL.pHead; i != NULL; i = i->pNext)
	{
		x = i->data;
		InsertTailLL(listLL2, x);
	}
}

//void Copy2(NODELL** head, LISTLL listLL)
//{
//	LLNV x;
//	for (NODELL* i = listLL.pHead; i != NULL; i = i->pNext)
//	{
//		x = i->data;
//		Push(&head, x);
//	}
//}

void Push(NODELL** head, LLNV data)
{
	NODELL* newNode = (NODELL*)malloc(sizeof(NODELL));
	newNode->data = data;
	newNode->pNext = *head;
	*head = newNode;
}