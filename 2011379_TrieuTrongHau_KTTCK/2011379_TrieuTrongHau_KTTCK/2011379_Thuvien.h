void SuaTinChi_DL23452(TREE& root)
{
	if (root)
	{
		TREE current = root;
		while (current)
		{
			if (_strcmpi(current->data.maHV, "DL23452") == 0)
				current->data.tcTichLuy = 35;
			if (_strcmpi(current->data.maHV, "DL23452") < 0)
				current = current->pRight;
			else
				current = current->pLeft;
		}
	}
}

void XuatLopCTK36(TREE& root)
{
	if (root != NULL)
	{
		if (_strcmpi(root->data.lop, "CTK36") == 0)
			Xuat_1_HV(root->data);
		XuatLopCTK36(root->pLeft);
		XuatLopCTK36(root->pRight);
	}
}

void NodeThayThe(TREE& x, TREE& y)
{
	if (y->pRight)
		NodeThayThe(x, y->pRight);
	else
	{
		x->data = y->data;
		x = y;
		y = y->pLeft;
	}
}

int DeleteNode(TREE& root, char maHV[10])
{
	if (root != NULL)
	{
		if (_strcmpi(root->data.maHV, maHV) == 0)
		{
			NODE* x = root;
			if (!root->pLeft && !root->pRight)
				root = NULL;
			else if (!root->pLeft)
				root = root->pRight;
			else if (!root->pRight)
				root = root->pLeft;
			else
				NodeThayThe(x, root->pLeft);
			delete x;
			return 1;
		}
		else if (_strcmpi(root->data.maHV, maHV) > 0)
			return DeleteNode(root->pLeft, maHV);
		else
			return DeleteNode(root->pRight, maHV);
	}
	return 0;
}