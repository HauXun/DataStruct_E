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
typedef struct NODELL* List;

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

NODELL* GetNODELL(LLNV x)
{
	NODELL* pNODE = new NODELL;
	if (!pNODE)
		exit(1);
	pNODE->data = x;
	pNODE->pNext = NULL;
	return pNODE;
}

NODECC* GetNODECC(CCNV x)
{
	NODECC* pNODE = new NODECC;
	if (!pNODE)
		exit(1);
	pNODE->data = x;
	pNODE->pNext = NULL;
	return pNODE;
}

void AddHeadLL(LISTLL& list, NODELL* pNODE)
{
	if (list.pHead == NULL)
		list.pHead = list.pTail = pNODE;
	pNODE->pNext = list.pHead;
	list.pHead = pNODE;
}

void InsertHeadLL(LISTLL& list, LLNV x)
{
	NODELL* pNODE = GetNODELL(x);
	if (pNODE == NULL)
		return;
	AddHeadLL(list, pNODE);
}

void AddTailLL(LISTLL& list, NODELL* pNODE)
{
	if (list.pHead == NULL)
		list.pHead = list.pTail = pNODE;
	list.pTail->pNext = pNODE;
	list.pTail = pNODE;
}

void AddTailLL_N(List& list, LLNV x)
{
	NODELL* pNODE = GetNODELL(x);
	if (!list)
		list = pNODE;
	else
	{
		NODELL* i = list;
		while (i->pNext)
		{
			i = i->pNext;
		}
		i->pNext = pNODE;
		i = pNODE;
	}
}

void InsertTailLL(LISTLL& list, LLNV x)
{
	NODELL* pNODE = GetNODELL(x);
	if (pNODE == NULL)
		return;
	AddTailLL(list, pNODE);
}

void InsertTailCC(LISTCC& list, CCNV x)
{
	NODECC* pNODE = GetNODECC(x);
	if (pNODE == NULL)
		return;
	if (list.pHead == NULL)
		list.pHead = list.pTail = pNODE;
	list.pTail->pNext = pNODE;
	list.pTail = pNODE;
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
	NODELL* iNODE = listLL.pHead;
	if (listLL.pHead == NULL)
		return;
	while (iNODE != NULL)
	{
		cout << '\n';
		cout << setiosflags(ios::left) << " "
			<< setw(10) << iNODE->data.maNV
			<< setw(19) << iNODE->data.hoTen
			<< setw(9) << setprecision(2) << setiosflags(ios::fixed) << iNODE->data.luongCB
			<< setw(9) << setprecision(2) << setiosflags(ios::fixed) << iNODE->data.luongPT
			<< setw(9) << setprecision(2) << setiosflags(ios::fixed) << iNODE->data.luongTL;
		iNODE = iNODE->pNext;
	}
	cout << '\n';
	for (int i = 0; i < 60; i++)
		cout << '=';
	cout << '\n';
}

