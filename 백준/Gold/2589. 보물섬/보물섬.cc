#include<iostream>
#include<memory>
#include<queue>
#include<vector>
using namespace std;
int n,m,ans=0;
queue<pair<int,int>> q;
vector<pair<int,int>> v;
unique_ptr< unique_ptr<int[]>[] > arr;
void f()
{
    while(!q.empty())
    {
        int nn=q.front().first;
        int mm=q.front().second;q.pop();
        if(arr[nn][mm]>ans)ans=arr[nn][mm];
        if(nn>0&&!arr[nn-1][mm]){q.push(make_pair(nn-1,mm));arr[nn-1][mm]=arr[nn][mm]+1; }
        if(mm<m-1&&!arr[nn][mm+1]){q.push(make_pair(nn,mm+1));arr[nn][mm+1]=arr[nn][mm]+1;}
        if(nn<n-1&&!arr[nn+1][mm]){q.push(make_pair(nn+1,mm));arr[nn+1][mm]=arr[nn][mm]+1;}
        if(mm>0&&!arr[nn][mm-1]){q.push(make_pair(nn,mm-1));arr[nn][mm-1]=arr[nn][mm]+1;}
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0);
    cin >> n>>m;
    char temp;
    arr = make_unique<unique_ptr<int[]>[]>(n);
    for(int i=0;i<n;i++)
        arr[i] = make_unique<int[]>(m);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            cin >> temp;
            if(temp=='L')
            {
                v.push_back(make_pair(i,j));
                arr[i][j]=0;
            }
            else arr[i][j]=1;
        }
    int landCnt=v.size();
    for(int i=0;i<landCnt;i++)
    {
        q.push(v[i]);
        arr[ v[i].first ][ v[i].second ]=1;
        f();
        for(int j=0;j<landCnt;j++)
        {
            arr[v[j].first][ v[j].second ]=0;
        }
    }
    cout << ans-1;
}
