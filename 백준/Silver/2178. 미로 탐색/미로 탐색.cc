#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<vector<int>> v;
int n,m;
int dir1[] = {-1,0,1,0};
int dir2[] = {0,1,0,-1};

queue<pair<int,int>> q;
void f()
{
    while(!q.empty())
    {
        pair<int,int> temp = q.front();q.pop();
        if(temp.first==n-1&&temp.second==m-1)return;
        for(int i=0;i<4;i++)
        {
            int y = temp.first+dir1[i];
            int x = temp.second+dir2[i];
            if(0<=y&&y<n&&0<=x&&x<m&&v[y][x]==1)
            {
                v[y][x] = v[temp.first][temp.second]+1;
                q.push(make_pair(y,x) );
            }
        }
    }
}
int main()
{
    cin >>n>>m;
    v.resize(n);
    for(int i=0;i<n;i++)
        v[i].resize(m);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            char temp;
            cin >> temp;
            if(temp-'0')v[i][j]=1;
            else v[i][j]=0;
        }
    v[0][0]=2;
    q.push(make_pair(0,0));
    f();

    cout << v[n-1][m-1]-1;
}
