#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
#include<string>
#include<set>
#include<map>
#include<cmath>
#include <iomanip>
using namespace std;

vector<int> parent;
vector<bool> visit;
set<int> _list;
int ans;
int find_parent(int a)
{
	if (parent[a] == a)return a;
	return parent[a] = find_parent(parent[a]);
}
void my_union(int a, int b)
{
	int aa = find_parent(a);
	int bb = find_parent(b);
	if (aa == bb)return;
	parent[aa] = bb;
}
bool my_is_union(int a, int b)
{
	return find_parent(a) == find_parent(b);
}
void f(int now, int top)
{
	if (visit[now])
	{
		if (_list.find(now) == _list.end())return;
		if (now == top)return;
		if (top == -1)
			top = now;
		ans--;
		f(parent[now], top);
	}
	else
	{
		_list.insert(now);
		visit[now] = true;
		f(parent[now], top);
	}
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		parent.resize(n);
		visit.resize(n);
		for (int i = 0; i < n; i++)
		{
			visit[i] = false;
			int temp;
			cin >> temp;
			parent[i] = temp - 1;
		}
		ans = n;
		for (int i = 0; i < n; i++)
		{
			_list.clear();
			f(i,-1);
		}
		cout << ans << "\n";
	}
}
