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

int f(pair<int, int>& a, pair<int, int>& b)
{
	return abs(a.first - b.first) + abs(a.second - b.second);
}
int main()
{
	int n, k;
	cin >> n >> k;
	vector<pair<int, int>> v(n);
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		v[i] = { a,b };
	}
	vector<vector<int>> dp(n, vector<int>(k + 1, INT_MAX));
	for (int i = 0; i <= k; i++)
		dp[0][i] = 0;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j <= k; j++)
		{
			int next = 1 + j;
			if (i + next >= n)continue;
			int distance = f(v[i], v[i + next]);
			for (int q = 0; q <= k - j; q++)
			{
				dp[i + next][q + j] = min(dp[i + next][q + j], dp[i][q] + distance);
			}
		}
	}
	cout << dp[n - 1][k];
}