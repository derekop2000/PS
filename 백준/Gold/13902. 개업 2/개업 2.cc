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


#include<limits>
int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> arr(m);
	for (int i = 0; i < m; i++)cin >> arr[i];
	vector<int> dp(n + 1, numeric_limits<int>::max());
	dp[0] = 0;
	for (int i = 0; i < m; i++)
	{
		dp[arr[i]] = 1;
		for (int j = 0; j < m; j++)
		{
			if (i == j)continue;
			int temp = arr[i] + arr[j];
			if (temp <= n)
				dp[temp] = 1;
		}
	}
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (dp[i - j] != numeric_limits<int>::max() && dp[j] != numeric_limits<int>::max())
				dp[i] = min(dp[i], dp[i - j] + dp[j]);
		}
	}
	if (dp[n] == numeric_limits<int>::max())
		cout << "-1";
	else cout << dp[n];
}