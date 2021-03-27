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