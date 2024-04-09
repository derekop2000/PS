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
#include<climits>
using namespace std;

int v, e, p;
vector<vector<pair<int, int>>> arr;
vector<vector<int>> parent;
void f()
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	q.push({ 0,0 });
	vector<int> dist(v,INT_MAX);
	dist[0] = 0;
	parent.resize(v);
	while (!q.empty())
	{
		int now_w = q.top().first;
		int now_v = q.top().second;
		q.pop();
		if (now_w > dist[now_v])continue;
		for (int i = 0; i < arr[now_v].size(); i++)
		{
			int next_w = now_w + arr[now_v][i].second;
			int next_v = arr[now_v][i].first;
			if(next_w == dist[next_v])parent[next_v].push_back(now_v);
			if (next_w < dist[next_v])
			{
				parent[next_v].resize(0);
				parent[next_v].push_back(now_v);
				dist[next_v] = next_w;
				q.push({ dist[next_v],next_v });
			}
		}
	}
}
bool ans = false;
void ff(int now)
{
	if (now == 0)return;
	if (now == p)
	{
		ans = true;
		return;
	}
	for(int i=0;i<parent[now].size();i++)
		ff(parent[now][i]);
}
int main()
{
	cin >> v >> e >> p;
	p--;
	arr.resize(v);
	for (int i = 0; i < e; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		a--; b--;
		arr[a].push_back({ b,c });
		arr[b].push_back({ a,c });
	}
	f();
	if (p == 0)ans = true;
	else ff(v-1);
	if (ans)cout << "SAVE HIM";
	else cout << "GOOD BYE";
}
