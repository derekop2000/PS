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

int cnt = 0;
vector<int> visit;
void f(int now, vector<vector<int>>& arr)
{
	for (auto next : arr[now])
	{
		if (visit[next])continue;
		cnt++;
		visit[next] = true;
		f(next, arr);
	}
}
int main()
{
	int n, m;
	cin >> n >> m;
	visit.resize(n);
	vector<vector<int>> arr(n);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		a--; b--;
		arr[b].push_back(a);
	}
	int s;
	cin >> s;
	s--;
	f(s,arr);
	cout << cnt;
}

