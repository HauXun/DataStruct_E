#define MAX 100

typedef int DaySo[MAX];
int compare = 0, swapper = 0;

int FileStream(char* filename, DaySo a, int& n)
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
	cout << "\n";
	for (int i = 0; i < n; i++)
		cout << a[i] << "\t";
	cout << "\n";
}

void Copy(DaySo b, DaySo a, int n)
{
	for (int i = 0; i < n; i++)
		b[i] = a[i];
}

void SelectionSort(DaySo a, int n)
{
	int csMin;
	for (int i = 0; i < n - 1; i++)
	{
		csMin = i;
		for (int j = i + 1; j < n; j++)
		{
			if (a[j] < a[csMin])
			{
				csMin = j;
				compare++;
			}
		}
		swap(a[i], a[csMin]);
		swapper++;
	}
}

void InsertionSort(DaySo a, int n)
{
	int j, x;
	for (int i = 1; i < n; i++)
	{
		x = a[i];
		j = i;
		while (j > 0 && a[j - 1] > x)
		{
			compare++;
			swapper++;
			a[j] = a[j - 1];
			j--;
		}
		a[j] = x;
	}
}

void InterchangeSort(DaySo a, int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (a[i] > a[j])
			{
				compare++;
				swapper++;
				swap(a[i], a[j]);
			}
}

void BubbleSort(DaySo a, int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = n - 1; j > i; j--)
			if (a[j] < a[j - 1])
			{
				compare++;
				swapper++;
				swap(a[j], a[j - 1]);
			}
}