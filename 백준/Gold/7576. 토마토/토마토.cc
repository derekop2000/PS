#include<iostream>
#include<memory>
#include<queue>
using namespace std;
unique_ptr< unique_ptr<int[]>[] >arr;
unique_ptr< unique_ptr<bool[]>[] >visited;
queue<pair<int,int>> v;
int n,m,cnt=0;
void f()
{
    while(1)
    {
        int v_size = v.size();
        for(int i=0;i<v_size;i++)
        {
            pair<int,int> temp = v.front();
            arr[temp.first][temp.second] = 1;
            if(temp.first>0&& !visited[temp.first-1][temp.second] &&!arr[temp.first-1][temp.second]){v.push(make_pair(temp.first-1,temp.second));visited[temp.first-1][temp.second]=true; }
            if(temp.second+1<m&& !visited[temp.first][temp.second+1] &&!arr[temp.first][temp.second+1]){v.push(make_pair(temp.first,temp.second+1));visited[temp.first][temp.second+1]=true; }
            if(temp.first+1<n&& !visited[temp.first+1][temp.second] &&!arr[temp.first+1][temp.second]){v.push(make_pair(temp.first+1,temp.second));visited[temp.first+1][temp.second]=true; }
            if(temp.second>0&& !visited[temp.first][temp.second-1] &&!arr[temp.first][temp.second-1]){v.push(make_pair(temp.first,temp.second-1));visited[temp.first][temp.second-1]=true; }
            v.pop();
        }
        if(!v.size())
            break;
        cnt++;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    cin >>m>> n;
    arr = make_unique< unique_ptr<int[]>[] >(n);
    for(int i=0;i<n;i++)
        arr[i] = make_unique<int[]>(m);

    visited = make_unique< unique_ptr<bool[]>[] >(n);
    for(int i=0;i<n;i++)
        visited[i] = make_unique<bool[]>(m);

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            {
                visited[i][j]=false;
                cin >> arr[i][j];
                if(arr[i][j]==1)
                    {v.push( make_pair(i,j) );visited[i][j]=true; }
            }
    f();
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(arr[i][j]==0){cout <<"-1";return 0;}
    cout << cnt;

}
