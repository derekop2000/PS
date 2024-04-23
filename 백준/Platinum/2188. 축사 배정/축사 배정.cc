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
using namespace std;

int n, m;
vector<vector<int>> _arr;
vector<bool> _visit;
vector<int> _partner;
bool f2(int now)
{
	_visit[now] = true;
	for (int i = 0; i < _arr[now].size(); i++)
	{
		int next = _arr[now][i];
		if (_partner[next] == -1 || (_visit[_partner[next]]==false && f2(_partner[next]) ))
		{
			_partner[next] = now;
			return true;
		}
	}
	return false;
}
int f()
{
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		_visit.clear();
		_visit.resize(n, false);
		if (f2(i))
			ans++;
	}
	return ans;
}

int main()
{
	cin >> n >> m;
	_arr.resize(n);
	_partner.resize(m, -1);
	for (int i = 0; i < n; i++)
	{
		int k;
		cin >> k;
		for (int j = 0; j < k; j++)
		{
			int temp;
			cin >> temp;
			_arr[i].push_back(temp-1);
		}
	}
	cout << f();
}