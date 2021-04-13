#define MAX 100

struct NhanVien
{
	char maNV[8];
	char ho[10];
	char hoLot[10];
	char ten[10];
	char diaChi[15];
	unsigned namsinh;
	double luong;
};

int FileStream(char* filename, NhanVien a[MAX], int& n)
{
	ifstream in(filename);
	if (!in)
		return 0;
	n = 0;
	while (!in.eof())
	{
		in >> a[n].maNV;
		in >> a[n].ho;
		in >> a[n].hoLot;
		in >> a[n].ten;
		in >> a[n].diaChi;
		in >> a[n].namsinh;
		in >> a[n].luong;
		n++;
	}
	in.close();
	return 1;
}

void XuatDongKe(char kt)
{
	cout << "\n";
	for (int i = 0; i <= 75; i++)
		cout << kt;
	cout << "\n";
}

void XuatTieuDe()
{
	XuatDongKe('=');
	cout << setiosflags(ios::left)
		<< setw(8) << "Ma NV"
		<< setw(10) << "Ho"
		<< setw(10) << "Ho Lot"
		<< setw(10) << "Ten"
		<< setw(15) << "Dia Chi"
		<< setw(10) << "Nam Sinh"
		<< setw(10) << "Luong";
	XuatDongKe('=');
}

void Xuat1NhanVien(NhanVien a)
{
	cout << "\n";
	cout << setiosflags(ios::left)
		<< setw(8) << a.maNV
		<< setw(10) << a.ho
		<< setw(10) << a.hoLot
		<< setw(10) << a.ten
		<< setw(15) << a.diaChi
		<< setw(10) << a.namsinh
		<< setw(10) << setiosflags(ios::fixed) << setprecision(0) << a.luong;
}

void XuatDSNV(NhanVien a[MAX], int n)
{
	XuatTieuDe();
	for (int i = 0; i < n; i++)
	{
		Xuat1NhanVien(a[i]);
		if ((i + 1) % 5 == 0)
			XuatDongKe('-');
	}
	XuatDongKe('=');
}

void Copy(NhanVien b[MAX], NhanVien a[MAX], int n)
{
	for (int i = 0; i < n; i++)
	{
		b[i] = a[i];
	}
}

void SelectionSort(NhanVien a[MAX], int n)
{
	int csMin;
	for (int i = 0; i < n; i++)
	{
		csMin = i;
		for (int j = i + 1; j < n; j++)
		{
			if (_strcmpi(a[i].maNV, a[j].maNV) > 0)
				csMin = j;
		}
		swap(a[csMin], a[i]);
	}
}

void InsertionSort(NhanVien a[MAX], int n)
{
	int j;
	char x[15];
	for (int i = 1; i < n; i++)
	{
		strcpy_s(x, a[i].diaChi);
		j = i;
		while (j > 0 && (_strcmpi(a[j - 1].diaChi, x) > 0))
		{
			a[j] = a[j - 1];
			j--;
		}
		strcpy_s(a[j].diaChi, x);
	}
}

void RadixSort(NhanVien a[MAX], int n)
{
	int max = a[0].namsinh, m = 0, k = 0, du, thuong, i, j;
	int b0[MAX], b1[MAX], b2[MAX], b3[MAX], b4[MAX], b5[MAX], b6[MAX], b7[MAX], b8[MAX], b9[MAX];
	int p0, p1, p2, p3, p4, p5, p6, p7, p8, p9;
	for (int i = 0; i < n; i++)
		if (a[i].namsinh > max)
			max = a[i].namsinh;
	while (max != 0)
	{
		max /= 10;
		m++;
	}
	while (k < m)
	{
		p0 = p1 = p2 = p3 = p4 = p5 = p6 = p7 = p8 = p9 = 0;
		for (i = 0; i < n; i++)
		{
			thuong = a[i].namsinh;
			for (j = 0; j <= k; j++)
			{
				du = thuong % 10;
				thuong /= 10;
			}
			switch (du)
			{
			case 0:
				b0[p0++] = a[i].namsinh;
				break;
			case 1:
				b1[p1++] = a[i].namsinh;
				break;
			case 2:
				b2[p2++] = a[i].namsinh;
				break;
			case 3:
				b3[p3++] = a[i].namsinh;
				break;
			case 4:
				b4[p4++] = a[i].namsinh;
				break;
			case 5:
				b5[p5++] = a[i].namsinh;
				break;
			case 6:
				b6[p6++] = a[i].namsinh;
				break;
			case 7:
				b7[p7++] = a[i].namsinh;
				break;
			case 8:
				b8[p8++] = a[i].namsinh;
				break;
			case 9:
				b9[p9++] = a[i].namsinh;
				break;
			}
		}
		j = 0;
		for (i = 0; i < p0; i++)
			a[j++].namsinh = b0[i];
		for (i = 0; i < p1; i++)
			a[j++].namsinh = b1[i];
		for (i = 0; i < p2; i++)
			a[j++].namsinh = b2[i];
		for (i = 0; i < p3; i++)
			a[j++].namsinh = b3[i];
		for (i = 0; i < p4; i++)
			a[j++].namsinh = b4[i];
		for (i = 0; i < p5; i++)
			a[j++].namsinh = b5[i];
		for (i = 0; i < p6; i++)
			a[j++].namsinh = b6[i];
		for (i = 0; i < p7; i++)
			a[j++].namsinh = b7[i];
		for (i = 0; i < p8; i++)
			a[j++].namsinh = b8[i];
		for (i = 0; i < p9; i++)
			a[j++].namsinh = b9[i];
		k++;
	}
}

void QuickSort(NhanVien a[MAX], int l, int r)
{
	int p = a[(l + r) / 2].luong;
	int i = l, j = r;
	while (i < j)
	{
		while (a[i].luong < p)
			i++;
		while (a[j].luong > p)
			j--;
		if (i <= j)
			swap(a[i++], a[j--]);
	}
	if (i < r)
		QuickSort(a, i, r);
	if (l < j)
		QuickSort(a, l, j);
	for (int i = 0; i <= r; i++)
		for (int j = i + 1; j < r; j++)
			if (a[i].luong == a[j].luong)
			{
				if (_strcmpi(a[i].ten, a[j].ten) > 0)
					swap(a[i], a[j]);
				else if (_strcmpi(a[i].ten, a[j].ten) == 0)
				{
					if (_strcmpi(a[i].ho, a[j].ho) > 0)
						swap(a[i], a[j]);
					else if (_strcmpi(a[i].ho, a[j].ho) == 0)
					{
						if (a[i].namsinh > a[j].namsinh)
							swap(a[i], a[j]);
					}
				}
			}
}