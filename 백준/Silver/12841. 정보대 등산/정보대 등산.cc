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

using namespace std;

int dir[][2] = { {-1,0}, {0,1}, {1,0} ,{0,-1} };

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

int n;
vector<int> a;
vector<int> b;
vector<int> c;
int point = 1;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		c.push_back(temp);
	}
	for (int i = 0; i < n-1; i++)
	{
		int temp;
		cin >> temp;
		a.push_back(temp);
	}
	for (int i = 0; i < n-1; i++)
	{
		int temp;
		cin >> temp;
		b.push_back(temp);
	}
	vector<vector<long long int>> dp(n, vector<long long int>(2));
	dp[0][0] = 0;
	dp[0][1] = c[0];
	for (int i = 1; i < n; i++)
	{
		dp[i][0] = dp[i - 1][0] + a[i - 1];
		long long int l = dp[i][0] + c[i];
		long long int u = dp[i - 1][1] + b[i - 1];
		if (l < u)
		{
			dp[i][1] = l;
			point = i+1;
		}
		else
		{
			dp[i][1] = u;
		}
	}
	cout << point<<" "<<dp[n - 1][1];
}