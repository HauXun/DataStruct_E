#define MAX 100

typedef int DaySo[MAX];

int TapTin_Mang1Chieu(char* filename, int a[MAX], int& n)
{
	ifstream in(filename);
	if (!in)
	{
		return 0;
	}
	in >> n;
	for (int i = 0; i < n; i++)
		in >> a[i];
	in.close();
	return 1;
}

void XuatMang(int a[MAX], int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << "\t";
}

int LinearSearch_First(int a[MAX], int n, int x)
{
	int i = 0;
	while ((i < n) && (a[i] != x))
		i++;
	if (i == n)
		return -1;
	return i;
}

int LinearSearch_First_Guards(int a[MAX], int n, int x)
{
	int i = 0;
	a[n] = x;
	while (a[i] != x)
		i++;
	if (i == n)
		return -1;
	return i;
}

int LinearSearch_Last(int a[MAX], int n, int x)
{
	int i = n - 1;
	while ((i >= -1) && (a[i] != x))
		i--;
	if (i == -1)
		return i;
	return i;
}

int LinearSearch_Index(int a[MAX], int n, int x)
{
	int result = -1;
	for (int i = 0; i < n; i++)
		if (a[i] == x)
			return 1;
	return result;
}