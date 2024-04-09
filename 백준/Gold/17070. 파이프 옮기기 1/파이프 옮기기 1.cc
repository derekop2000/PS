#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<map>
using namespace std;

int n;
int cnt = 0;
vector<vector<bool>> arr;
void f(int x,int y,int dir) // dir 0 1 2 가로 대각 세로
{
	if (x == n - 1 && y == n - 1) { cnt++; return; }
	int x0, y0, x1, y1, x2, y2;
	x0 = x;
	y0 = y + 1;
	x1 = x + 1;
	y1 = y + 1;
	x2 = x + 1;
	y2 = y;
	if (dir == 0)
	{
		if (0 <= x0 && x0 < n && 0 <= y0 && y0 < n && arr[x0][y0])
		{
			f(x0, y0, 0);
			if (0 <= x1 && x1 < n && 0 <= y1 && y1 < n && arr[x1][y1] && 0 <= x2 && x2 < n && 0 <= y2 && y2 < n && arr[x2][y2])
			{
				f(x1, y1, 1);
			}
		}
	}
	else if (dir == 1)
	{
		if (0 <= x0 && x0 < n && 0 <= y0 && y0 < n && arr[x0][y0])
		{
			f(x0, y0, 0);
			if (0 <= x1 && x1 < n && 0 <= y1 && y1 < n && arr[x1][y1] && 0 <= x2 && x2 < n && 0 <= y2 && y2 < n && arr[x2][y2])
			{
				f(x1, y1, 1);
			}
		}
		if (0 <= x2 && x2 < n && 0 <= y2 && y2 < n && arr[x2][y2])
		{
			f(x2, y2, 2);
		}
	}
	else
	{
		if (0 <= x2 && x2 < n && 0 <= y2 && y2 < n && arr[x2][y2])
		{
			f(x2, y2, 2);
			if (0 <= x0 && x0 < n && 0 <= y0 && y0 < n && arr[x0][y0] && 0 <= x1 && x1 < n && 0 <= y1 && y1 < n && arr[x1][y1])
			{
				f(x1, y1, 1);
			}
		}
	}
}
int main()
{
	cin >> n;
	arr.resize(n, vector<bool>(n, true));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int temp;
			cin >> temp;
			if (temp)arr[i][j] = false;
		}

	}
	f(0,1,0);
	cout << cnt;
}

