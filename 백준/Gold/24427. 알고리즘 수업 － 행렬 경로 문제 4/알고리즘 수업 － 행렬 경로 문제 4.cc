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
	vector<vector<pair<int, bool>>> arr;
	int n;
	cin >> n;
	arr.resize(n, vector<pair<int, bool>>(n));
	for(int i=0;i<n;i++)
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j].first;
		}
	int m;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		arr[a-1][b-1].second = true;
	}
	vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(n, {-1, -1 }));
	dp[0][0].first = arr[0][0].first;
	for(int i =0;i<n;i++)
		for (int j = 0; j < n; j++)
		{
			{
				int ii = i - 1;
				int jj = j;
				if (ii >= 0)
				{
					dp[i][j].first = max(dp[i][j].first, dp[ii][jj].first + arr[i][j].first);
					if(dp[ii][jj].second != -1)
						dp[i][j].second = max(dp[i][j].second, dp[ii][jj].second + arr[i][j].first);
				}
			}

			{
				int ii = i;
				int jj = j -1 ;
				if (jj >= 0)
				{
					dp[i][j].first = max(dp[i][j].first, dp[ii][jj].first + arr[i][j].first);
					if (dp[ii][jj].second != -1)
						dp[i][j].second = max(dp[i][j].second, dp[ii][jj].second + arr[i][j].first);
				}
			}
			if (arr[i][j].second)
			{
				dp[i][j].second = max(dp[i][j].second, dp[i][j].first);
			}
		}
	cout << dp[n - 1][n - 1].second;
}
