#include<iostream>
using namespace std;
int** visited;
int count;
void f();
void dfs(int i,int j,int n,int m);
int main()
{
    int t;
    cin >> t;
    for(int i=0;i<t;i++)
    {
        count =0;
        f();
        cout << count <<'\n';
    }
}
void f()
{
    int m,n,k;
    cin >> m >> n >> k;
    visited = new int*[n];
    for(int i=0;i<n;i++)
        visited[i] = new int[m];
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            visited[i][j]=0;
    int a,b;
    for(int i=0;i<k;i++)
    {
        cin >> a>> b;
        visited[b][a]=1;
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(visited[i][j]==1)
            {
                count++;
                dfs(i,j,n,m);
            }
    for(int i=0;i<n;i++)
        delete[] visited[i];
    delete[] visited;

}
void dfs(int i,int j,int n,int m)
{
    visited[i][j]=0;
    if(i>0&&visited[i-1][j])dfs(i-1,j,n,m);
    if(j+1<m&&visited[i][j+1])dfs(i,j+1,n,m);
    if(i+1<n&&visited[i+1][j])dfs(i+1,j,n,m);
    if(j>0&&visited[i][j-1])dfs(i,j-1,n,m);
}
