void XuatMenu(wstring optional[]);
int ChonMenu(int soMenu, wstring optional[]);
enum TuyChon;
void XuLy(int menu);
void XuLyMenu(TuyChon tuyChon);
void XuLyChucNang(TuyChon tuyChon, int menu);

typedef char Chuoi[100];

TREE root;
int kq;
char filename[12] = "hocvien.txt";
Chuoi lop;

void XuatMenu(wstring optional[], int n)
{
	wcout << PadRight(L"", 24, '=') + L" HỆ THỐNG CHỨC NĂNG " + PadRight(L"", 24, '=') << endl;
	for (int i = 0; i < n; i++)
	{
		wcout << i << L". " << optional[i] << endl;
	}
	wcout << PadRight(L"", 68, '=') << endl;
}

int ChonMenu(int soMenu, wstring optional[])
{
	int stt = -1;
	while (stt < 0 || stt >= soMenu)
	{
		system("cls");
		XuatMenu(optional, soMenu);
		wcout << L"\nNhập một số tương ứng trong khoảng từ [0,..," << soMenu - 1 << L"] để chọn chức năng, stt = ";
		wcin >> stt;
	}
	return stt;
}

enum TuyChon
{
	TìmKiếm = 2,
	SắpXếp,
	Xóa,
	Sửa,
	Xuất,
	ChứcNăngKhác
};

void XuLy(int menu)
{
	switch (menu)
	{
	case 0:
		wcout << L"Thoát khỏi chương trình";
		exit(0);
	case 1:
		system("cls");
		wcout << L"Chuyển dữ liệu từ tập tin danh sách nhân viên vào BST\n";
		kq = File_BST(root, filename);
		if (kq == 1)
			wcout << L"\n Chuyển dữ liệu thành công";
		else
			wcout << L"\n Chuyển dữ liệu không thành công";
		break;
	case 2:
		system("cls");
		wcout << L"Xem danh sách nhân viên theo các thứ tự NLR, LNR, LRN\n";
		XuatTieuDe();
		XuatNLR(root);
		XuatDongKeNgangDoi();
		wcout << L"\n\n Danh sách nhân viên theo thứ tự LNR:\n";
		XuatTieuDe();
		XuatLNR(root);
		XuatDongKeNgangDoi();
		wcout << L"\n\n Danh sách nhân viên theo thứ tự LRN:\n";
		XuatTieuDe();
		XuatLRN(root);
		XuatDongKeNgangDoi();
		break;
	case 3:
		system("cls");
		int soMenu = size(options);
		int menu;
		do
		{
			menu = ChonMenu(soMenu, options);
			TuyChon tuyChon = (TuyChon)menu;
			if (menu == 1)
				return;
			else if (menu == 0)
			{
				wcout << L"\n Bạn đã lựa chọn đi ngủ.\n\tCÚT";
				exit(0);
			}
			XuLyMenu(tuyChon);
		} while (menu > 0);
		break;
	}
	_getch();
}

void XuLyMenu(TuyChon tuyChon)
{
	int menu;
	int soMenu;
	switch (tuyChon)
	{
	case TìmKiếm:
		soMenu = size(search);
		do
		{
			menu = ChonMenu(soMenu, search);
			if (menu == 1)
				return;
			XuLyChucNang(tuyChon, menu);
		} while (menu > 0);
		break;
	case SắpXếp:
		soMenu = size(sort);
		do
		{
			menu = ChonMenu(soMenu, sort);
			if (menu == 1)
				return;
			XuLyChucNang(tuyChon, menu);
		} while (menu > 0);
		break;
	case Xóa:
		soMenu = size(deletes);
		do
		{
			menu = ChonMenu(soMenu, deletes);
			if (menu == 1)
				return;
			XuLyChucNang(tuyChon, menu);
		} while (menu > 0);
		break;
	case Sửa:
		soMenu = size(modified);
		do
		{
			menu = ChonMenu(soMenu, modified);
			if (menu == 1)
				return;
			XuLyChucNang(tuyChon, menu);
		} while (menu > 0);
		break;
	case Xuất:
		soMenu = size(out);
		do
		{
			menu = ChonMenu(soMenu, out);
			if (menu == 1)
				return;
			XuLyChucNang(tuyChon, menu);
		} while (menu > 0);
		break;
	case ChứcNăngKhác:
		soMenu = size(other);
		do
		{
			menu = ChonMenu(soMenu, other);
			if (menu == 1)
				return;
			XuLyChucNang(tuyChon, menu);
		} while (menu > 0);
		break;
	}
	_getch();
}

