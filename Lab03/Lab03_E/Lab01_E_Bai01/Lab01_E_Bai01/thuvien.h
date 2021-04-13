#define MAX 100

typedef int DaySo[MAX];

int File_Array(char* filename, DaySo a, int& n)
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

void XuatMang(DaySo a, int n)
{
	cout << "\n";
	for (int i = 0; i < n; i++)
		cout << a[i] << '\t';
	cout << "\n";
}

void Copy(DaySo b, DaySo a, int n)
{
	for (int i = 0; i < n; i++)
		b[i] = a[i];
}

void Selection_Left(DaySo a, int n)
{
	int csMin;
	for (int i = 0; i < n - 1; i++)
	{
		csMin = i;
		for (int j = i + 1; j < n; j++)
		{
			if (a[csMin] > a[j])
				csMin = j;
		}
		swap(a[i], a[csMin]);
	}
}

void Selection_Right(DaySo a, int n)
{
	int csMax;
	for (int i = n - 1; i >= 1; i--)
	{
		csMax = i;
		for (int j = n - 1; j >= 0; j--)
		{
			if (a[csMax] < a[j])
				csMax = j;
		}
		swap(a[i], a[csMax]);
	}
}

void Selection_Right_Left(DaySo a, int n)
{
	int csMin, csMax;
	for (int i = 0; i < n / 2; i++)
	{
		csMin = i;
		csMax = n - 1 - i;
		for (int j = i; j < n - i; j++)
		{
			if (a[csMin] > a[j])
				csMin = j;
			if (a[csMax] < a[j])
				csMax = j;
		}
		if (csMin == n - 1 - i)
		{
			swap(a[i], a[csMin]);
			if (csMax != i)
				swap(a[csMax], a[n - 1 - i]);
		}
		else
		{
			swap(a[csMax], a[n - 1 -i]);
			swap(a[csMin], a[i]);
		}
	}
}

void Insertion_Left(DaySo a, int n)
{
	int k, x;
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (a[i] < a[j])
			{
				x = a[i];
				k = i;
				while (k != j)
				{
					a[k] = a[k - 1];
					k--;
				}
				a[j] = x;
			}
		}
	}
}

void Insertion_Right(DaySo a, int n)
{
	int k, x;
	for (int i = n - 2; i >= 0; i--)
	{
		for (int j = n - 1; j >= i; j--)
		{
			if (a[i] > a[j])
			{
				x = a[i];
				k = i;
				while (k <= j)
				{
					a[k++] = a[k + 1];
				}
				a[j] = x;
			}
		}
	}
}

void BinaryInsertion(DaySo a, int n)
{
	int l, r, mid;
	int x;
	for (int i = 1; i < n; i++)
	{
		l = 0, r = i - 1;
		x = a[i];
		while (l <= r)
		{
			mid = (l + r) / 2;
			if (x < a[mid])
				r = mid - 1;
			else
				l = mid + 1;
		}
		for (int j = i - 1; j >= l; j--)
			a[j + 1] = a[j];
		a[l] = x;
	}
}

void Interchange_Left(DaySo a, int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (a[j] < a[i])
				swap(a[j], a[i]);
}

void Interchange_Right(DaySo a, int n)
{
	for (int i = n - 1; i > 0; i--)
		for (int j = 0; j < i; j++)
			if (a[j] > a[i])
				swap(a[j], a[i]);
}

void Bubble_Left(DaySo a, int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = n - 1; j > i; j--)
			if (a[j] < a[j - 1])
				swap(a[j], a[j - 1]);
}

void Bubble_Right(DaySo a, int n)
{
	for (int i = n - 1; i > 0; i--)
		for (int j = 0; j < n - 1; j++)
			if (a[j] > a[j + 1])
				swap(a[j], a[j + 1]);
}