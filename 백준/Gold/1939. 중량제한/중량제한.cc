#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
using namespace std;

int n, m;
vector<vector<pair<int, int>>> arr;
int s, e;
int ans = 0;
int _mid;
vector<bool> visited;
bool dfs(int now_node)
{
	if (now_node == e)return true;
	for (int i = 0; i < arr[now_node].size(); i++)
	{
		if (visited[arr[now_node][i].first] || arr[now_node][i].second < _mid)continue;
		visited[arr[now_node][i].first] = true;
		if (dfs(arr[now_node][i].first))return true;
	}
	return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
	cin >> n >> m;
	arr.resize(n);
	visited.resize(n, false);
	int _max = 0;
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		a--; b--;
		arr[a].push_back({ b,c });
		arr[b].push_back({ a,c });
		if (c > _max)_max = c;
	}
	cin >> s >> e;
	s--; e--;
	int _min = 0;
	while(_min<=_max)
	{
		_mid = (_max + _min) / 2;
		for (int i = 0; i < n; i++)visited[i] = false;
		visited[s] = true;
		if (dfs(s))
		{
			ans = max(ans, _mid);
			_min = _mid + 1;
		}
		else
		{
			_max = _mid - 1;
		}
	}
	cout << ans;
}