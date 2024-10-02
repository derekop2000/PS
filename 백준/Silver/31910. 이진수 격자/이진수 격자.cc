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
	int n;
	cin >> n;
	vector<vector<int>> arr(n, vector<int>(n));
	vector<vector<pair<long long int,long long int>>> dp(n, vector<pair<long long int,long long int>>(n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];
	dp[n - 1][n - 1].first = 1;
	for(int i=n-1;i>=0;i--)
		for (int j = n - 1; j >= 0; j--)
		{
			long long int value = 0;
			{
				int y = i;
				int x = j + 1;
				if (x < n)
				{
					dp[i][j].first = dp[y][x].first * 2;
					value = max(value, dp[y][x].second);
				}
			}
			{
				int y = i+1;
				int x = j;
				if (y < n)
				{
					dp[i][j].first = dp[y][x].first * 2;
					value = max(value, dp[y][x].second);
				}
			}
			long long int value2 = 0;
			if (arr[i][j])
				value2 = dp[i][j].first;
			dp[i][j].second = value + value2;
		}
	cout << dp[0][0].second;
}

