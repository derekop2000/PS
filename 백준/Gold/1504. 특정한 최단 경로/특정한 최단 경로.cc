#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int INF = 187654321;
int v, e;
int must[2];
vector<vector<pair<int, int>>> arr;
int time_ = 1;
int s1, s2, mid, f1, f2;
void dks(int start)
{
	vector<int> dist(v, INF);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	dist[start] = 0;
	q.push(make_pair(0, start));
	while (!q.empty())
	{
		int v = q.top().second;
		int w = q.top().first;
		q.pop();
		if (w > dist[v])continue;
		for (int i = 0; i < arr[v].size(); i++)
		{
			int V = arr[v][i].first;
			int W = arr[v][i].second + w;
			if (W < dist[V])
			{
				dist[V] = W;
				q.push(make_pair(W, V));
			}
		}
	}
	if (time_ == 1)
	{
		s1 = dist[must[0]];
		s2 = dist[must[1]];
		time_++;
	}
	else if (time_ == 2)
	{
		mid = dist[must[1]];
		time_++;
	}
	else if (time_ == 3)
	{
		f2 = dist[must[1]];
		f1 = dist[must[0]];
	}
}
int main()
{
	cin >> v >> e;
	arr.resize(v);
	for (int i = 0; i < e; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		arr[a - 1].push_back(make_pair(b - 1, c));
		arr[b - 1].push_back(make_pair(a - 1, c));
	}
	cin >> must[0] >> must[1];
	must[0]--; must[1]--;
	dks(0);
	dks(must[0]);
	dks(v - 1);
	
    int ans = min((s1 + mid + f2), (s2 + mid + f1));
	if (ans >= INF)cout << "-1";
	else cout << ans;
}