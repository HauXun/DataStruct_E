#define MAX 20

int n, k;
int a[MAX], b[MAX];
int dem;

//Xuat day nhi phan, hoan vi, to hop
void Xuat_KQ(int a[MAX], int n)
{
	cout << "KQ" << setw(3) << dem << ":";
	for (int i = 1; i <= n; i++)
		cout << setw(2) << a[i];
	cout << "\n";
}

//Day nhi phan chieu dai n
void LietKe_DayNP(int i) //Try
{
	for (int j = 0; j <= 1; j++)
	{
		a[i] = j;
		if (i < n)
			LietKe_DayNP(i + 1);
		else
		{
			dem++;
			Xuat_KQ(a, n);
		}
	}
}

//Khoi tao hv
void KhoiTao_danhdau()
{
	for (int i = 1; i <= n; i++)
		b[i] = 1;
}

//To hop chap k trong n
void LietKe_TH(int i) //Try
{
	for (int j = a[i - 1] + 1; j <= n - k + i; j++)
	{
		a[i] = j;
		if (i == k)
		{
			dem++;
			Xuat_KQ(a, k);
		}
		else
			LietKe_TH(i + 1);
	}
}

//Hoan vi n so nguyen duong dau tien
void LietKe_HV(int i) //Try
{
	for (int j = 1; j <= n; j++)
		if (b[j])
		{
			a[i] = j;
			b[j] = 0;
			if (i == n)
			{
				dem++;
				Xuat_KQ(a, n);
			}
			else
				LietKe_HV(i + 1);
			b[j] = 1;
		}
}