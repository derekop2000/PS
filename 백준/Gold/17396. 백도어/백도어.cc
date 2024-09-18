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

vector<vector<int>> arr;
vector<bool> visit;
void f(int now,bool first)
{
	if (first)
	{
		Union(0, now);
	}
	visit[now] = true;
	for (int i = 0; i < arr[now].size(); i++)
	{
		int next = arr[now][i];
		if (visit[next])
			continue;
		if (findParent(now) == 0)
		{
			f(next,false);
		}
		else
		{
			Union(0, next);
			f(next,false);
		}
	}
}


int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> v(n);
	vector<vector<pair<int,int>>> arr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	v[n - 1] = 0;
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if (v[a] || v[b])
			continue;
		arr[a].push_back({b,c});
		arr[b].push_back({a,c});
	}
	priority_queue<pair<long long int, int>, vector<pair<long long int, int>>, greater<pair<long long int, int>>> q;
	q.push({ 0,0 });
	vector<long long int> dist(n,LONG_MAX);
	dist[0] = 0;
	while (q.empty() == false)
	{
		auto now = q.top(); q.pop();
		int v = now.second;
		long long int w = now.first;
		if (w > dist[v])
			continue;
		for (int i = 0; i<arr[v].size(); i++)
		{
			int V = arr[v][i].first;
			long long int W = dist[v] + arr[v][i].second;
			if (W < dist[V])
			{
				dist[V] = W;
				q.push({ W,V });
			}
		}
	}
	if (dist[n - 1] != LONG_MAX)
		cout << dist[n - 1];
	else cout << -1;
}

