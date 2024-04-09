#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int dir1[] = {-1,0,1,0};
int dir2[] = {0,1,0,-1};
vector<vector<int>> arr;
vector<vector<int>> arr2;
int r, c, t;
pair<int, int> pos;
void arr2init()
{
	for(int i=0;i<r;i++)
		for (int j = 0; j < c; j++)
		{
			arr2[i][j] = 0;
		}
}
void diffusion()
{
	
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
		{
			if (arr[i][j] == -1)continue;
			int cnt = 0;
			for (int q = 0; q < 4; q++)
			{
				int ii = i + dir1[q];
				int jj = j + dir2[q];
				if (0 <= ii && ii < r && 0 <= jj && jj < c && arr[ii][jj] != -1)
				{
					cnt++;
					arr2[ii][jj] += arr[i][j] / 5;
				}
			}
			arr[i][j] -= ( (arr[i][j] / 5) * cnt );
		}
	for(int i=0;i<r;i++)
		for (int j = 0; j < c; j++)
		{
			if (arr[i][j] == -1)continue;
			arr[i][j] += arr2[i][j];
		}
}
void cleaning()
{
	pair<int, int> wind;
	wind.first = pos.first-1;
	wind.second = pos.second;
	int dir = 0;
	arr[wind.first][wind.second] = 0;
	while (1)
	{
		wind.first += dir1[dir];
		wind.second += dir2[dir];
		if (wind.first == pos.first && wind.second == pos.second)
		{
			arr[wind.first + dir1[(dir + 2) % 4]][wind.second + dir2[(dir + 2) % 4]] = 0;
			break;
		}
		if (!(0 <= wind.first && wind.first <= pos.first && 0 <= wind.second && wind.second < c))
		{
			wind.first -= dir1[dir];
			wind.second -= dir2[dir];
			dir = (dir + 1) % 4;
			continue;
		}
		arr[wind.first+ dir1[(dir+2)%4] ][wind.second+ dir2[(dir + 2) % 4]] = arr[wind.first][wind.second];
	}
	wind.first = pos.first+2;
	wind.second = pos.second;
	dir = 2;
	arr[wind.first][wind.second] = 0;
	while (1)
	{
		wind.first += dir1[dir];
		wind.second += dir2[dir];
		if (wind.first == pos.first + 1 && wind.second == pos.second)
		{
			arr[wind.first + dir1[(dir + 2) % 4]][wind.second + dir2[(dir + 2) % 4]] = 0;
			break;
		}
		if (!(pos.first+1 <= wind.first && wind.first < r && 0 <= wind.second && wind.second < c))
		{
			wind.first -= dir1[dir];
			wind.second -= dir2[dir];
			dir = (dir + 3) % 4;
			continue;
		}
		arr[wind.first + dir1[(dir + 2) % 4]][wind.second + dir2[(dir + 2) % 4]] = arr[wind.first][wind.second];
	}
}
void f()
{
	for (int i = 0; i < t; i++)
	{
		arr2init();
		diffusion();
		cleaning();
	}
}
int main()
{
	cin >> r >> c >> t;
	arr.resize(r, vector<int>(c));
	arr2.resize(r, vector<int>(c));
	for(int i=0;i<r;i++)
		for (int j = 0; j < c; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == -1)
			{
				pos.first = i;
			}
		}
	pos.first--;
	pos.second = 0;
	f();
	int ans = 0;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			//cout << arr[i][j] << "  ";
			if (arr[i][j] == -1)continue;
			ans += arr[i][j];
		}//cout << "\n";
	}
	cout << ans;
}