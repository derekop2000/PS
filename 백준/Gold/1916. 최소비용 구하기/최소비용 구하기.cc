#include<iostream>
#include<vector>
using namespace std;
int n,m,s,e;
int max_value=0;
int currentPos;
vector<bool> visit;
vector<int> dist;
vector<vector<int>> info;
void dks()
{
    for(int i=0;i<n;i++)
    {
        visit[currentPos]=true;
        int minn=100000001;
        for(int j=0;j<n;j++)
        {
            if(visit[j])continue;
            if(dist[j]>-1 && dist[j]<minn)
            {
                currentPos=j;
                minn=dist[j];
            }
        }
        for(int j=0;j<n;j++)
        {
            if(visit[j])continue;
            if(info[currentPos][j]==-1)continue;
            else if(dist[j]==-1)dist[j]=info[currentPos][j]+dist[currentPos];
            else dist[j] = min(dist[j],info[currentPos][j]+dist[currentPos] );
        }

    }
}
void f()
{
    currentPos=s;
    for(int i=0;i<n;i++)
        {dist[i]=info[s][i];visit[i]=false;}
    dist[currentPos]=0;
    dks();
}
int main()
{
    cin >>n>>m;
    visit.resize(n);
    dist.resize(n);
    info.resize(n);
    for(int i=0;i<n;i++)
        info[i].resize(n);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            info[i][j]=-1;
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin >>a >>b>>c;
        if(info[a-1][b-1]!=-1&& info[a-1][b-1] < c)continue;
        info[a-1][b-1]= c;
    }
    cin >> s>>e;
    s--;
    e--;
    f();
    cout << dist[e];
}
