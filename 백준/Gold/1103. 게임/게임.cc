#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
#include<memory.h>
#include<string>
#include<sstream>
#include<algorithm>
#include<map>
#include<set>
#include<iomanip>
#include<climits>
using namespace std;


int n, m;
vector<vector<int>> arr;
vector<vector<int>> dp;
vector < vector < bool >> visit;
int dir[4][2] = { {-1,0}, {0,1} ,{1,0}, {0,-1} };
bool infinite = false;
int f(int y, int x,int floor)
{
	if (!(0 <= y && y < n && 0 <= x && x < m))
	{
		return 0;
	}
	if (arr[y][x] == 0)
	{
		return 0;
	}
	if (visit[y][x])
	{
		infinite = true;
		return 0;
	}
	if (dp[y][x] > 0)return dp[y][x];
	visit[y][x] = true;
	int re = 0;
	for (int i = 0; i < 4; i++)
	{
		int multiply = arr[y][x];
		int yy = y + dir[i][0]* multiply;
		int xx = x + dir[i][1]* multiply;
		re = max(re,f(yy, xx, floor + 1));
	}
	visit[y][x] = false;
	dp[y][x] = re + 1;
	return re+1;
}
int main()
{
	cin >> n >> m;
	arr.resize(n, vector<int>(m));
	dp.resize(n, vector<int>(m,-1));
	visit.resize(n, vector<bool>(m));
	for(int i=0;i<n;i++)
		for (int j = 0; j < m; j++)
		{
			char c;
			cin >> c;
			if (c == 'H')
				arr[i][j] = 0;
			else arr[i][j] = c - '0';
		}
	f(0, 0,0);
	if (infinite)
	{
		cout << "-1";
	}
	else cout << dp[0][0];
}