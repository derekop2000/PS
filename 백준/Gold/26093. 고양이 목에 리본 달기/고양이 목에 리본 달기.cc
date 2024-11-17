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
#include <functional>
#include <unordered_set>
using namespace std;

int dir[][2] = { {-1,0}, {0,1}, {1,0} ,{0,-1},{-1,1},{1,1},{1,-1},{-1,-1} };

vector<int> parent;
int findParent(int a)
{
	if (parent[a] == a)
		return a;
	return parent[a] = findParent(parent[a]);
}
void Union(int a, int b)
{
	parent[findParent(b)] = findParent(a);
}
bool IsUnion(int a, int b)
{
	return findParent(a) == findParent(b);
}

int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> arr(n+1, vector<int>(m,0));
	vector<vector<int>> dp(n+1, vector<int>(m,0));
	for(int i=1;i<=n;i++)
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	pair<pair<int, int>, pair<int, int>> past ;
	pair<pair<int, int>, pair<int, int>> current = { {0,0} ,{0,1} };
	int ans = 0;
	for (int i = 1; i <=n; i++)
		for (int j = 0; j < m; j++)
		{
			if (j == 0)
			{
				past = current;
				current = { {-1,-1} ,{-1,-1} };
			}
			if (past.first.second != j)
			{
				dp[i][j] = arr[i][j] + past.first.first;
			}
			else dp[i][j] = arr[i][j] + past.second.first;

			if (i == n)
			{
				ans = max(ans, dp[i][j]);
			}

			if (dp[i][j] > current.second.first)
			{
				current.second = { dp[i][j],j };
				if (dp[i][j] > current.first.first)
				{
					pair<int, int> temp = current.first;
					current.first = current.second;
					current.second = temp;
				}
			}
		}
	cout << ans;
}
