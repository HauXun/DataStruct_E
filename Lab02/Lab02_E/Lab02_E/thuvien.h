#define MAX 100

struct Date
{
	unsigned int ngay;
	unsigned int thang;
	unsigned int nam;
};

struct NhanVien
{
	char maNV[8];
	char ho[10];
	char tenLot[10];
	char ten[10];
	Date ntns;
	char diaChi[15];
	double luong;
};

int File_Reader(char* filename, NhanVien a[MAX], int& n)
{
	ifstream in(filename);
	if (!in)
		return 0;
	n = 0;
	while (!in.eof())
	{
		in >> a[n].maNV;
		in >> a[n].ho;
		in >> a[n].tenLot;
		in >> a[n].ten;
		in >> a[n].ntns.ngay;
		in >> a[n].ntns.thang;
		in >> a[n].ntns.nam;
		in >> a[n].diaChi;
		in >> a[n].luong;
		n++;
	}
	in.close();
	return 1;
}

void XuatTieuDe()
{
	cout << endl;
	cout << setiosflags(ios::left)
		<< setw(15) << "Ma NV"
		<< setw(10) << "Ho"
		<< setw(10) << "Ten Lot"
		<< setw(10) << "Ten"
		<< setw(15) << "Ngay Sinh"
		<< setw(15) << "Dia Chi"
		<< setw(9) << "Luong" << endl;
}

void XuatNhanVien(NhanVien a)
{
	cout << endl;
	cout << setiosflags(ios::left)
		<< setw(15) << a.maNV
		<< setw(10) << a.ho
		<< setw(10) << a.tenLot
		<< setw(10) << a.ten
		<< setw(3) << a.ntns.ngay
		<< setw(3) << a.ntns.thang
		<< setw(9) << a.ntns.nam
		<< setw(15) << a.diaChi
		<< setw(9) << setiosflags(ios::fixed) << setprecision(0) << a.luong << endl;
}

void XuatDSNV(NhanVien a[MAX], int n)
{
	XuatTieuDe();
	for (int i = 0; i < n; i++)
		XuatNhanVien(a[i]);
}

void TimNhanVien_Ho_Ten(NhanVien a[MAX], int n, char ho[8], char ten[8])
{
	int count = 0;
	for (int i = 0; i < n; i++)
		if (_strcmpi(a[i].ho, ho) == 0 && _strcmpi(a[i].ten, ten) == 0)
			count++;
	if (!count)
		cout << "\nKhong tim thay nhan vien nao co ho " << ho << " va ten " << ten << " trong danh sach. Vui long kiem tra lai !";
	else
	{
		cout << "\nCo " << count << " nhan vien co ho " << ho << " va ten " << ten << " trong danh sach";
		XuatTieuDe();
		for (int i = 0; i < n; i++)
			if (_strcmpi(a[i].ho, ho) == 0 && _strcmpi(a[i].ten, ten) == 0)
				XuatNhanVien(a[i]);
	}
}

void TimNhanVien_NamSinh(NhanVien a[MAX], int n, int namsinh)
{
	int count = 0;
	for (int i = 0; i < n; i++)
		if (a[i].ntns.nam == namsinh)
			count++;
	if (!count)
		cout << "\nKhong tim thay nhan vien nao co nam sinh " << namsinh << " trong danh sach. Vui long kiem tra lai !";
	else
	{
		cout << "\nCo " << count << " nhan vien co nam sinh " << namsinh << " trong danh sach";
		XuatTieuDe();
		for (int i = 0; i < n; i++)
			if (a[i].ntns.nam == namsinh)
				XuatNhanVien(a[i]);
	}
}

void TimNhanVien_Ho_Ten_NamSinh(NhanVien a[MAX], int n, char ho[8], char ten[8], int namsinh)
{
	int count = 0;
	for (int i = 0; i < n; i++)
		if (_strcmpi(a[i].ho, ho) == 0 && _strcmpi(a[i].ten, ten) == 0 && a[i].ntns.nam < namsinh)
			count++;
	if (!count)
		cout << "\nKhong tim thay nhan vien nao co ho " << ho << " va ten " << ten << " va nam sinh nho hon " << namsinh << " trong danh sach. Vui long kiem tra lai !";
	else
	{
		cout << "\nCo " << count << " nhan vien co ho " << ho << " va ten " << ten << " va nam sinh nho hon " << namsinh << " trong danh sach";
		XuatTieuDe();
		for (int i = 0; i < n; i++)
			if (_strcmpi(a[i].ho, ho) == 0 && _strcmpi(a[i].ten, ten) == 0 && a[i].ntns.nam < namsinh)
				XuatNhanVien(a[i]);
	}
}

