int DemSoNut(BSTree root)
{
	if (!root)
		return 0;
	return 1 + DemSoNut(root->pLeft) + DemSoNut(root->pRight);
}

int DemNodeNhoHonX(BSTree root, int x)
{
	int soNut;
	if (!root)
		soNut = 0;
	// Nếu nút hiện tại có giá trị nhỏ hơn x, tăng giá trị soNut lên 1
	else if (root->data < x)
	{
		cout << root->data << '\t';
		soNut = 1 + DemNodeNhoHonX(root->pLeft, x) + DemNodeNhoHonX(root->pRight, x);
	}
	else
		soNut = DemNodeNhoHonX(root->pLeft, x) + DemNodeNhoHonX(root->pRight, x);
	return soNut;
}

BSTree TimKiem_VongLap(int x, BSTree root)
{
	if (root)
	{
		BSTree current = root;
		while (current)
		{
			if (current->data == x)
				return current;
			else if (x > current->data)
				current = current->pRight;
			else
				current = current->pLeft;
		}
	}
	return NULL;
}

BSTree TimKiem_DeQuy(int x, BSTree root)
{
	if (root)
	{
		if (root->data == x)
			return root;
		else if (root->data < x)
			return TimKiem_DeQuy(x, root->pRight);
		else
			return TimKiem_DeQuy(x, root->pLeft);
	}
	return NULL;
}

// Nút lá là nút không có nhánh con nào hết
int IsLeaf_x(BSTree root, int x)
{
	int kq = 0;
	BSTree t = TimKiem_DeQuy(x, root);
	if (!t)
		kq = -1;
	else
		kq = (!t->pLeft) && (!t->pRight);
	return kq;
}

int DemNutLa(BSTree root)
{
	int soNutLa;
	if (!root)
		soNutLa = 0;
	// Nếu nút đang xét không có nhánh con, thì nút đó là nút lá
	else if (!root->pRight && !root->pLeft)
	{
		cout << root->data << '\t';
		soNutLa = 1;
	}
	else	// Nếu nút đó có nhánh, thì tìm tất cả các nhánh con của nút đó
		soNutLa = DemNutLa(root->pLeft) + DemNutLa(root->pRight);
	return soNutLa;
}

int TinhMax(int a, int b)
{
	return a > b ? a : b;
}

int TinhChieuCao(BSTree root)
{
	int h;
	if (!root)
		h = -1;
	// Không tính nút gốc
	else if (!root->pLeft && !root->pRight)
		h = 0;
	else	// Tìm nhánh nào dài hơn làm chiều cao của cây
		h = 1 + TinhMax(TinhChieuCao(root->pLeft), TinhChieuCao(root->pRight));	// Từ nút gốc trở đi, cứ mỗi nút trong nhánh thì tăng chiều cao lên 1
	return h;
}

// Tìm mức cấp độ (level) của nút bằng vòng lặp
int TimMuc_x_VongLap(BSTree root, int x)
{
	int muc = 0;
	BSTree current = root;
	if (!current)
		return -1;
	while (current)
	{
		if (current->data == x)
			return muc;
		else
		{
			muc++;
			if (current->data > x)
				current = current->pLeft;
			else
				current = current->pRight;
		}
	}
	return 0;
}

// Tìm mức cấp độ (level) của nút bằng đệ quy
int TimMuc_x_DeQuy(BSTree root, int x)
{
	int muc;
	if (!root)
		return -1;
	else if (!root->pLeft && !root->pRight)
		return 0;
	else if (root->data != x)
		// Điều kiện dừng (neo) là nếu giá trị của nút bằng với x
		muc = 1 + TimMuc_x_DeQuy(root->pLeft, x) + TimMuc_x_DeQuy(root->pRight, x);
	return muc;
}

// Trả về 0 nếu hai nút có cùng mức, 1 nếu mức x > mức y, -1 nếu mức x < mức y
int SoSanhMuc(BSTree root, int x, int y)
{
	int kq1, kq2;
	kq1 = TimMuc_x_VongLap(root, x);
	kq2 = TimMuc_x_VongLap(root, y);
	if (kq1 > kq2)
		return 1;
	else if (kq1 < kq2)
		return -1;
	return 0;
}

int XoaNodeNhoNhat(BSTree root)
{
	int k;
	if (!root->pLeft)
	{
		k = root->data;
		root = root->pRight;
		return k;
	}
	else
		return XoaNodeNhoNhat(root->pLeft);
}

int XoaNodeX(int x, BSTree root)
{
	if (root)
	{
		// Nếu nút cần xóa nằm bên trái
		if (x < root->data)
			XoaNodeX(x, root->pLeft);
		// Nếu nút cần xóa nằm bên phải
		else if (x > root->data)
			XoaNodeX(x, root->pRight);
		// Nếu nút cần xóa là nút lá
		else if ((!root->pLeft) && (!root->pRight))
			root = NULL;
		// Nếu nút cần xóa chỉ có nhánh bên phải
		else if (!root->pLeft)
			root = root->pRight;
		// Nếu nút cần xóa chỉ có nhánh bên trái
		else if (!root->pRight)
			root = root->pLeft;
		// Nếu nút cần xóa là một cây con (có hai nhánh)
		else
			// Lấy nút nhỏ nhất bên phải thế vào nó
			root->data = XoaNodeNhoNhat(root->pRight);
		return 1;
	}
	return 0;
}