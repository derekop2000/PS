#include<iostream>
#include<vector>
using namespace std;
int ans = 4;
int dir1[] = {-1,0,1,0};
int dir2[] = { 0,1,0,-1};
vector<vector<int>> arr;
vector<vector<bool>> visit;
int n, m;
void f1(int floor,int cnt,int i,int j)
{
	if (floor == 5)
	{
		if (ans < cnt) ans = cnt;
		return;
	}
	visit[i][j] = true;
	cnt += arr[i][j];
	for (int q = 0; q < 4; q++)
	{
		int ii = i + dir1[q];
		int jj = j + dir2[q];
		if (0 <= ii && ii < n && 0 <= jj && jj < m && !visit[ii][jj])
		{
			f1(floor + 1, cnt, ii, jj);
		}
	}
	visit[i][j] = false;
}
void f2(int i,int j)
{
	for (int q = 0; q < 4; q++)
	{
		int cnt = arr[i][j];
		int i1 = i + dir1[(q + 1) % 4 ];
		int j1 = j + dir2[(q + 1) % 4 ];
		int i2 = i + dir1[(q + 2) % 4];
		int j2 = j + dir2[(q + 2) % 4];
		int i3 = i + dir1[(q + 3) % 4];
		int j3 = j + dir2[(q + 3) % 4];
		if (0 <= i1 && i1 < n && 0 <= i2 && i2 < n && 0 <= i3 && i3 < n && 0 <= j1 && j1 < m && 0 <= j2 && j2 < m && 0 <= j3 && j3 < m)
		{
			cnt += (arr[i1][j1]+ arr[i2][j2]+ arr[i3][j3]);
			if (ans < cnt)ans = cnt;
		}
	}
}
int main()
{
	cin >> n >> m;
	arr.resize(n, vector<int>(m));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];
	visit.resize(n, vector <bool>(m, false));
	for(int i=0;i<n;i++)
		for (int j = 0; j < m; j++)
		{
			f1(1, 0, i, j);
			f2(i, j);
		}
	cout << ans;
}