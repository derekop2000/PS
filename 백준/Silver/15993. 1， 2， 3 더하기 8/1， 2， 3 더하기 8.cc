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
	long long int dp[100'001][2] = {0};
	dp[1][0] = 1;
	dp[1][1] = 0;
	dp[2][0] = 1;
	dp[2][1] = 1;
	dp[3][0] = 2;
	dp[3][1] = 2;
	for (int i = 4; i <= 100000; i++)
	{
		dp[i][0] = dp[i - 1][1] + dp[i - 2][1] + dp[i - 3][1];
		dp[i][1] = dp[i - 1][0] + dp[i - 2][0] + dp[i - 3][0];
		dp[i][0] %= 1000000009;
		dp[i][1] %= 1000000009;
	}
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		cout << dp[n][0] << " " << dp[n][1] << "\n";
	}
}