int DemSoNut(TREE root)
{
	if (!root)
		return 0;
	return 1 + DemSoNut(root->pLeft) + DemSoNut(root->pRight);
}

void XuatNhanVien(TREE& root)
{
	if (root != NULL)
	{
		if (_strcmpi(root->data.maNV, "LD19022") == 0)
			Xuat_1_NV(root->data);
		XuatNhanVien(root->pLeft);
		XuatNhanVien(root->pRight);
	}
}

void SuaNamSinh_DL23452(TREE& root)
{
	if (root)
	{
		TREE current = root;
		while (current)
		{
			if (_strcmpi(current->data.maNV, "LD18041") == 0)
				current->data.namSinh = 1990;
			if (_strcmpi(current->data.maNV, "LD18041") < 0)
				current = current->pRight;
			else
				current = current->pLeft;
		}
	}
}