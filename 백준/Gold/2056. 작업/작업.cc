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

vector<int> operTime;
vector<vector<int>> arr;
vector<pair<int,int>> etc;
int ans = 0;
void f(int now)
{
	if (arr[now].size() == 0)
	{
		ans = max(ans, etc[now].first + operTime[now]);
		return;
	}
	for (int i = 0; i < arr[now].size(); i++)
	{
		int next = arr[now][i];
		etc[next].second--;
		etc[next].first = max(etc[next].first, etc[now].first + operTime[now]);
		if (etc[next].second == 0)
		{
			f(next);
		}
	}
}
int main()
{
	int n;
	cin >> n;
	operTime.resize(n);
	arr.resize(n);
	etc.resize(n, {0,0});
	vector<int> firstList;
	for (int i = 0; i < n; i++)
	{
		int m, k;
		cin >> operTime[i] >> k;
		if (k == 0)
			firstList.push_back(i);
		etc[i].second = k;
		for (int j = 0; j < k; j++)
		{
			int temp;
			cin >> temp;
			temp--;
			arr[temp].push_back(i);
		}
	}
	for (auto value : firstList)
	{
		f(value);
	}
	cout << ans;
}

