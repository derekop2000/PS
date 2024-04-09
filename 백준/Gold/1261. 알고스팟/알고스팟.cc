#include <iostream>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <queue>
#include <map>
#include<tuple>
using namespace std;

int n, m;
int dir1[] = {-1,0,1,0};
int dir2[] = {0,1,0,-1};
vector<vector<int>> arr;
vector<vector<int>> dp;
void bfs()
{
	queue<pair<int, int>> q;
	q.push({ 0,0 });
	while (!q.empty())
	{
		int i = q.front().first;
		int j = q.front().second;
		q.pop();
		for (int p = 0; p < 4; p++)
		{
			int ii = i + dir1[p];
			int jj = j + dir2[p];
			if (0 <= ii && ii < n && 0 <= jj && jj < m)
			{
				if (arr[ii][jj] == 0 && dp[ii][jj] > dp[i][j])
				{
					q.push({ ii,jj });
					dp[ii][jj] = dp[i][j];
				}
				else if (arr[ii][jj] == 1 && dp[ii][jj] > dp[i][j] + 1)
				{
					q.push({ ii,jj });
					dp[ii][jj] = dp[i][j]+1;
				}
			}
		}
	} 
}
int main()
{
	cin >> m >> n;
	arr.resize(n, vector<int>(m));
	dp.resize(n, vector<int>(m,10001));
	dp[0][0] = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			char temp;
			cin >> temp;
			arr[i][j] = temp - '0';
		}
	bfs();
	cout << dp[n - 1][m - 1];
}
