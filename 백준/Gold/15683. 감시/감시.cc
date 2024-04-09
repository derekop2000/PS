#include<iostream>
#include<vector>
#include<memory>
#include<math.h>
using namespace std;

int dir1[] = {-1,0,1,0};
int dir2[] = {0,1,0,-1};
vector<vector<int>> arr;
vector<vector<int>> arr2;
vector<vector<int>> cctv;
int cctv_size=0;
int n, m;
int ans = 64;
void setArr2()
{
	for(int i=0;i<n;i++)
		for (int j = 0; j < m; j++)
		{
			arr2[i][j] = arr[i][j];
		}
}
void f3(int i,int j,int type,int dir)
{
	vector<int> dirs;
	switch (type)
	{
	case 1: {dirs.push_back(0); break; }
	case 2: {dirs.push_back(3);dirs.push_back(1); break; }
	case 3: {dirs.push_back(0); dirs.push_back(1); break; }
	case 4: {dirs.push_back(0); dirs.push_back(3); dirs.push_back(1); break; }
	case 5: {dirs.push_back(0); dirs.push_back(1); dirs.push_back(2); dirs.push_back(3); break; }
	}
	for (int i = 0; i < dirs.size(); i++)
	{
		if (type == 5)break;
		dirs[i] = (dirs[i] + dir) % 4;
	}
	for (int q = 0; q < dirs.size(); q++)
	{
		int ii = i;
		int jj = j;
		while (1)
		{
			ii += dir1[dirs[q]];
			jj += dir2[dirs[q]];
			if (0 <= ii && ii < n && 0 <= jj && jj < m && arr2[ii][jj] != 6)
			{
				if (arr2[ii][jj] == 0)
					arr2[ii][jj] = 7;
			}
			else break;
		}
	}
}
void f2()
{
	setArr2();
	for (int i = 0; i < cctv_size; i++)
	{
		f3(cctv[i][0], cctv[i][1], cctv[i][2], cctv[i][3]);
	}
	int temp = 0;
	for(int i=0;i<n;i++)
		for (int j = 0; j < m; j++)
		{
			if (arr2[i][j]==0)
				temp++;
		}
	if (temp < ans) ans = temp;
}
void f(int floor)
{
	if (floor == cctv_size)
	{
		f2();
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		cctv[floor][3] = i;
		f(floor + 1);
	}
}
int main()
{
	cin >> n >> m;
	arr.resize(n, vector<int>(m, 0));
	arr2.resize(n, vector<int>(m, 0));
	for(int i=0;i<n;i++)
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
			if (1 <= arr[i][j] && arr[i][j] <= 5)
			{
				cctv.push_back(vector<int>());
				cctv[cctv_size].push_back(i);
				cctv[cctv_size].push_back(j);
				cctv[cctv_size].push_back(arr[i][j]);
				cctv[cctv_size].push_back( 0 );
				cctv_size++;
			}
		}
	f(0);
	cout << ans;
}
