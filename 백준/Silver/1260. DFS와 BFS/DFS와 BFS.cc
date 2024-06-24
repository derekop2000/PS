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

int dir[][2] = { {-1,0}, {0,1}, {1,0} ,{0,-1} };

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

int n, m, v;
vector<vector<int>> arr;
vector<bool> visit;
void d(int now)
{
	visit[now] = true;
	cout << now+1 << " ";
	for (int i = 0; i < arr[now].size(); i++)
	{
		int next = arr[now][i];
		if (visit[next] == false)
		{
			d(next);
		}
	}
}
void b(int now)
{
	queue<int> q;
	q.push(now);
	visit[now] = true;
	while (q.empty()==false)
	{
		int current = q.front();
		q.pop();
		cout << current+1 << " ";
		for (int i = 0; i < arr[current].size(); i++)
		{
			int next = arr[current][i];
			if (visit[next] == false)
			{
				visit[next] = true;
				q.push(next);
			}
		}
	}
}
int main()
{
	cin >> n >> m >> v;
	v--;
	arr.resize(n);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		a--; b--;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	for (int i = 0; i < n; i++)
	{
		sort(arr[i].begin(), arr[i].end());
	}
	visit.resize(n, false);
	d(v);
	cout << "\n";
	visit.clear();
	visit.resize(n, false);
	b(v);

}