void XuatBangLuongNV_N(List list)
{
	XuatTieuDe();
	while (list)
	{
		cout << '\n';
		cout << setiosflags(ios::left) << " "
			<< setw(10) << list->data.maNV
			<< setw(19) << list->data.hoTen
			<< setw(9) << setprecision(2) << setiosflags(ios::fixed) << list->data.luongCB
			<< setw(9) << setprecision(2) << setiosflags(ios::fixed) << list->data.luongPT
			<< setw(9) << setprecision(2) << setiosflags(ios::fixed) << list->data.luongTL;
		list = list->pNext;
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

// ============================== SẮP XẾP ====================================

// SELECTION SORT

void SortedInsertion(NODELL** j, NODELL* i)
{
	// Trường hợp đặc biệt nếu j rỗng hoặc j là NODE cuối cùng
	// Chèn ở vị trí đầu tiên
	if (*j == NULL || (*j)->data.luongTL >= i->data.luongTL)
	{
		i->pNext = *j;
		*j = i;
	}
	else
	{
		// Xác định NODE trước điểm chèn
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

	// Duyệt qua danh sách liên kết đã cho và chèn mọi NODE để sắp xếp
	NODELL* i = list.pHead;
	while (i != NULL)
	{
		// Xác định lại pNext cho lần lặp tiếp theo
		NODELL* iNext = i->pNext;

		// Chèn i vào danh sách liên kết được sắp xếp
		SortedInsertion(&j, i);

		// Cập nhập i
		i = iNext;
	}
	// Cập nhật pHead để trỏ đến danh sách liên kết đã sắp xếp
	list.pHead = j;
}


// BUBBLE SORT

void BubbleSort(LISTLL& list)
{
	NODELL* i = list.pHead;
	while (i->pNext != NULL)	// while (i && i.pNext != NULL)
	{
		NODELL* j = i->pNext;
		while (j != NULL)		// while (j)
		{
			if (i->data.luongTL > j->data.luongTL)
				swap(i->data, j->data);
			j = j->pNext;
		}
		i = i->pNext;
	}
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

//void BubbleSort(LISTLL& list)
//{
//	for (NODELL* i = list.pHead; i != NULL; i = i->pNext)
//		for (NODELL* j = i->pNext; j != NULL; j = j->pNext)
//			if (i->data.luongTL > j->data.luongTL)
//				swap(i->data, j->data);
//}


// FUNCTION

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

void Push(NODELL** head, LLNV data)
{
	NODELL* newNODE = (NODELL*)malloc(sizeof(NODELL));
	newNODE->data = data;
	newNODE->pNext = *head;
	*head = newNODE;
}

// Thêm một NODE mới vào danh sách theo thứ tự tăng dần
NODELL* InsertNODESorted(LISTLL& list, LLNV x)
{
	NODELL* pNODE = GetNODELL(x);
	NODELL* i = list.pHead;
	while ((i->pNext != NULL) && (i->pNext->data.luongTL < pNODE->data.luongTL))
	{
		i = i->pNext;
	}
	pNODE->pNext = i->pNext;
	i->pNext = pNODE;
	return pNODE;
}




// MERGE SORT

// ===============
// Sắp xếp một danh sách được liên kết nhất định bằng cách sử dụng thuật toán sắp xếp hợp nhất MergeSort
// Cách 1:

void MergeSort(NODELL** headList, LISTLL& list)
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
	MergeSort(&left, list);
	MergeSort(&right, list);

	// Sắp xếp danh sách
	*headList = SortedMerge(left, right);
	list.pHead = *headList;
}

// Chia đôi danh sách thành 2 nửa
// Nếu kích thước của danh sách là lẻ, thì phần tử phụ sẽ nằm trong danh sách đầu tiên.
// Hoặc nói cách khác
// Chia các nút của danh sách đã cho thành các nửa trước và sau và trả về hai danh sách bằng cách sử dụng các tham số tham chiếu.
// Nếu độ dài là lẻ, nút phụ sẽ nằm trong danh sách phía trước. Nó sử dụng chiến lược con trỏ left / right
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



// ==============
// Sắp xếp một danh sách được liên kết nhất định bằng cách sử dụng thuật toán sắp xếp hợp nhất MergeSort
// Cách 2:

// Trộn 2 danh sách đã sắp xếp thành danh sách sắp xếp
// Lần lượt kiểm tra 2 phần tử đầu của mỗi danh sách left và right
// Chọn lấy phần tử có giá trị nhỏ hơn chèn vào cuối danh sách left
// Thực hiện cho tới khi 1 trong 2 danh sách rỗng
NODELL* Merge(List left, List right)
{
	if (right == NULL)
		return left;
	if (left == NULL)
		return right;
	List list = NULL;
	if (left->data.luongTL < right->data.luongTL)
	{
		list = left;
		list->pNext = Merge(left->pNext, right);
	}
	else
	{
		list = right;
		list->pNext = Merge(left, right->pNext);
	}
	return list;
}

// Tìm phần tử middle (phần tử giữa của danh sách liên kết)
// Dùng 2 NODE để chạy là left và right, trong đó: left nhảy 1 lần và right nhảy 2 lần
// Khi right trỏ đến NULL (phần tử cuối cùng của danh sách) thì left chính là phần tử middle cần tìm
NODELL* getMid(List list)
{
	if (!list)
		return list;
	NODELL* left, * right;
	left = right = list;
	while (right->pNext && right->pNext->pNext)
	{
		left = left->pNext;
		right = right->pNext->pNext;
	}
	return left;
}

void Split(List list, List& list1, List& list2)
{
	NODELL* mid = getMid(list);
	list1 = list;
	list2 = mid->pNext;
	mid->pNext = NULL;
}

void mergeSort(List& list, LISTLL& listLL)
{
	List left = NULL;
	List right = NULL;

	// Điều kiện dừng
	// Danh sách rỗng hoặc danh sách chỉ có 1 NODE
	if (!list || !list->pNext)
		return;

	// Tách đôi danh sách cần sắp xếp thành 2 danh sách
	// Bao gồm 1 danh sách bên trái (left) và 1 danh sách bên phải (right)
	Split(list, left, right);

	// Gọi đệ quy mergeSort(left)
	mergeSort(left, listLL);
	// Gọi đệ quy mergeSort(right)
	mergeSort(right, listLL);

	// Trộn 2 danh sách left và right lại thành danh sách đã được sắp xếp hoàn chỉnh
	list = Merge(left, right);

	// Trả về danh sách kết quả hoàn chỉnh
	listLL.pHead = list;
}



// RADIX SORT

#pragma region Demo RadixSort LinkedList

// Hàm trả về số lớn nhất theo điều kiện nhất định (+ hoặc -)
float Max(LISTLL list)
{
	NODELL* i = list.pHead;
	float max = list.pHead->data.luongTL;
	while (i != NULL)
	{
		if (abs(i->data.luongTL) > max)
			max = abs(i->data.luongTL);
		i = i->pNext;
	}
	return max;
}

// Hàm trả về số mũ lũy thừa 10 tương ứng với chữ số có nghĩa nhất
int Expoment(float max)
{
	int count = 0;
	while (max != NULL)
	{
		max /= 10;
		count++;
	}
	return count - 1;
}

// Hàm trả về độ dài của 1 danh sách liên kết đơn
int Length(LISTLL list)
{
	NODELL* i = list.pHead;
	int count = 0;
	while (i != NULL)
	{
		i = i->pNext;
		count++;
	}
	return count;
}

// Hàm trả về phần đầu của một danh sách mới
NODELL* NewList(void)
{
	NODELL* newNODE = NULL;
	if ((newNODE = (struct NODELL*)malloc(sizeof(NODELL))) == NULL)
	{
		cout << "\nError, memory allocation failed.\n";
		exit(1);
	}
	newNODE->pNext = NULL;
	return newNODE;
}

// Hàm giải phóng(xóa) toàn bộ danh sách
void DeleteList(LISTLL& list)
{
	NODELL* i = NULL;
	while (list.pHead != NULL)
	{
		i = list.pHead;
		list.pHead = list.pHead->pNext;
		free(i);
	}
}

NODELL* radixSort(LISTLL& list)
{
	NODELL** ptrArray;
	NODELL* tempPtr;
	NODELL* headPtr = list.pHead;

	ptrArray = (struct NODELL**)malloc(sizeof(struct NODELL) * 10);

	for (int i = 0; i < 10; i++)
	{
		// Cấp phát cho các nhóm phần tử NODE đầu
		ptrArray[i] = NewList();
	}
	/* help
	in here */
	return NULL;
}

#pragma endregion

// Xác định cơ số
int CoSo(LISTLL list)
{
	NODELL* i = list.pHead;
	float max = 0;
	int coSo = 0;
	while (i != NULL)
	{
		if (i->data.luongTL > max)
			max = i->data.luongTL;
		i = i->pNext;
	}

	while (max != 0)
	{
		coSo++;
		max /= 10;
	}
	return coSo;
}

// Xác định thương số
int ThuongSo_Radix(int number, int k)
{
	int du;
	for (int i = 1; i <= k; i++)
	{
		du = number % 10;
		number /= 10;
	}
	return du;
}

void RadixSort(LISTLL& list)
{
	int minCoSo = 1;
	int maxCoSo = CoSo(list);
	int soDu;

	// Phần phía sau
	NODELL* rear[10];
	// Phần phía trước
	NODELL* front[10];

	int i;
	for (int coSo = minCoSo; coSo <= maxCoSo; coSo++)
	{
		for (i = 0; i <= 9; i++)
		{
			rear[i] = NULL;
			front[i] = NULL;
		}
		for (NODELL* j = list.pHead; j != NULL ; j = j->pNext)
		{
			soDu = ThuongSo_Radix(j->data.luongTL, coSo);
			if (front[soDu] == NULL)
				front[soDu] = j;
			else
				rear[soDu]->pNext = j;
			rear[soDu] = j;
		}
		i = 0;
		while (front[i] == NULL)
		{
			i++;
		}
		list.pHead = front[i];
		while (i < 9)
		{
			if (rear[i + 1] != NULL)
				rear[i]->pNext = front[i + 1];
			else
				rear[i + 1] = rear[i];
			i++;
		}
		rear[9]->pNext = NULL;
	}
}