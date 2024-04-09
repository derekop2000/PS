#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<map>
using namespace std;

int INF = 8000000;
int v, e;
vector<vector<pair<int, int>>> arr;
vector<vector<int>> ans;
void dks(int start)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	q.push(make_pair(0, start));
	vector<int> dist(v, INF);
	dist[start] = 0;
	while (!q.empty())
	{
		int w = q.top().first;
		int v = q.top().second;
		q.pop();
		if (w > dist[v]) continue;
		for (int i = 0; i < arr[v].size(); i++)
		{
			int W = w + arr[v][i].second;
			int V = arr[v][i].first;
			if (W < dist[V])
			{
				dist[V] = W;
				q.push(make_pair(W, V));
			}
		}
	}
	for (int i = 0; i < v; i++)
	{
		ans[start][i] = dist[i];
	}
}
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> v >> e;
	arr.resize(v);
	ans.resize(v, vector<int>(v));
	for (int i = 0; i < e; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		a--; b--;
		arr[a].push_back(make_pair(b, c));
	}
	for (int i = 0; i < v; i++)
	{
		dks(i);
	}
	int anss = INF;
	for (int i = 0; i < v; i++)
	{
		for (int j = 0; j < v; j++)
		{
			if (i == j) continue;
			anss = min(anss, ans[i][j] + ans[j][i]);
		}
	}
	if (anss == INF) cout << "-1";
	else cout << anss;
}

