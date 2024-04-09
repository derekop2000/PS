#include <iostream>
#include<vector>
#include<queue>
#include<tuple>
#include<map>
using namespace std;

int n, m;
vector<vector<pair<int,int>>> arr;
map<pair<int,int>, int> ans;
void dks()
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    vector<int> dist(n, 2147483647);
    vector<int> parent(n);
    dist[0] = 0;
    q.push({ 0,0 });
    while (!q.empty())
    {
        auto now = q.top(); q.pop();
        if (now.first > dist[now.second])continue;
        for (int i = 0; i < arr[now.second].size(); i++)
        {
            int w = now.first + arr[now.second][i].second;
            int v = arr[now.second][i].first;
            if (dist[v] > w)
            {
                parent[v] = now.second;
                dist[v] = w;
                q.push({ w,v });
            }

        }
    }
    for (int i = 1; i < n; i++)
    {
        int temp = i;
        while (true)
        {
            ans.insert({ { temp, parent[temp] },0 });
            if (parent[temp] != 0)
                temp = parent[temp];
            else break;
        }
    }
    cout << ans.size()<<"\n";
    for (auto i = ans.begin();i!=ans.end();i++)
    {
        cout << (*i).first.first+1 << " " << (*i).first.second+1 << "\n";
    }
}
int main()
{
    ios::sync_with_stdio(0);
	cin.tie(0);
    cin >> n >> m;
    arr.resize(n);
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        arr[a].push_back({ b,c });
        arr[b].push_back({ a,c });
    }
    dks();
}