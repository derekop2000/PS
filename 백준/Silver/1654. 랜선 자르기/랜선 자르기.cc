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

int f(vector<int>& buildTime, vector<vector<int>>& arr, vector<int>& dp, int v)
{
	if (dp[v] != -1)return dp[v];
	int reValue = buildTime[v];
	int bigValue = 0;
	for (int i = 0; i < arr[v].size(); i++)
	{
		bigValue = max(bigValue, f(buildTime, arr, dp, arr[v][i]));
	}
	dp[v] = reValue + bigValue;
	return reValue+bigValue;
}
int main()
{
	int n, k;
	cin >> k >> n;
	vector<int> v(k);
	for (int i = 0; i < k; i++)
		cin >> v[i];
	unsigned int s = 1;
	unsigned int e = INT_MAX;
	int ans=0;
	while (s <= e)
	{
		unsigned int mid = (s + e) / 2;
		int cnt = 0;
		for (int i = 0; i < k; i++)
		{
			cnt += v[i] / mid;
		}
		if (cnt >= n)
		{
			s = mid + 1;
			ans = mid;
		}
		else
		{
			e = mid - 1;
		}
	}
	cout << ans;
}