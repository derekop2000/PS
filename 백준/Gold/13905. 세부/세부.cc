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

int n, m,s,e;
vector<vector<pair<int, int>>> arr;
void f()
{
	vector<int> dist(n,0);
	vector<bool> visit(n, false);
	dist[s] = 1000000;
	priority_queue<pair<int, int>> q;
	q.push({ 1000000,s });
	while (q.empty() == false)
	{
		auto temp = q.top(); q.pop();
		int w = temp.first;
		int v = temp.second;
		if (visit[v])
			continue;
		visit[v] = true;
		for (int i = 0; i < arr[v].size(); i++)
		{
			int W = min(w , arr[v][i].second);
			int V = arr[v][i].first;
			if (visit[V])
				continue;
			if (W > dist[V])
			{
				dist[V] = W;
				q.push({ W,V });
			}
		}
	}
	cout << dist[e];
}
int main()
{
	cin >> n >> m >> s >> e;
	arr.resize(n);
	s--; e--;
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		a--; b--;
		arr[a].push_back({ b,c });
		arr[b].push_back({ a,c });
	}
	f();
}