#include<iostream>
#include<vector>
using namespace std;
vector<vector<bool>> v;
int n,m;
int dir1[] = {-1,0,1,0};
int dir2[] = {0,1,0,-1};
int ans=0;
int temp_ans=0;
int cnt=0;
void f(int col,int row)
{
    v[col][row]=false;
    temp_ans++;
    int x,y;
    for(int i=0;i<4;i++)
    {
        y = col+dir1[i];
        x = row+dir2[i];
        if(0<=y&&y<n&&0<=x&&x<m&&v[y][x])
        {
            f(y,x);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >>n>>m;
    v.resize(n);
    for(int i=0;i<n;i++)
        v[i].resize(m);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            int temp;
            cin >> temp;
            if(temp)v[i][j]=true;
            else v[i][j]=false;
        }
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            if(v[i][j])
            {
                cnt++;
                temp_ans=0;
                f(i,j);
                if(temp_ans>ans)
                    ans=temp_ans;
            }
        }
    cout << cnt <<'\n'<<ans;
}
