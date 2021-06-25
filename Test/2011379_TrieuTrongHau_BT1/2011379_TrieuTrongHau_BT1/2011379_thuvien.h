#define MAX 100

struct HocVien
{
	char maHV[10];
	char hoHV[11];
	char tenLot[11];
	char tenHV[11];
	char lop[7];
	unsigned namSinh;
	double diemTB;
	unsigned tcTichLuy;
};

int TaoDanhSachHocVien(HocVien a[MAX], int& n, char filename[MAX])
{
	ifstream in(filename);
	if (!in)
	{
		return 0;
	}
	else
	{
		n = 0;
		while (!in.eof())
		{
			in >> a[n].maHV;
			in >> a[n].hoHV;
			in >> a[n].tenLot;
			in >> a[n].tenHV;
			in >> a[n].lop;
			in >> a[n].namSinh;
			in >> a[n].diemTB;
			in >> a[n].tcTichLuy;
			n++;
		}
		in.close();
		return 1;
	}
}

void XuatDongKeNgangDoi()
{
	cout << "\n";
	for (int i = 0; i <= 82; i++)
		cout << '=';
}

void XuatDongKeNgangDon()
{
	cout << "\n";
	for (int i = 0; i <= 82; i++)
		cout << '-';
}

void XuatTieuDe()
{
	XuatDongKeNgangDoi();
	cout << "\n";
	cout << setiosflags(ios::left)
		<< setw(11) << "Ma HV"
		<< setw(8) << "Ho"
		<< setw(8) << "Ho Lot"
		<< setw(8) << "Ten"
		<< setw(8) << "Lop"
		<< setw(12) << "Nam sinh"
		<< setw(17) << "Diem TB"
		<< setw(10) << "TCTL";
	XuatDongKeNgangDoi();
}

void Xuat_1_HocVien(HocVien a)
{
	cout << setiosflags(ios::left);
	cout << setw(11) << a.maHV
		<< setw(8) << a.hoHV
		<< setw(8) << a.tenLot
		<< setw(8) << a.tenHV
		<< setw(8) << a.lop
		<< setw(12) << a.namSinh
		<< setw(17) << a.diemTB
		<< setiosflags(ios::fixed) << setprecision(2) << setw(10) << a.tcTichLuy << '|';
	cout << "\n";
}

void XuatDSHV(HocVien a[MAX], int n)
{
	XuatTieuDe();
	for (int i = 0; i < n; i++)
	{
		cout << "\n\n";
		Xuat_1_HocVien(a[i]);
		if ((i + 1) % 3 == 0)
			XuatDongKeNgangDon();
	}
	XuatDongKeNgangDoi();
}

void XuatHocVien_Lop_STC(HocVien a[MAX], int n)
{
	int dem = 0;
	for (int i = 0; i < n; i++)
		if (_strcmpi(a[i].lop, "CTK37") == 0 && a[i].tcTichLuy > 41)
			dem++;
	if (!dem)
		cout << "\nKhong tim thay hoc vien co lop CTK37 va stc lon hon 41 vui long kiem tra lai.";
	else
	{
		cout << "\nCo " << dem << " hoc vien co lop CTK37 va stc lon hon 41 trong danh sach";
		XuatTieuDe();
		for (int i = 0; i < n; i++)
			if (_strcmpi(a[i].lop, "CTK37") == 0 && a[i].tcTichLuy > 41)
			{
				cout << "\n\n";
				Xuat_1_HocVien(a[i]);
				if ((i + 1) % 3 == 0)
					XuatDongKeNgangDon();
			}
		XuatDongKeNgangDoi();
	}
}

void XuatHocVien_TenHoa(HocVien a[MAX], int n)
{
	int dem = 0;
	for (int i = 0; i < n; i++)
		if (_strcmpi(a[i].tenHV, "Hoa") == 0)
			dem++;
	if (!dem)
		cout << "\nKhong tim thay hoc vien co lop CTK37 va stc lon hon 41 vui long kiem tra lai.";
	else
	{
		cout << "\nCo " << dem << " hoc vien co lop CTK37 va stc lon hon 41 trong danh sach";
		XuatTieuDe();
		for (int i = 0; i < n; i++)
			if (_strcmpi(a[i].tenHV, "Hoa") == 0)
			{
				cout << "\n\n";
				Xuat_1_HocVien(a[i]);
				if ((i + 1) % 3 == 0)
					XuatDongKeNgangDon();
			}
		XuatDongKeNgangDoi();
	}
}

void XuatHocVienTheoNamSinh_DTB(HocVien a[MAX], int n)
{
	int dem = 0;
	for (int i = 0; i < n; i++)
		if (a[i].namSinh > 1993 && a[i].diemTB <= 6.2)
			dem++;
	if (!dem)
		cout << "\nKhong tim thay hoc vien co nam sinh lon hon 1993 va DTB <= 6.2 vui long kiem tra lai.";
	else
	{
		cout << "\nCo " << dem << " hoc vien co nam sinh lon hon 1993 va DTB <= 6.2 trong danh sach";
		XuatTieuDe();
		for (int i = 0; i < n; i++)
			if (a[i].namSinh > 1993 && a[i].diemTB <= 6.2)
			{
				cout << "\n\n";
				Xuat_1_HocVien(a[i]);
				if ((i + 1) % 3 == 0)
					XuatDongKeNgangDon();
			}
		XuatDongKeNgangDoi();
	}
}