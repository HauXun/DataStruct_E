void XuatHocVien_Lop(TREE& root, char lop[15])
{
	if (root != NULL)
	{
		if (_strcmpi(root->data.lop, lop) == 0)
			Xuat_1_HV(root->data);
		XuatHocVien_Lop(root->pLeft, lop);
		XuatHocVien_Lop(root->pRight, lop);
	}
}