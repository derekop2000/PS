#include<iostream>
#include<vector>
#include<memory>
using namespace std;
int dir1[] = {-1,0,1,0};
int dir2[] = { 0,1,0,-1 };
int n, m;
unique_ptr<unique_ptr<int[]>[]> arr;
unique_ptr<unique_ptr<int[]>[]> arr2;
int ans = 0;
void f2(int i,int j)
{
	arr2[i][j] = 3;
	for (int q = 0; q < 4; q++)
	{
		int ii = i + dir1[q];
		int jj = j + dir2[q];
		if (0 <= ii && ii < n && 0 <= jj && jj < m && arr2[ii][jj] == 0)
			f2(ii, jj);
	}
}
void f()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			if (arr2[i][j] == 2)
				f2(i, j);
		}
	int cnt = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			if (arr2[i][j] == 0)
				cnt++;
		}
	if (cnt > ans) ans = cnt;
}
int main()
{
	cin >> n >> m;
	arr = make_unique<unique_ptr<int[]>[]>(n);
	arr2 = make_unique<unique_ptr<int[]>[]>(n);
	for (int i = 0; i < n; i++)
	{
		arr[i] = make_unique<int[]>(m);
		arr2[i] = make_unique<int[]>(m);
	}
	for(int i=0;i<n;i++)
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	for (int z = 0; z < n * m; z++)
	{
		for (int x = z + 1; x < n * m; x++)
		{
			for (int c = x + 1; c < n * m; c++)
			{
				int i1 = z / m;
				int j1 = z % m;
				int i2 = x / m;
				int j2 = x % m;
				int i3 = c / m;
				int j3 = c % m;
				if ( !(arr[i1][j1] == 0 && arr[i2][j2] == 0 && arr[i3][j3] == 0) ) continue;
				arr[i1][j1] = 1;
				arr[i2][j2] = 1;
				arr[i3][j3] = 1;
				for(int i=0;i<n;i++)
					for (int j = 0; j < m; j++)
					{
						arr2[i][j] = arr[i][j];
					}
				f();
				arr[i1][j1] = 0;
				arr[i2][j2] = 0;
				arr[i3][j3] = 0;
			}
		}
	}
	cout << ans;
}