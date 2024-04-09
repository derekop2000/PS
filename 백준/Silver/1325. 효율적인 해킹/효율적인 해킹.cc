#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
#include<memory.h>
#include<string>
using namespace std;

vector<vector<int>> _down;
vector<int> _value;
vector<bool> _visit;
int v, e;
int cnt = 0;
void f2(int now)
{
	cnt++;
	for (int i = 0; i < _down[now].size(); i++)
	{
		int next = _down[now][i];
		if (_visit[next]) continue;
		_visit[next] = true;
		f2(next);
	}
}
void f()
{
	int ans = 0;
	for (int i = 0; i < v; i++)
	{
		_visit.clear();
		_visit.resize(v, false);
		_visit[i] = true;
		cnt = 0;
		f2(i);
		_value[i] = cnt;
		ans = max(ans, cnt);
	}
	for (int i = 0; i < v; i++)
		if (_value[i] == ans)
			cout << i + 1 << " ";
}
int main()
{
	cin >> v >> e;
	_down.resize(v); _value.resize(v);
	for (int i = 0; i < e; i++)
	{
		int a, b;
		cin >> a >> b;
		a--; b--;
		_down[b].push_back(a);
	}
	f();
}
  
