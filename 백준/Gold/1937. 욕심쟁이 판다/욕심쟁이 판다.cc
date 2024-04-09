#include <iostream>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <queue>
#include <map>
#include<tuple>
using namespace std;

int n;
vector<vector<int>> dp;
vector<vector<int>> arr;
int dir1[] = {-1,0,1,0};
int dir2[] = {0,1,0,-1};
int ans = 1;
int dfs(int i, int j)
{
	if (dp[i][j])return dp[i][j];
	dp[i][j] = 1;
	bool more = false;
	for (int dir = 0; dir < 4; dir++)
	{
		int ii = i + dir1[dir];
		int jj = j + dir2[dir];
		if (0 <= ii && ii < n && 0 <= jj && jj < n && arr[i][j]<arr[ii][jj])
		{
			more = true;
			dp[i][j] = max(dp[i][j],dfs(ii, jj));
		}
	}
	if(more)dp[i][j]++;
	return dp[i][j];
}

int main()
{
	cin >> n;
	arr.resize(n, vector<int>(n));
	dp.resize(n, vector<int>(n,0));
	for(int i=0;i<n;i++)
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			ans = max(ans,dfs(i, j));
		}
	cout << ans;
}
