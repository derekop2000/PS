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
#include<stack>
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
	vector<vector<int>> dp(n + 1, vector<int>(m,0));
	pair<pair<int, int>, pair<int, int>> past;
	pair<pair<int, int>, pair<int, int>> current{ {0,-1} ,{0,-1} };
	int ans = 0;
	vector<vector<int>> arr(n+1, vector<int>(m));
	for(int j = 0;j<m;j++)
		for (int i = 1; i <= n; i++)
		{
			cin >> arr[i][j];
		}
	for (int i = 1; i <= n; i++)
	{
		past = current;
		current = { {0,-1} ,{0,-1} };
		for (int j = 0; j < m; j++)
		{
			int temp = arr[i][j];
			if (past.first.second == j)
			{
				if((past.first.first + temp/2) > (past.second.first + temp))
					dp[i][j] = (past.first.first + temp / 2);
				else dp[i][j] = (past.second.first + temp);
			}
			else dp[i][j] = temp + past.first.first;

			if (current.second.first < dp[i][j])
			{
				if (current.first.first < dp[i][j])
				{
					current.second = current.first;
					current.first = { dp[i][j],j };
				}
				else
				{
					current.second = { dp[i][j],j };
				}
			}

			if (i == n)
				ans = max(ans, dp[i][j]);
		}
	}
	cout << ans;
}