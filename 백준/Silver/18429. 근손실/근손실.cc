#include<iostream>
#include<vector>
using namespace std;
int n,k,cnt=0;
vector<int> v;
bool visited[8];
void dfs(int floor,int state)
{
    int goal = floor * k;
    for(int i=0;i<n;i++)
    {
        if(!visited[i]&& (v[i]+state)>=goal )
        {
            if(floor == n){cnt++;continue;}
            visited[i]=true;
            dfs(floor+1,state+v[i]);
            visited[i]=false;
        }
    }
}
int main()
{
    cin >>n >>k;
    v.resize(n);
    for(int i=0;i<n;i++)
        cin >> v[i];
    dfs(1,0);
    cout << cnt;
}
