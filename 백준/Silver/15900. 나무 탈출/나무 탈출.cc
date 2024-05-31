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

vector<vector<int>> arr;
vector<int> visit;
pair<int,long long int> f(int now)
{
	int childCnt = 0;
	long long int localAns = 0;
	visit[now] = true;
	for (int i = 0; i < arr[now].size(); i++)
	{
		int next = arr[now][i];
		if (visit[next] == false)
		{
			auto temp = f(next);
			childCnt += temp.first;
			localAns += temp.second;
		}
	}
	if (now == 0)
		return { 0,localAns };
	else
	{
		long long int temp = 0;
		if (localAns + childCnt == 0)
			temp = 1;
		else temp = localAns + childCnt;
		return { max(childCnt,1),temp };
	}
}
int main()
{
	int n;
	cin >> n;
	visit.resize(n);
	arr.resize(n);
	for (int i = 0; i < n - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		a--; b--;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	if (f(0).second % 2 == 1)
		cout << "Yes";
	else cout << "No";
}