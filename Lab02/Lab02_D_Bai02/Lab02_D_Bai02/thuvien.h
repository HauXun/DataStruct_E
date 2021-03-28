#define MAX 100

struct SinhVien
{
	char maSV[8];
	char hoSV[10];
	char tenLot[10];
	char ten[10];
	char lop[6];
	int namsinh;
	double dtb;
	int tichLuy;
};

int TapTin_MangCT(char* filename, SinhVien a[MAX], int& n)
{
	ifstream in(filename);
	if (!in)
		return 0;
	n = 0;
	while (!in.eof())
	{
		in >> a[n].maSV;
		in >> a[n].hoSV;
		in >> a[n].tenLot;
		in >> a[n].ten;
		in >> a[n].lop;
		in >> a[n].namsinh;
		in >> a[n].dtb;
		in >> a[n].tichLuy;
		n++;
	}
	in.close();
	return 1;
}

void XuatDSNV(SinhVien a[MAX], int n)
{
	cout << endl;
	cout << setiosflags(ios::left)
		<< setw(10) << "MS"
		<< setw(30) << "Ho Ten"
		<< setw(10) << "Lop"
		<< setw(6) << "NS"
		<< setw(6) << "DTB"
		<< setw(8) << "TichLuy" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << setiosflags(ios::left)
			<< setw(10) << a[i].maSV
			<< setw(10) << a[i].hoSV
			<< setw(10) << a[i].tenLot
			<< setw(10) << a[i].ten
			<< setw(10) << a[i].lop
			<< setw(6) << a[i].namsinh
			<< setw(6) << setprecision(2) << a[i].dtb
			<< setiosflags(ios::fixed) << setw(8) << a[i].tichLuy << endl;
	}
}

void XuatTieuDe(SinhVien a[MAX], int n)
{
	cout << endl;
	cout << setiosflags(ios::left)
		<< setw(10) << "MS"
		<< setw(30) << "Ho Ten"
		<< setw(10) << "Lop"
		<< setw(6) << "NS"
		<< setw(6) << "DTB"
		<< setw(8) << "TichLuy" << endl;
}

void XuatNhanVien(SinhVien a)
{
	cout << endl;
	cout << setiosflags(ios::left)
		<< setw(10) << a.maSV
		<< setw(10) << a.hoSV
		<< setw(10) << a.tenLot
		<< setw(10) << a.ten
		<< setw(10) << a.lop
		<< setw(6) << a.namsinh
		<< setw(6) << setprecision(2) << a.dtb
		<< setiosflags(ios::fixed) << setw(8) << a.tichLuy << endl;
}

// Tìm theo mã số: Trả về chỉ số i đầu tiên sao cho a[i].maSV = maSV
int Tim_MaSo_DauTien(char maSV[10], SinhVien a[MAX], int n)
{
	int i = 0;
	while ((i < n) && (_strcmpi(a[i].maSV, maSV)))
		i++;
	if (i == n)
		return -1;
	return i;
}

// Tìm theo tên
void Tim_TheoTen(char ten[10], SinhVien a[MAX], int n)
{
	int result = -1;
	for (int i = 0; i < n; i++)
		if (_strcmpi(a[i].ten, ten) == 0)
		{
			result = 1;
			break;
		}
	if (result == -1)
		cout << "\nDanh sach khong co sinh vien ten " << ten;
	else
	{
		cout << "\nThong tin sinh vien trong danh sach co ten " << ten;
		cout << endl;
		XuatTieuDe(a, n);
		for (int i = 0; i < n; i++)
			if (_strcmpi(a[i].ten, ten) == 0)
				XuatNhanVien(a[i]);
	}
}

// Tìm theo họ
void Tim_TheoHo(char hoSV[10], SinhVien a[MAX], int n)
{
	int result = -1;
	for (int i = 0; i < n; i++)
		if (_strcmpi(a[i].hoSV, hoSV) == 0)
		{
			result = 1;
			break;
		}
	if (result == -1)
		cout << "\nDanh sach khong co sinh vien ho " << hoSV;
	else
	{
		cout << "\nThong tin sinh vien trong danh sach co ho " << hoSV;
		cout << endl;
		XuatTieuDe(a, n);
		for (int i = 0; i < n; i++)
			if (_strcmpi(a[i].hoSV, hoSV) == 0)
				XuatNhanVien(a[i]);
	}
}

