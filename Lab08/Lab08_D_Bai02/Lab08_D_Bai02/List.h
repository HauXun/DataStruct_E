//List <-> Queue + Stack
//Kieu thanh phan du lieu cua cac nut trong Queue, stack la BSNode* <-> BSTree
//Kieu cac nut trong Queue, Stack
struct NODE
{
	BSTree data;
	NODE* pNext;
};

//Queeue, Stack
struct LIST
{
	NODE* pHead;
	NODE* pTail;
};

//Tao List rong (Queue, Stack)
void CreatList(LIST& list)
{
	list.pHead = list.pTail = NULL;
}

NODE* GetNode(BSTree data)
{
	NODE* pNode = new NODE;
	if (pNode)
	{
		pNode->data = data;
		pNode->pNext = NULL;
	}
	return pNode;
}

bool IsEmpty(LIST list)
{
	if (!list.pHead)
		return 1;
	return 0;
}

//Them dau, phuc vu cho Stack : Push
void InsertHead(LIST& list, BSTree data)
{
	NODE* pNode = GetNode(data);
	if (!pNode)
		return;
	if (!list.pHead)
		list.pHead = list.pTail = pNode;
	else
	{
		pNode->pNext = list.pHead;
		list.pHead = pNode;
	}
}

//Them cuoi : EnQueue -> phuc vu cho Queue
void InsertTail(LIST& list, BSTree data)
{
	NODE* pNode = GetNode(data);
	if (!pNode)
		return;
	if (!list.pHead)
		list.pHead = list.pTail = NULL;
	else
	{
		list.pTail->pNext = pNode;
		list.pTail = pNode;
		list.pTail->pNext = NULL;
	}
}

//Xoa dau, tra ve du lieu nut bi xoa : ->Phuc vu cho Queue, Stack : DeQueue , Pop
BSTree RemoveHead(LIST& list)
{
	if (!list.pHead)
		return NULL;
	else
	{
		NODE* pNode = list.pHead;
		BSTree x = pNode->data;
		list.pHead = list.pHead->pNext;
		delete pNode;
		return x;
	}
}

//----------------------------------------------
// Stack
//----------------------------------------------
//Xuat theo chieu sau : dung Stack
void DFS(BSTree root)
{
	LIST stack;
	CreatList(stack);
	NODE* pNode;
	BSTree pTree;
	if (!root)
		cout << "\n Cay rong!";
	else
	{
		pNode = GetNode(root);
		InsertHead(stack, pNode->data);
		do
		{
			pTree = RemoveHead(stack);
			cout << pTree->data << '\t';
			if (pTree->pLeft)
				DFS(pTree->pLeft);
			if (pTree->pRight)
			{
				pNode = GetNode(pTree->pRight);
				InsertHead(stack, pNode->data);
			}
		} while (IsEmpty(stack) == 0);
		cout << '\n';
	}
}

//----------------------------------------------
// Queue
//----------------------------------------------
//Xuat theo chieu rong (tung muc) : Dung Queue
void BFS(BSTree root)
{
	LIST queue;
	CreatList(queue);
	NODE* pNode;
	BSTree pTree;
	if (!root)
		cout << "\n Cay rong!";
	else
	{
		pNode = GetNode(root);
		InsertTail(queue, pNode->data);
		do
		{
			pTree = RemoveHead(queue);
			cout << pTree->data << '\t';
			if (pTree->pLeft)
			{
				pNode = GetNode(pTree->pLeft);
				InsertHead(queue, pNode->data);
			}
			if (pTree->pRight)
			{
				pNode = GetNode(pTree->pRight);
				InsertHead(queue, pNode->data);
			}
		} while (IsEmpty(queue) == 0);
		cout << '\n';
	}
}

//Xuat nut muc k
void BFS_TheoMuc_K(BSTree root, int k)
{
	LIST queue;
	CreatList(queue);
	NODE* pNode;
	BSTree pTree;
	if (!root)
		cout << "\n Cay rong!";
	else
	{
		pNode = GetNode(root);
		InsertTail(queue, pNode->data);
		do
		{
			pTree = RemoveHead(queue);
			if (TinhMuc_x(root, pTree->data) == k)
				cout << pTree->data << '\t';
			if (pTree->pLeft)
			{
				pNode = GetNode(pTree->pLeft);
				InsertHead(queue, pNode->data);
			}
			if (pTree->pRight)
			{
				pNode = GetNode(pTree->pRight);
				InsertHead(queue, pNode->data);
			}
		} while (IsEmpty(queue) == 0);
		cout << '\n';
	}
}

//Xuat theo muc
void BFS_TheoMuc(BSTree root)
{
	int h = TinhChieuCao(root);
	cout << "\n\nXuat BST theo chieu rong (tung muc):\n";
	for (int i = 0; i <= h; i++)
	{
		cout << endl << " Muc " << i << " : ";
		BFS_TheoMuc_K(root, i);
	}
}