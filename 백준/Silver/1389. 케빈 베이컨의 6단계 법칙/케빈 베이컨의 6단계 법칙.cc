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

int n, m;
vector<set<int>> arr;
int ans = INT_MAX;
int who;
void f(int s)
{
	vector<int> dist(n,1000);
	dist[s] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	q.push({ 0,s });
	while (q.empty() == false)
	{
		auto now = q.top(); q.pop();
		int w = now.first;
		int v = now.second;
		if (w > dist[v])
			continue;
		for(int temp : arr[v])
		{
			int V = temp;
			int W = dist[v] + 1;
			if (W < dist[V])
			{
				dist[V] = W;
				q.push({ W,V });
			}
		}
	}
	int sum = 0;
	for (int temp : dist)
		sum += temp;
	if (sum < ans)
	{
		who = s;
		ans = sum;
	}
	if (sum == ans)
	{
		if (s < who)
		{
			who = s;
		}
	}
}
int main()
{
	cin >> n >> m;
	arr.resize(n);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		a--; b--;
		arr[a].insert(b);
		arr[b].insert(a);
	}
	for (int i = 0; i < n; i++)
	{
		f(i);
	}
	cout << who+1;
}

