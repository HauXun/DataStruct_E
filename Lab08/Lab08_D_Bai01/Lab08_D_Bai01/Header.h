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
	if (root)
	{
		cout << root->data << '\t';
		NLROrder(root->pLeft);
		NLROrder(root->pRight);
	}
}

void LNROrder(BSTree root)
{
	if (root)
	{
		LNROrder(root->pLeft);
		cout << root->data << '\t';
		LNROrder(root->pRight);
	}
}

void LRNOrder(BSTree root)
{
	if (root)
	{
		LRNOrder(root->pLeft);
		LRNOrder(root->pRight);
		cout << root->data << '\t';
	}
}