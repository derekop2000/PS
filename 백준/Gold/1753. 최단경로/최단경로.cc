#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#define INF 200001
using namespace std;
vector<vector<pair<int,int>>> arr;
vector<int> dist;
int v,e;
int start;
void dks()
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push( make_pair(0,start) );
    while(!q.empty())
    {
        int v = q.top().second;
        int w = dist[v];
        q.pop();
        for(int i=0;i<arr[v].size();i++)
        {
            int V = arr[v][i].first;
            int W = arr[v][i].second+w;
            if(dist[V] > W)
            {
                dist[V] = W;
                q.push(make_pair(W,V) );
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> v >> e;
    cin >> start;
    arr.resize(v+1);
    dist.resize(v+1,INF);
    dist[start]=0;
    for(int i=0;i<e;i++)
    {
        int a,b,c;
        cin >>a>>b>>c;
        arr[a].push_back(make_pair(b,c));

    }
    dks();
    for(int i=1;i<=v;i++)
        if(dist[i]!=INF)cout<< dist[i]<<'\n';else cout<<"INF\n";

}
