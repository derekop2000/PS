#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<map>
using namespace std;

#define INF 100000000
int v, e , s ,e_ ;
vector<vector<pair<int, int>>> arr;
void dks(int start)
{
	vector<int> dist(v, INF);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	q.push(make_pair(0, start));
	dist[start] = 0;
	vector<vector<int>> route;
	route.resize(v, vector<int>(1, start));
	while (!q.empty())
	{
		int v = q.top().second;
		int w = q.top().first;
		q.pop();
		if (w > dist[v]) continue;
		for (int i = 0; i < arr[v].size(); i++)
		{
			int V = arr[v][i].first;
			int W = arr[v][i].second + w;
			if (W < dist[V])
			{
				route[V].clear();
				for (int j = 0; j < route[v].size(); j++)
				{
					route[V].push_back(route[v][j]);
				}
				route[V].push_back(V);
				
				dist[V] = W;
				q.push(make_pair(W, V));
			}
		}
	}
	cout << dist[e_] << "\n";
	
	cout << route[e_].size() << "\n";
	for (int i = 0; i < route[e_].size(); i++)
	{
		cout << route[e_][i]+1 << " ";
	}
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	cin >> v >> e;
	arr.resize(v);
	for (int i = 0; i < e; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		a--; b--;
		arr[a].push_back(make_pair(b, c));
	}
	cin >> s >> e_;
	s--; e_--;
	dks(s);
}