void XuLyChucNang(TuyChon tuyChon, int menu)
{
	switch (tuyChon)
	{
	case TìmKiếm:
		switch (menu)
		{
		case 0:
			wcout << L"Thoát luôn đi ngủ";
			exit(0);
		case 1:
			system("cls");
			wcout << L"Quay về trang trước";
			break;
		case 2:
			system("cls");
			wcout << L"(Tìm) Xuất danh sách học viên theo MSHV";
			wcout << L"\nNhập vào lớp cần lọc >> ";
			_flushall();
			gets_s(lop, 15);
			wcout << L"\n Danh sách học viên lớp " << lop << L" là\n\n";
			XuatTieuDe();
			XuatHocVien_Lop(root, lop);
			XuatDongKeNgangDoi();
			break;
		case 3:
			system("cls");
			wcout << L"(Tìm) Xuất danh sách học viên theo Họ và tên";
			break;
		case 4:
			system("cls");
			wcout << L"(Tìm) Xuất danh sách học viên theo năm sinh";
			break;
		case 5:
			system("cls");
			wcout << L"(Tìm) Xuất danh sách học viên theo lớp";
			break;
		case 6:
			system("cls");
			wcout << L"(Tìm) Xuất bảng điểm học viên có diểm trung bình cao nhất";
			break;
		case 7:
			system("cls");
			wcout << L"(Tìm) Xuất bảng điểm học viên có diểm trung bình thấp nhất";
			break;
		case 8:
			system("cls");
			wcout << L"(Tìm) Xuất bảng điểm học viên có diểm trung bình >= x";
			break;
		case 9:
			system("cls");
			wcout << L"(Tìm) Xuất bảng điểm học viên có diểm trung bình <= x";
			break;
		case 10:
			system("cls");
			wcout << L"(Tìm) Xuất danh sách học viên có tctl thấp nhất";
			break;
		case 11:
			system("cls");
			wcout << L"(Tìm) Xuất danh sách học viên có tctl cao nhất";
			break;
		case 12:
			system("cls");
			wcout << L"(Tìm) Xuất danh sách học viên có tctl >= x (nhập từ bàn phím)";
			break;
		case 13:
			system("cls");
			wcout << L"(Tìm) Xuất danh sách học viên có tctl <= x (nhập từ bàn phím)";
			break;
		case 14:
			system("cls");
			wcout << L"(Tìm) Xuất danh sách học viên có năm sinh trong khoảng [u,v]";
			break;
		}
		break;
	case SắpXếp:
		switch (menu)
		{
		case 0:
			wcout << L"Thoát luôn đi ngủ";
			exit(0);
		case 1:
			system("cls");
			wcout << L"Quay về trang trước";
			break;
		case 2:
			system("cls");
			wcout << L"Sắp xếp danh sách học viên tăng dần theo MSHV";
			break;
		case 3:
			system("cls");
			wcout << L"Sắp xếp danh sách học viên tăng dần theo Họ và Tên";
			break;
		case 4:
			system("cls");
			wcout << L"Sắp xếp danh sách học viên tăng dần theo Năm sinh";
			break;
		case 5:
			system("cls");
			wcout << L"Sắp xếp danh sách học viên tăng dần theo lớp";
			break;
		case 6:
			system("cls");
			wcout << L"Sắp xếp danh sách học viên tăng dần theo Điểm trung bình";
			break;
		case 7:
			system("cls");
			wcout << L"Sắp xếp danh sách học viên tăng dần theo tctl";
			break;
		case 8:
			system("cls");
			wcout << L"Sắp xếp danh sách học viên giảm dần theo MSHV";
			break;
		case 9:
			system("cls");
			wcout << L"Sắp xếp danh sách học viên giảm dần theo Họ và Tên";
			break;
		case 10:
			system("cls");
			wcout << L"Sắp xếp danh sách học viên giảm dần theo năm sinh";
			break;
		case 11:
			system("cls");
			wcout << L"Sắp xếp danh sách học viên giảm dần theo lớp";
			break;
		case 12:
			system("cls");
			wcout << L"Sắp xếp danh sách học viên giảm dần theo điểm trung bình";
			break;
		case 13:
			system("cls");
			wcout << L"Sắp xếp danh sách học viên giảm dần theo tctl";
			break;
		case 14:
			system("cls");
			wcout << L"Sắp xếp danh sách học viên tăng dần theo MSHV - Họ và tên - Năm sinh - Lớp - DTB - TCTL";
			break;
		case 15:
			system("cls");
			wcout << L"Sắp xếp danh sách học viên tăng dần theo TCTL - DTB - Lớp - Năm sinh - Họ và tên -  MSHV";
			break;
		case 16:
			system("cls");
			wcout << L"Sắp xếp danh sách học viên tăng dần theo MSHV - Họ và Tên - Năm sinh - Lớp - DTB - TCTL";
			break;
		case 17:
			system("cls");
			wcout << L"Sắp xếp danh sách học viên tăng dần theo TCTL - DTB - Lớp - Năm sinh - Họ và tên -  MSHV";
			break;
		}
		break;
	case Xóa:
		switch (menu)
		{
		case 0:
			wcout << L"Thoát luôn đi ngủ";
			exit(0);
		case 1:
			system("cls");
			wcout << L"Quay về trang trước";
			break;
		case 2:
			system("cls");
			wcout << L"Xóa học viên theo MSHV";
			break;
		case 3:
			system("cls");
			wcout << L"Xóa học viên theo Họ và Tên";
			break;
		case 4:
			system("cls");
			wcout << L"Xóa học viên theo năm sinh";
			break;
		case 5:
			system("cls");
			wcout << L"Xóa học viên theo lớp";
			break;
		case 6:
			system("cls");
			wcout << L"Xóa học viên có điểm trung bình >= x";
			break;
		case 7:
			system("cls");
			wcout << L"Xóa học viên có điểm trung bình <= x";
			break;
		case 8:
			system("cls");
			wcout << L"Xóa học viên có điểm trung bình thấp nhất";
			break;
		case 9:
			system("cls");
			wcout << L"Xóa học viên có điểm trung bình cao nhất";
			break;
		case 10:
			system("cls");
			wcout << L"Xóa học viên có tctl >= x";
			break;
		case 11:
			system("cls");
			wcout << L"Xóa học viên có tctl <= x";
			break;
		case 12:
			system("cls");
			wcout << L"Xóa học viên có tctl thấp nhất";
			break;
		case 13:
			system("cls");
			wcout << L"Xóa học viên có tctl cao nhất";
			break;
		}
		break;
	case Sửa:
		switch (menu)
		{
		case 0:
			wcout << L"Thoát luôn đi ngủ";
			exit(0);
		case 1:
			system("cls");
			wcout << L"Quay về trang trước";
			break;
		case 2:
			system("cls");
			wcout << L"Sửa thông tin học viên theo MSHV";
			break;
		case 3:
			system("cls");
			wcout << L"Sửa thông tin học viên theo Ho va ten";
			break;
		case 4:
			system("cls");
			wcout << L"Sửa thông tin học viên theo nam sinh";
			break;
		case 5:
			system("cls");
			wcout << L"Sửa thông tin học viên theo lop";
			break;
		case 6:
			system("cls");
			wcout << L"Sửa thông tin học viên có điểm trung bình >= x";
			break;
		case 7:
			system("cls");
			wcout << L"Sửa thông tin học viên có điểm trung bình <= x";
			break;
		case 8:
			system("cls");
			wcout << L"Sửa thông tin học viên có điểm trung bình thấp nhất";
			break;
		case 9:
			system("cls");
			wcout << L"Sửa thông tin học viên có điểm trung bình cao nhất";
			break;
		case 10:
			system("cls");
			wcout << L"Sửa thông tin học viên có tctl >= x";
			break;
		case 11:
			system("cls");
			wcout << L"Sửa thông tin học viên có tctl <= x";
			break;
		case 12:
			system("cls");
			wcout << L"Sửa thông tin học viên có tctl thấp nhất";
			break;
		case 13:
			system("cls");
			wcout << L"Sửa thông tin học viên có tctl cao nhất";
			break;
		}
		break;
	case Xuất:
		switch (menu)
		{
		case 0:
			wcout << L"Thoát luôn đi ngủ";
			exit(0);
		case 1:
			system("cls");
			wcout << L"Quay về trang trước";
			break;
		case 2:
			system("cls");
			wcout << L"Xuất danh sách học viên theo cùng MSHV";
			break;
		case 3:
			system("cls");
			wcout << L"Xuất danh sách học viên theo cùng Họ";
			break;
		case 4:
			system("cls");
			wcout << L"Xuất danh sách học viên theo cùng Họ lót";
			break;
		case 5:
			system("cls");
			wcout << L"Xuất danh sách học viên theo cùng Tên";
			break;
		case 6:
			system("cls");
			wcout << L"Xuất danh sách học viên theo cùng năm sinh";
			break;
		case 7:
			system("cls");
			wcout << L"Xuất danh sách học viên theo cùng lớp";
			break;
		case 8:
			system("cls");
			wcout << L"Xuất danh sách học viên theo cùng mức điểm trung bình";
			break;
		case 9:
			system("cls");
			wcout << L"Xuất danh sách học viên theo cùng mức tctl";
			break;
		}
		break;
	case ChứcNăngKhác:
		switch (menu)
		{
		case 0:
			wcout << L"Thoát luôn đi ngủ";
			exit(0);
		case 1:
			system("cls");
			wcout << L"Quay về trang trước";
			break;
		case 2:
			system("cls");
			wcout << L"Thêm một học viên vào đầu danh sách";
			break;
		case 3:
			system("cls");
			wcout << L"Thêm một học viên vào cuối danh sách";
			break;
		case 4:
			system("cls");
			wcout << L"Tính tổng tất cả điểm trung bình của học viên";
			break;
		case 5:
			system("cls");
			wcout << L"Tính tổng tất cả tctl của học viên";
			break;
		}
		break;
	}
	_getch();
}