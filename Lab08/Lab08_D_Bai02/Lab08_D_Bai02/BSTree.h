struct BSNode
{
	int data;
	BSNode* pLeft;
	BSNode* pRight;
};
typedef BSNode* BSTree;

void CreatBST(BSTree& root)
{
	root = NULL;
}

BSNode* CreatNode(int x)
{
	BSNode* pNode = new BSNode;
	if (pNode)
	{
		pNode->data = x;
		pNode->pLeft = NULL;
		pNode->pRight = NULL;
	}
	return pNode;
}

int InsertNode(BSTree& root, int x)
{
	if (root)
	{
		if (root->data == x)
			return 0;
		else if (root->data > x)
			return InsertNode(root->pLeft, x);
		else
			return InsertNode(root->pRight, x);
	}
	root = CreatNode(x);
	if (!root)
		return -1;
	return 1;
}

int FileBST(BSTree& root, char* filename)
{
	ifstream in(filename);
	if (!in)
		return 0;
	int x;
	int kq;
	CreatBST(root);
	while (!in.eof())
	{
		in >> x;
		kq = InsertNode(root, x);
		if (kq == 0 || kq == -1)
			return 0;
	}
	in.close();
	return 1;
}

void NLROrder(BSTree root)
{
	if (root != NULL)
	{
		cout << root->data << "   ";
		NLROrder(root->pLeft);
		NLROrder(root->pRight);
	}
}

void LNROrder(BSTree root)
{
	if (root != NULL)
	{
		LNROrder(root->pLeft);
		cout << root->data << "   ";
		LNROrder(root->pRight);
	}
}

void LRNOrder(BSTree root)
{
	if (root != NULL)
	{
		LRNOrder(root->pLeft);
		LRNOrder(root->pRight);
		cout << root->data << "   ";
	}
}

int TinhMax(int a, int b)
{
	return a >= b ? a : b;
}

int TinhChieuCao(BSTree root)
{
	int h;
	if (!root)
		h = -1;
	else if (!root->pLeft && !root->pRight)
		h = 0;
	else
		h = 1 + TinhMax(TinhChieuCao(root->pLeft), TinhChieuCao(root->pRight));
	return h;
}

int TinhMuc_x(BSTree root, int x)
{
	int muc = 0;
	BSTree t = root;
	while (t)
	{
		if (t->data == x)
			return muc;
		else
		{
			muc++;
			if (t->data > x)
				t = t->pLeft;
			else
				t = t->pRight;
		}
	}
	return 0;
}