void TimNhanVien_Ten_DiaChi(NhanVien a[MAX], int n, char ten[8], char diachi[15])
{
	int count = 0;
	for (int i = 0; i < n; i++)
		if (_strcmpi(a[i].ten, ten) == 0 && _strcmpi(a[i].diaChi, diachi))
			count++;
	if (!count)
		cout << "\nKhong tim thay nhan vien nao co ten " << ten << " va co dia chi " << diachi << " trong danh sach. Vui long kiem tra lai !";
	else
	{
		cout << "\nCo " << count << " nhan vien co ten " << ten << " va co dia chi " << diachi << " trong danh sach";
		XuatTieuDe();
		for (int i = 0; i < n; i++)
			if (_strcmpi(a[i].ten, ten) == 0 && _strcmpi(a[i].diaChi, diachi))
				XuatNhanVien(a[i]);
	}
}

void TimNhanVien_Luong_NamSinh(NhanVien a[MAX], int n, double luong, int namsinh)
{
	int count = 0;
	for (int i = 0; i < n; i++)
		if (a[i].luong >= luong && a[i].ntns.nam <= namsinh)
			count++;
	if (!count)
		cout << "\nKhong tim thay nhan vien nao co luong >= " << luong << " va nam sinh <= " << namsinh << " trong danh sach. Vui long kiem tra lai !";
	else
	{
		cout << "\nCo " << count << " nhan vien co luong >= " << luong << " va nam sinh <= " << namsinh << " trong danh sach";
		XuatTieuDe();
		for (int i = 0; i < n; i++)
			if (a[i].luong >= luong && a[i].ntns.nam <= namsinh)
				XuatNhanVien(a[i]);
	}
}

int KiemTraDayTang(NhanVien a[MAX], int n)
{
	int result = 1;
	for (int i = 0; i < n; i++)
	{
		if (_strcmpi(a[i].maNV, a[i + 1].maNV) > 0)
		{
			result = 0;
			break;
		}
	}
	return result;
}

int KiemTraDayGiam(NhanVien a[MAX], int n)
{
	int result = 1;
	for (int i = 0; i < n; i++)
	{
		if (_strcmpi(a[i].maNV, a[i + 1].maNV) < 0)
		{
			result = 0;
			break;
		}
	}
	return result;
}

int LinearSearch_MaNV_Tang(NhanVien a[MAX], int n, char maNV[8])
{
	int result = -1, middle, left = 0, right = n - 1;
	do
	{
		middle = (left + right) / 2;
		if (_strcmpi(a[middle].maNV, maNV) == 0)
		{
			result = middle;
			break;
		}
		else
			if (_strcmpi(a[middle].maNV, maNV) > 0)
				right = middle - 1;
			else
				left = middle + 1;
	} while (left <= right);
	return result;
}

int LinearSearch_MaNV_Giam(NhanVien a[MAX], int n, char maNV[8])
{
	int result = -1, middle, left = 0, right = n - 1;
	do
	{
		middle = (left + right) / 2;
		if (_strcmpi(a[middle].maNV, maNV) == 0)
		{
			result = middle;
			break;
		}
		else
			if (_strcmpi(a[middle].maNV, maNV) < 0)
				left = middle + 1;
			else
				right = middle - 1;
	} while (left <= right);
	return result;
}

void TimNhanVien_MaNV_LinearSearch(NhanVien a[MAX], int n, int result, char maNV[8])
{
	if (result == -1)
	{
		cout << "\nKhong tim thay nhan vien nao trong danh sach co ma nhan vien la " << maNV;
		return;
	}
	else
	{
		cout << "\nThong tin nhan vien co ma nhan vien la " << maNV;
		XuatTieuDe();
		XuatNhanVien(a[result]);
	}
}

void LinearSearch_MaNV(NhanVien a[MAX], int n, char maNV[8])
{
	int result;
	if (!KiemTraDayTang(a, n) && !KiemTraDayGiam(a, n))
	{
		cout << "\nTruong ma so nhan vien khong dong deu...";
		cout << "\nKhong the su dung thuat giai tim kiem nhi phan...!";
		return;
	}
	if (KiemTraDayTang(a, n))
	{
		result = LinearSearch_MaNV_Tang(a, n, maNV);
		TimNhanVien_MaNV_LinearSearch(a, n, result, maNV);
	}
	if (KiemTraDayGiam(a, n))
	{
		result = LinearSearch_MaNV_Giam(a, n, maNV);
		TimNhanVien_MaNV_LinearSearch(a, n, result, maNV);
	}
}