#define MAX 100

typedef int DaySo[MAX];

int File_Reader(char* filename, DaySo a, int& n)
{
	ifstream in(filename);
	if (!in)
		return 0;
	in >> n;
	for (int i = 0; i < n; i++)
		in >> a[i];
	in.close();
	return 1;
}

void Output(DaySo a, int n)
{
	cout << endl;
	for (int i = 0; i < n; i++)
		cout << a[i] << "\t";
	cout << "\n";
}

void Copy(DaySo b, DaySo a, int n)
{
	for (int i = 0; i < n; i++)
		b[i] = a[i];
}

// Hàm chọn trực tiếp
// Tại mỗi bước, đưa giá trị nhỏ nhất về đầu mảng
void Selection_L(DaySo a, int n)
{
	int cs_min;
	for (int i = 0; i < n - 1; i++)
	{
		cs_min = i;
		for (int j = i + 1; j < n; j++)
			if (a[cs_min] > a[j])
				cs_min = j;
		swap(a[i], a[cs_min]);
	}
}

// Tại mỗi bước chèn phần tử hiện hành vào mảng con bên trái tăng dần
void Insertion_L(DaySo a, int n)
{
	int x, pos;
	for (int i = 1; i < n; i++)
	{
		x = a[i];
		for (pos = i - 1; (pos >= 0) && (a[pos] > x); pos--)
			a[pos + 1] = a[pos];
		a[pos + 1] = x;
	}
}

// Đỗi chổ trực tiếp, tại mỗi bước đưa giá trị nhỏ nhất về đầu mảng
void Interchange_L(DaySo a, int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (a[i] > a[j])
				swap(a[i], a[j]);
}

// Tại mỗi bước đưa giá trị nhỏ nhất về đầu mảng
void Buble_L(DaySo a, int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = n - 1; j > i; j--)
			if (a[j - 1] > a[j])
				swap(a[j - 1], a[j]);
}

// Chèn nhị phân
void Binary_Insertion(DaySo a, int n)
{
	int left, right, m;
	int x;
	for (int i = 1; i < n; i++)
	{
		x = a[i];
		left = 0, right = i - 1;
		while (left <= right)
		{
			m = (left + right) / 2;
			if (x < a[m])
				right = m - 1;
			else
				left = m + 1;
		}
		for (int j = i - 1; j >= left; j--)
			a[j + 1] = a[j];
		a[left] = x;
	}
}

// Sắp theo cơ số
void Radix(int a[MAX], int n)
{
	int max, m;
	max = a[0]; m = 0;
	int k, i, j, du, thuong;
	int b0[MAX], b1[MAX], b2[MAX], b3[MAX], b4[MAX], b5[MAX],
		b6[MAX], b7[MAX], b8[MAX], b9[MAX];
	int p0, p1, p2, p3, p4, p5, p6, p7, p8, p9;
	//Tim max(a)
	for (i = 0; i < n; i++)
		if (a[i] > max)
			max = a[i];
	//Xac dinh so cac chu so cua max(a) : m
	while (max != 0)
	{
		max = max / 10;
		m++;
	}
	k = 0; //khoi tao chu so k = 0 : hang don vi
	while (k < m)
	{
		p0 = p1 = p2 = p3 = p4 = p5 = p6 = p7 = p8 = p9 = 0;//khoi tao chi so cua cac lo
		for (i = 0; i < n; i++)
		{
			//xac dinh chu so hang k cua a[i] : du
			thuong = a[i];
			for (j = 0; j <= k; j++)
			{
				du = thuong % 10;
				thuong = thuong / 10;
			}
			//Phan vao cac lo
			switch (du)
			{
			case 0:b0[p0++] = a[i];
				break;
			case 1:b1[p1++] = a[i];
				break;
			case 2:b2[p2++] = a[i];
				break;
			case 3:b3[p3++] = a[i];
				break;
			case 4:b4[p4++] = a[i];
				break;
			case 5:b5[p5++] = a[i];
				break;
			case 6:b6[p6++] = a[i];
				break;
			case 7:b7[p7++] = a[i];
				break;
			case 8:b8[p8++] = a[i];
				break;
			case 9:b9[p9++] = a[i];
				break;
			}
		}//Phan xong vao cac lo khi xet hang k
		//Noi lai theo trinh tu de co day a tang theo hang k
		j = 0;
		for (i = 0; i < p0; i++)
			a[j++] = b0[i];
		for (i = 0; i < p1; i++)
			a[j++] = b1[i];
		for (i = 0; i < p2; i++)
			a[j++] = b2[i];
		for (i = 0; i < p3; i++)
			a[j++] = b3[i];
		for (i = 0; i < p4; i++)
			a[j++] = b4[i];
		for (i = 0; i < p5; i++)
			a[j++] = b5[i];
		for (i = 0; i < p6; i++)
			a[j++] = b6[i];
		for (i = 0; i < p7; i++)
			a[j++] = b7[i];
		for (i = 0; i < p8; i++)
			a[j++] = b8[i];
		for (i = 0; i < p9; i++)
			a[j++] = b9[i];
		k++; //xet tiep hang k lon hon, khi k = m thi dung
	}
}