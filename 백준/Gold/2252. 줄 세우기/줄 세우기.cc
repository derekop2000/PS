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
vector<vector<int>> arr2;
vector<int> points;
vector<bool> visit;
void s(int node);
void s2(int node);

void f(int node)
{
	if (visit[node])
		return;
	if (arr2[node].size() == 0)
		s(node);
	for (int i = 0; i < arr2[node].size(); i++)
	{
		int next = arr2[node][i];
		f(next);
	}
}
void s(int node)
{
	visit[node] = true;
	for (int i = 0; i < arr[node].size(); i++)
	{
		int next = arr[node][i];
		if (points[next] > points[node])
			continue;
		points[next] = points[node]+1;
		s(next);
	}
	for (int i = 0; i < arr2[node].size(); i++)
	{
		int back = arr2[node][i];
		if (points[back] < points[node])
			continue;
		points[back] = points[node] - 1;
		s(back);
	}
}
void s2(int node)
{
	if (visit[node])
		return;
	visit[node] = true;
	
	for (int i = 0; i < arr[node].size(); i++)
	{
		int next = arr[node][i];
		if (visit[next])
			continue;
		s(next);
	}
}
int main()
{
	int n, m;
	cin >> n >> m;
	arr.resize(n);
	arr2.resize(n);
	points.resize(n);
	visit.resize(n);
	for (int i = 0;i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		a--; b--;
		arr[a].push_back(b);
		arr2[b].push_back(a);
		points[a]++;
	}
	for (int i = 0; i < n; i++)
		s(i);
	priority_queue<pair<int, int>, vector<pair<int, int>>,greater<pair<int,int>>> q;
	for (int i = 0; i < n; i++)
	{
		q.push({ points[i],i });
	}
	while (q.empty()==false)
	{
		auto temp = q.top(); q.pop();
		cout << temp.second+1 << " ";
	}
}