// Tìm theo lớp
void Tim_TheoLop(char lop[10], SinhVien a[MAX], int n)
{
	int result = -1;
	for (int i = 0; i < n; i++)
		if (_strcmpi(a[i].lop, lop) == 0)
		{
			result = 1;
			break;
		}
	if (result == -1)
		cout << "\nDanh sach khong co sinh vien lop " << lop;
	else
	{
		cout << "\nThong tin sinh vien trong danh sach thuoc lop " << lop;
		cout << endl;
		XuatTieuDe(a, n);
		for (int i = 0; i < n; i++)
			if (_strcmpi(a[i].lop, lop) == 0)
				XuatNhanVien(a[i]);
	}
}

// Tìm theo điểm trung bình: Xuất sinh viên có điểm trung bình >= dtb
void Tim_TheoDTB(double dtb, SinhVien a[MAX], int n)
{
	int result = -1;
	for (int i = 0; i < n; i++)
		if (a[i].dtb >= dtb)
		{
			result = 1;
			break;
		}
	if (result == -1)
		cout << "\nDanh sach khong co sinh vien co diem trung binh " << dtb;
	else
	{
		cout << "\nThong tin sinh vien trong danh sach co diem trung binh " << dtb;
		cout << endl;
		XuatTieuDe(a, n);
		for (int i = 0; i < n; i++)
			if (a[i].dtb >= dtb)
				XuatNhanVien(a[i]);
	}
}

// Kiểm tra dãy số nguyên tăng, Tăng = 1: Không Tăng = 0;
int KiemTraDayTang(int x[MAX], int n)
{
	int result = -1;
	for (int i = 0; i < n; i++)
		if (x[i] > x[i + 1])
		{
			result = 0; // Không tăng
			break;
		}
	return result;
}

// Kiểm tra dãy số nguyên giảm, Giảm = 1: Không Giảm = 0;
int KiemTraDayGiam(int x[MAX], int n)
{
	int result = -1;
	for (int i = 0; i < n; i++)
		if (x[i] < x[i + 1])
		{
			result = 0; // Không giảm
			break;
		}
	return result;
}

int LinearSearch_Tang(int x[MAX], int n, int tichLuy)
{
	int result = -1, middle, left = 0, right = n - 1;
	do
	{
		middle = (left + right) / 2;
		if (tichLuy == x[middle])
		{
			result = middle;
			break;
		}
		else if (tichLuy < middle)
			right = middle - 1;
		else
			left = middle + 1;
	} while (left <= right);
	return result;
}

void Xuat_LinearSearch_Theo_DiemTichLuy(int tichLuy, SinhVien a[MAX], int n, int result)
{
	if (result == -1)
	{
		cout << "\nKhong co sinh vien trong danh sach co so Tin chi tich luy = " << tichLuy;
		cout << endl;
		return;
	}
	else
	{
		cout << "\nThong tin sinh vien trong danh sach co so tin chi tich luy = " << tichLuy;
		XuatTieuDe(a, n);
		cout << endl;
		XuatNhanVien(a[result]);
		cout << endl;
		return;
	}
}

void LinearSearch_Theo_DiemTichLuy(SinhVien a[MAX], int n)
{
	int result;
	int x[MAX];
	for (int i = 0; i < n; i++)
		x[i] = a[i].tichLuy;
	if (!KiemTraDayGiam(x, n) && (!KiemTraDayTang(x, n)))
	{
		cout << "\nDay so nguyen tao boi truong tich luy khong dong deu";
		cout << "\nKhong su dung duoc giai thuat tim kiem nhi phan...";
		return;
	}
	int tichLuy;
	cout << "\nNhap so tin chi tich luy: ";
	cin >> tichLuy;
	if (KiemTraDayTang(x, n))
	{
		result = LinearSearch_Tang(x, n, tichLuy);
		Xuat_LinearSearch_Theo_DiemTichLuy(tichLuy, a, n, result);
	}
}