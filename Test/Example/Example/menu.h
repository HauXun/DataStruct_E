wstring input[] = {
	L"Thoát khỏi chương trình",
	L"Chuyển dữ liệu từ tập tin danh sách nhân viên vào BST",
	L"Xem danh sách nhân viên theo các thứ tự NLR, LNR, LRN",
	L"Tùy biến chức năng"
};

wstring options[] = {
	L"Thoát luôn đi ngủ",
	L"Quay về trang trước",

	L"Tìm kiếm",
	L"Sắp xếp",
	L"Xóa",
	L"Sửa",
	L"Chức năng khác",
};

wstring search[] = {
	L"Thoát luôn đi ngủ",
	L"Quay về trang trước",

	L"(Tìm) Xuất danh sách học viên theo MSHV",
	L"(Tìm) Xuất danh sách học viên theo Họ và tên",
	L"(Tìm) Xuất danh sách học viên theo năm sinh",
	L"(Tìm) Xuất danh sách học viên theo lớp",

	L"(Tìm) Xuất bảng điểm học viên có diểm trung bình cao nhất",
	L"(Tìm) Xuất bảng điểm học viên có diểm trung bình thấp nhất",
	L"(Tìm) Xuất bảng điểm học viên có diểm trung bình >= x",
	L"(Tìm) Xuất bảng điểm học viên có diểm trung bình <= x",

	L"(Tìm) Xuất danh sách học viên có tctl thấp nhất",
	L"(Tìm) Xuất danh sách học viên có tctl cao nhất",
	L"(Tìm) Xuất danh sách học viên có tctl >= x (nhập từ bàn phím)",
	L"(Tìm) Xuất danh sách học viên có tctl <= x (nhập từ bàn phím)",
	L"(Tìm) Xuất danh sách học viên có năm sinh trong khoảng [u,v]"
};

wstring sort[] = {
	L"Thoát luôn đi ngủ",
	L"Quay về trang trước",

	L"Sắp xếp danh sách học viên tăng dần theo MSHV",
	L"Sắp xếp danh sách học viên tăng dần theo Họ và Tên",
	L"Sắp xếp danh sách học viên tăng dần theo Năm sinh",
	L"Sắp xếp danh sách học viên tăng dần theo lớp",
	L"Sắp xếp danh sách học viên tăng dần theo Điểm trung bình",
	L"Sắp xếp danh sách học viên tăng dần theo tctl",

	L"Sắp xếp danh sách học viên giảm dần theo MSHV",
	L"Sắp xếp danh sách học viên giảm dần theo Họ và Tên",
	L"Sắp xếp danh sách học viên giảm dần theo năm sinh",
	L"Sắp xếp danh sách học viên giảm dần theo lớp",
	L"Sắp xếp danh sách học viên giảm dần theo điểm trung bình",
	L"Sắp xếp danh sách học viên giảm dần theo tctl",

	L"Sắp xếp danh sách học viên tăng dần theo MSHV - Họ và tên - Năm sinh - Lớp - DTB - TCTL",
	L"Sắp xếp danh sách học viên tăng dần theo TCTL - DTB - Lớp - Năm sinh - Họ và tên -  MSHV",
	L"Sắp xếp danh sách học viên tăng dần theo MSHV - Họ và Tên - Năm sinh - Lớp - DTB - TCTL",
	L"Sắp xếp danh sách học viên tăng dần theo TCTL - DTB - Lớp - Năm sinh - Họ và tên -  MSHV"
};

wstring deletes[] = {
	L"Thoát luôn đi ngủ",
	L"Quay về trang trước",

	L"Xóa học viên theo MSHV",
	L"Xóa học viên theo Họ và Tên",
	L"Xóa học viên theo năm sinh",
	L"Xóa học viên theo lớp",

	L"Xóa học viên có điểm trung bình >= x",
	L"Xóa học viên có điểm trung bình <= x",
	L"Xóa học viên có điểm trung bình thấp nhất",
	L"Xóa học viên có điểm trung bình cao nhất",

	L"Xóa học viên có tctl >= x",
	L"Xóa học viên có tctl <= x",
	L"Xóa học viên có tctl thấp nhất",
	L"Xóa học viên có tctl cao nhất"
};

wstring modified[] = {
	L"Thoát luôn đi ngủ",
	L"Quay về trang trước",

	L"Sửa thông tin học viên theo MSHV",
	L"Sửa thông tin học viên theo Ho va ten",
	L"Sửa thông tin học viên theo nam sinh",
	L"Sửa thông tin học viên theo lop",

	L"Sửa thông tin học viên có điểm trung bình >= x",
	L"Sửa thông tin học viên có điểm trung bình <= x",
	L"Sửa thông tin học viên có điểm trung bình thấp nhất",
	L"Sửa thông tin học viên có điểm trung bình cao nhất",

	L"Sửa thông tin học viên có tctl >= x",
	L"Sửa thông tin học viên có tctl <= x",
	L"Sửa thông tin học viên có tctl thấp nhất",
	L"Sửa thông tin học viên có tctl cao nhất"
};

wstring out[] = {
	L"Thoát luôn đi ngủ",
	L"Quay về trang trước",

	L"Xuất danh sách học viên theo cùng MSHV",
	L"Xuất danh sách học viên theo cùng Họ",
	L"Xuất danh sách học viên theo cùng Họ lót",
	L"Xuất danh sách học viên theo cùng Tên",
	L"Xuất danh sách học viên theo cùng năm sinh",
	L"Xuất danh sách học viên theo cùng lớp",
	L"Xuất danh sách học viên theo cùng mức điểm trung bình",
	L"Xuất danh sách học viên theo cùng mức tctl"
};

wstring other[] = {
	L"Thoát luôn đi ngủ",
	L"Quay về trang trước",

	L"Thêm một học viên vào đầu danh sách",
	L"Thêm một học viên vào cuối danh sách",

	L"Tính tổng tất cả điểm trung bình của học viên",
	L"Tính tổng tất cả tctl của học viên"
};