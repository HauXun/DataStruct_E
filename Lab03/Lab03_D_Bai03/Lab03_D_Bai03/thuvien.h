#define MAX 100

typedef int DaySo[MAX];

int File_Reader(char* filename, DaySo a, int& n)
{
	ifstream in(filename);
	if (!in)
		return 0;
	n = 0;
	while (!in.eof())
	{
		in >> a[n];
		n++;
	}
	in.close();
	return 1;
}

void Output(DaySo a, int n)
{
	cout << endl;
	for (int i = 0; i < n; i++)
		cout << a[i] << "\t";
}

void Copy(DaySo b, DaySo a, int n)
{
	for (int i = 0; i < n; i++)
		b[i] = a[i];
}

// Tại mỗi bước đưa giá trị lớn nhất về cuối mảng
void Selection_R(DaySo a, int n)
{
	int cs_max;
	for (int i = 0; i < n; i++)
	{
		cs_max = n - 1 - i;
		for (int j = n - 2; i >= 0; i--)
			if (a[j] > a[cs_max])
				cs_max = j;
		swap(a[n - 1 - i], a[cs_max]);
	}
}

// Tại mỗi bước đưa giá trị lớn nhất về cuối mảng, đưa giá trị nhỏ nhất về đầu mảng
void Selection_R_L(DaySo a, int n)
{
	int cs_min, cs_max;
	for (int i = 0; i < n / 2; i++)
	{
		cs_min = i;
		cs_max = n - 1 - i;
		for (int j = i; j <= n - 1 - i; j++)
		{
			if (a[j] < a[cs_min])
				cs_min = j;
			if (a[j] > a[cs_max])
				cs_max = j;
		}
		if (cs_min == n - 1 - i)
		{
			swap(a[i], a[cs_min]);
			if (cs_max != i)
				swap(a[cs_max], a[n - i - 1]);
		}
		else
		{
			swap(a[cs_max], a[n - i - 1]);
			swap(a[i], a[cs_min]);
		}
	}
}

// Tại mỗi bước chèn phần tử hiện hành vào mảng con bên phải tăng dần
void Insertion_R(DaySo a, int n)
{
	int x, pos;
	for (int i = n - 2; i >= 0; i--)
	{
		x = a[i];
		for (pos = i + 1; (pos < n) && (a[pos] < x); pos++)
			a[pos - 1] = a[pos];
		a[pos - 1] = x;
	}
}

// Tại mỗi bước đưa giá trị lớn nhất về cuối mảng
void Interchange_R(DaySo a, int n)
{
	for (int j = n - 2; j > 0; j++)
		for (int i = 0; i < j; i++)
			if (a[i] > a[j])
				swap(a[i], a[j]);
}

// Tại mỗi bước đưa giá trị lớn nhất về cuối mảng
void Buble_R(DaySo a, int n)
{
	for (int j = n - 1; j > 0; j--)
	{
		for (int i = 0; i < n - 1; i++)
			if (a[i] > a[i + 1])
				swap(a[i + 1], a[i]);
		cout << "\nBuoc " << n - j << ":";
		Output(a, n);
		cout << "\n";
	}
	cout << "\nCo " << n - 1 << " buoc thuc hien giai thuat\n";
}

void Shaker(DaySo a, int n)
{
	int left = 0, right = n - 1;
	int k = n - 1;
	int j;
	while (left < right)
	{
		j = right;	// Khởi tạo j từ bên phải
		while (j > left)
		{
			if (a[j] < a[j - 1])
			{
				swap(a[j], a[j - 1]);
				k = j;
				cout << "\nk = " << k;
			}
			j--;
		}
		left = k;	// Xác định lại bên trái left
		j = left;	// Khởi tạo j từ bên phải
		while (j < right)
		{
			if (a[j] > a[j + 1])
			{
				swap(a[j], a[j + 1]);
				k = j;
			}
			j++;
		}
		right = k;	// Xác định lại bên phải left
	}
}