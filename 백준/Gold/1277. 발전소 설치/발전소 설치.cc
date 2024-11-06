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
#include<cmath>
#include<limits>

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

int n, w;
float m;
vector<vector<pair<int, double>>> arr;
double GetDistance(int& x1, int& y1, int& x2,int& y2)
{
	return sqrt(pow(abs(x1 - x2), 2) + pow(abs(y1 - y2), 2));
}
void f()
{
	priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> q;
	q.push({ 0,0 });
	vector<double> dist(n,numeric_limits<double>::max());
	dist[0] = 0;
	while (q.empty()==false)
	{
		auto current = q.top(); q.pop();
		double w = current.first;
		int v = current.second;
		if (w > dist[v])
			continue;
		for (int i = 0; i < arr[v].size(); i++)
		{
			double W = w + arr[v][i].second;
			int V = arr[v][i].first;
			if (W < dist[V])
			{
				dist[V] = W;
				q.push({ W,V });
			}
		}
	}
	cout << (int)(dist[n - 1] * 1000);
}
int main()
{
	cin >> n >> w >> m;
	arr.resize(n);
	vector<pair<int, int>> pos(n);
	for (int i = 0; i < n; i++)
	{
		cin >> pos[i].first >> pos[i].second;
	}
	for(int i=0;i<n;i++)
		for (int j = i + 1; j < n; j++)
		{
			double dist = GetDistance(pos[i].first, pos[i].second, pos[j].first, pos[j].second);
			if (dist > m)
				continue;
			arr[i].push_back({ j,dist });
			arr[j].push_back({ i,dist });
		}
	for (int i = 0; i < w; i++)
	{
		int a, b;
		cin >> a >> b;
		a--; b--;
		arr[a].push_back({ b,0 });
		arr[b].push_back({ a,0 });
	}
	f();
}
