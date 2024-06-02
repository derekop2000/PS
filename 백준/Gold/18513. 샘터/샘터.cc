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
	int minValue = 100100000;
	int n, k;
	cin >> n >> k;
	queue<pair<long long int,long long int>> q;
	vector<bool> visit(200200001);
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		temp += minValue;
		visit[temp] = true;
		if(temp>0)
			q.push({ temp - 1,temp });
		if(temp<minValue*2)
			q.push({temp + 1,temp});
	}
	long long int ans = 0;
	while (k)
	{
		auto temp = q.front(); q.pop();
		if (visit[temp.first] == false)
		{
			ans += abs(temp.first - temp.second);
			if (temp.first > 0 && visit[temp.first-1]==false)
				q.push({ temp.first - 1 ,temp.second});
			if (temp.first < minValue * 2 && visit[temp.first +1] == false)
				q.push({ temp.first + 1 ,temp.second});
			k--;
			visit[temp.first] = true;
		}
	}
	cout << ans;
}