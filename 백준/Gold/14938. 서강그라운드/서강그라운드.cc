#include <iostream>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <queue>
#include <map>
#include<tuple>
using namespace std;

int n, m, r;
vector<int> items;
vector<vector<pair<int,int>>> routes;
int ans = 0;
void dks(int start)
{
	vector<int> dist(n, 2147483647);
	dist[start] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	q.push(make_pair(0, start));
	while (!q.empty())
	{
		int w = q.top().first;
		int v = q.top().second;
		q.pop();
		if (w > dist[v])continue;
		for (int i = 0; i < routes[v].size(); i++)
		{
			int V = routes[v][i].first;
			int W = routes[v][i].second+ w;
			if (W < dist[V])
			{
				dist[V] = W;
				q.push(make_pair(W, V));
			}
		}
	}
	int temp_ans = 0;
	for (int i = 0; i < n; i++)
	{
		if (dist[i] <= m)
		{
			temp_ans += items[i];
		}
	}
	ans = max(ans, temp_ans);
}
int main()
{
	cin >> n >> m >> r;
	items.resize(n);
	routes.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> items[i];
	}
	for (int i = 0; i < r; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		routes[a - 1].push_back(make_pair(b - 1, c));
		routes[b - 1].push_back(make_pair(a - 1, c));
	}
	for (int i = 0; i < n; i++)
	{
		dks(i);
	}
	cout << ans;
}             
