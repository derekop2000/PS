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

vector<int> visit;
void f(int now, vector<vector<int>>& v)
{
	queue<pair<int, int>> q;
	q.push({ now,0 });
	while (q.empty() == false)
	{
		auto current = q.front(); q.pop();
		if (visit[current.first] > current.second)
		{
			visit[current.first] = current.second;
			for (int i = 0; i < v[current.first].size(); i++)
			{
				int next = v[current.first][i];
				q.push({ next,current.second+1 });
			}
		}
	}
}
int main()
{
	int n, m, k, x;
	cin >> n >> m >> k >> x;
	x--;
	visit.resize(n,INT_MAX);
	vector<vector<int>> v(n);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		a--; b--;
		v[a].push_back(b);
	}
	f(x, v);
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		if (visit[i] == k)
		{
			cout << i + 1 << "\n"; cnt++;
		}
	}
	if (cnt == 0)
		cout << "-1";
}

