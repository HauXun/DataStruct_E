#define MAX 10
//Khoi dau cac buoc di cua ngua có thể co
int a[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int b[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
//Khai bao nguyen mau cac ham
void Try(int i, int x, int y, int h[MAX][MAX], int n, int& slg);
void Xuat_HanhTrinh(int h[MAX][MAX], int n);
void Init(int h[MAX][MAX], int n);
//************************************
//Thu tuc de quy ngua thu tu o co toa do (x,y) di buoc ke tiep
//Xuat hanh trinh neu di het cac o
void Try(int i, int x, int y, int h[MAX][MAX], int n, int& slg)
{
	int k, u, v;
	for (k = 0; k <= 7; k++)
	{
		u = x + a[k];
		v = y + b[k];
		if (1 <= u && u <= n && 1 <= v && v <= n && h[u][v] == 0)
		{
			h[u][v] = i;
			if (i < n * n)
				Try(i + 1, u, v, h, n, slg);
			else
			{
				slg++;
				cout << "\nLoi giai thu " << slg << " :";
				Xuat_HanhTrinh(h, n);
			} h
				[u][v] = 0;
		}
	}
}
// *************************
//Xua ma tran h : hanh trinh cua ngua
void Xuat_HanhTrinh(int h[MAX][MAX], int n)
{
	int i, j;
	cout << setiosflags(ios::left);
	for (i = 1; i <= n; i++)
	{
		cout << endl << endl;
		for (j = 1; j <= n; j++)
		{
			cout << setw(5) << h[i][j];
		}
	}
	cout << endl << endl;
}
// *************************
//Khoi tao h
void Init(int h[MAX][MAX], int n)
{
	int i, j;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			h[i][j] = 0;
}
// *************************