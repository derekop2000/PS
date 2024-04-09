#include<iostream>
#include<queue>
using namespace std;
int arr[1000][1000]; // 0이면 방문하고 -1 이면 방문 x
queue<pair<int,int>> q;
int n,m;
void bfs()
{
    while(!q.empty())
    {
        pair<int,int> pair_=q.front();
        q.pop();
        if(pair_.first>0&&!arr[pair_.first-1][pair_.second])
        {
            arr[pair_.first-1][pair_.second]=arr[pair_.first][pair_.second]+1;
            q.push(make_pair(pair_.first-1,pair_.second));
        }
        if(pair_.second+1<m&&!arr[pair_.first][pair_.second+1])
        {
            arr[pair_.first][pair_.second+1]=arr[pair_.first][pair_.second]+1;
            q.push(make_pair(pair_.first,pair_.second+1));
        }
        if(pair_.first+1<n&&!arr[pair_.first+1][pair_.second])
        {
            arr[pair_.first+1][pair_.second]=arr[pair_.first][pair_.second]+1;
            q.push(make_pair(pair_.first+1,pair_.second));
        }
        if(pair_.second>0&&!arr[pair_.first][pair_.second-1])
        {
            arr[pair_.first][pair_.second-1]=arr[pair_.first][pair_.second]+1;
            q.push(make_pair(pair_.first,pair_.second-1));
        }

    }

}
int main()
{


    pair<int,int> desXY;
    cin >> n >>m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            cin >> arr[i][j];
            if(arr[i][j]==2)
                desXY=make_pair(i,j);
            arr[i][j]--;
        }
    arr[desXY.first][desXY.second]=0;
    q.push(make_pair(desXY.first,desXY.second));
    bfs();
    arr[desXY.first][desXY.second]=-1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(arr[i][j]==-1)cout<<"0 ";
            else if (arr[i][j]==0)cout<<"-1 ";
            else cout << arr[i][j]<<' ';
        }
        cout<<'\n';
    }

}
