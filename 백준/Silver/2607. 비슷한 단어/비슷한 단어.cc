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
	int n;
	cin >> n;
	string str;
	cin >> str;
	vector<int> v(26);
	for (int i = 0; i < str.size(); i++)
	{
		v[str[i] - 'A']++;
	}
	int ans = 0;
	for (int i = 0; i < n - 1; i++)
	{
		string str2;
		cin >> str2;
		int cnt = 1;
		if (abs((int)(str.size() - str2.size())) > 1)continue;
		if (str2.size() < str.size())cnt--;
		auto v2 = v;
		bool can = true;
		for (int j = 0; j < str2.size(); j++)
		{
			char c = str2[j];
			if (--v2[c - 'A'] < 0)cnt--;
			if (cnt < 0)
			{
				can = false;
				break;
			}
		}
		if (can)
			ans++;
	}
	cout << ans;
}