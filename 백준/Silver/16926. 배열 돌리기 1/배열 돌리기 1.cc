#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
#include<string>
#include<set>
#include<map>
#include<cmath>
#include <iomanip>
#include<climits>

using namespace std;

int n, m, rotation;
vector<vector<int>> arr;
vector<vector<int>> arr2;
int dir1[] = {1,0,-1,0};
int dir2[] = {0,1,0,-1};
int nn, mm;
int dir;
pair<int, int> f2(int r, int c)
{
	int temp = rotation % (nn*2+mm*2-4);
	dir = 0;
	int temp_r = 0;
	int temp_c = 0;
	for (int i = 0; i < temp; i++)
	{
		temp_r += dir1[dir];
		temp_c += dir2[dir];
		if (0 <= temp_r && temp_r < nn && 0 <= temp_c && temp_c < mm)
		{
			continue;
		}
		temp_r -= dir1[dir];
		temp_c -= dir2[dir];
		dir = (dir + 1) % 4;
		temp_r += dir1[dir];
		temp_c += dir2[dir];
	}
	return make_pair( r + temp_r,c + temp_c );
}
void f(int r,int c)
{
	pair<int, int> temp = f2(r, c);
	int temp_r = r;
	int temp_c = c;
	int temp_dir = 0;
	while (true)
	{
		arr2[temp.first][temp.second] = arr[temp_r][temp_c];
		temp_r += dir1[temp_dir];
		temp_c += dir2[temp_dir];
		if (!(0 <= temp_r-r && temp_r-r < nn && 0 <= temp_c-c && temp_c-c < mm))
		{
			temp_r -= dir1[temp_dir];
			temp_c -= dir2[temp_dir];
			temp_dir = (temp_dir + 1) % 4;
			temp_r += dir1[temp_dir];
			temp_c += dir2[temp_dir];
		}
		//
		temp.first += dir1[dir];
		temp.second += dir2[dir];
		if (!(0 <= temp.first - r && temp.first - r < nn && 0 <= temp.second - c && temp.second - c < mm))
		{
			temp.first -= dir1[dir];
			temp.second -= dir2[dir];
			dir = (dir + 1) % 4;
			temp.first += dir1[dir];
			temp.second += dir2[dir];
		}
		if (temp_r == r && temp_c == c)break;
	}
	nn -= 2;
	mm -= 2;
}
int main()
{
	cin >> n >> m >> rotation;
	nn = n; mm = m;
	arr.resize(n, vector<int>(m));
	arr2.resize(n, vector<int>(m));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];
	int temp = min(n, m) / 2;
	for (int i = 0; i < temp; i++)
		f(i, i);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << arr2[i][j]<<" ";
		cout << "\n";
	}
}