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



vector<bool> visit;
vector<vector<int>> arr;
int ans = -1;
int b;
void f(int now, int cnt)
{
	if (now == b)
	{
		ans = cnt;
		return;
	}
	visit[now] = true;
	for (int i = 0; i < arr[now].size(); i++)
	{
		int next = arr[now][i];
		if (visit[next] == false)
		{
			f(next, cnt + 1);
		}
	}
}
int main()
{
	int n;
	cin >> n;
	arr.resize(n);
	visit.resize(n,false);
	int a;
	cin >> a >> b;
	a--; b--;
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int temp, temp2;
		cin >> temp >> temp2;
		temp--; temp2--;
		arr[temp].push_back(temp2);
		arr[temp2].push_back(temp);
	}
	f(a,0);
	cout << ans;
}