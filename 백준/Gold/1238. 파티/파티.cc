#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
#include<string>
using namespace std;

int n, m, x;
vector<vector<pair<int, int>>> arr;
vector<int> dist;
void dks(int s)
{
	for (int i = 0; i < dist.size(); i++)
		dist[i] = 2147483647;
	dist[s] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	q.push(make_pair(0, s));
	while (!q.empty())
	{
		int w = q.top().first;
		int v = q.top().second;
		q.pop();
		if (w > dist[v])continue;
		for (int i = 0; i < arr[v].size(); i++)
		{
			int W = w + arr[v][i].second;
			int V = arr[v][i].first;
			if (dist[V] > W)
			{
				dist[V] = W;
				q.push(make_pair(W, V));
			}
		}
	}

}
int main()
{
	cin >> n >> m >> x;
	x--;
	dist.resize(n);
	arr.resize(n);
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		a--; b--;
		arr[a].push_back(make_pair(b, c));
	}
	vector<int> anss(n,0);
	for (int i = 0; i < n; i++)
	{
		dks(i);
		anss[i] += dist[x];
	}
	dks(x);
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		anss[i] += dist[i];
		ans = max(anss[i], ans);
	}
	cout << ans;
}