#include<iostream>
using namespace std;
int n,m;
pair<int,int> R;
pair<int,int> B;
char** arr;
bool good;
pair<int,int> f(int direct,int i,int j,int a,int b)
{
    if(direct==0)
    {
        while(1)
        {
            if(i-1==a&&j==b)return make_pair(i,j);
            if(arr[i-1][j]=='#')
                return make_pair(i,j);
            else if(arr[i-1][j]=='O')
                return make_pair(-1,-1);
            else if(arr[i-1][j]=='.')
                i--;
            else return make_pair(i,j);
        }
    }
    else if(direct==1)
    {
        while(1)
        {
            if(i==a&&j+1==b)return make_pair(i,j);
            if(arr[i][j+1]=='#')
                return make_pair(i,j);
            else if(arr[i][j+1]=='O')
                return make_pair(-1,-1);
            else if(arr[i][j+1]=='.')
                j++;
            else return make_pair(i,j);
        }
    }
    else if(direct==2)
    {
        while(1)
        {
            if(i+1==a&&j==b)return make_pair(i,j);
            if(arr[i+1][j]=='#')
                return make_pair(i,j);
            else if(arr[i+1][j]=='O')
                return make_pair(-1,-1);
            else if(arr[i+1][j]=='.')
                i++;
            else return make_pair(i,j);
        }
    }
    else
    {
        while(1)
        {
            if(i==a&&j-1==b)return make_pair(i,j);
            if(arr[i][j-1]=='#')
                return make_pair(i,j);
            else if(arr[i][j-1]=='O')
                return make_pair(-1,-1);
            else if(arr[i][j-1]=='.')
                j--;
            else return make_pair(i,j);
        }
    }
}
void dfs(int cnt,int Ri,int Rj,int Bi,int Bj)
{
    if(cnt>10||good)return;
    pair<int,int>tempR;
    pair<int,int>tempB;

    if(Ri<Bi)
    {
        tempR = f(0,Ri,Rj,-1,-1);
        tempB = f(0,Bi,Bj,tempR.first,tempR.second);
    }
    else
    {
        tempB = f(0,Bi,Bj,-1,-1);
        tempR = f(0,Ri,Rj,tempB.first,tempB.second);
    }
    if(tempR.first==-1&&tempB.first!=-1)
        {
            good=true;return;
        }
    else if(tempR.first!=-1&&tempB.first!=-1&&(tempR.first!=Ri||tempB.first!=Bi))
        dfs(cnt+1,tempR.first,tempR.second,tempB.first,tempB.second);

    if(Rj>Bj)
    {
        tempR = f(1,Ri,Rj,-1,-1);
        tempB = f(1,Bi,Bj,tempR.first,tempR.second);
    }
    else
    {
        tempB = f(1,Bi,Bj,-1,-1);
        tempR = f(1,Ri,Rj,tempB.first,tempB.second);
    }
    if(tempR.first==-1&&tempB.first!=-1)
        {
            good=true;return;
        }
    else if(tempR.first!=-1&&tempB.first!=-1&&(tempR.second!=Rj||tempB.second!=Bj))
        dfs(cnt+1,tempR.first,tempR.second,tempB.first,tempB.second);

    if(Ri>Bi)
    {
        tempR = f(2,Ri,Rj,-1,-1);
        tempB = f(2,Bi,Bj,tempR.first,tempR.second);
    }
    else
    {
        tempB = f(2,Bi,Bj,-1,-1);
        tempR = f(2,Ri,Rj,tempB.first,tempB.second);
    }
    if(tempR.first==-1&&tempB.first!=-1)
        {
            good=true;return;
        }
    else if(tempR.first!=-1&&tempB.first!=-1&&(tempR.first!=Ri||tempB.first!=Bi))
        dfs(cnt+1,tempR.first,tempR.second,tempB.first,tempB.second);

    if(Rj<Bj)
    {
        tempR = f(3,Ri,Rj,-1,-1);
        tempB = f(3,Bi,Bj,tempR.first,tempR.second);
    }
    else
    {
        tempB = f(3,Bi,Bj,-1,-1);
        tempR = f(3,Ri,Rj,tempB.first,tempB.second);
    }
    if(tempR.first==-1&&tempB.first!=-1)
        {
            good=true;return;
        }
    else if(tempR.first!=-1&&tempB.first!=-1&&(tempR.second!=Rj||tempB.second!=Bj))
        dfs(cnt+1,tempR.first,tempR.second,tempB.first,tempB.second);

}
int main()
{
    cin >> n>>m;
    arr = new char*[n];
    for(int i=0;i<n;i++)
        arr[i]=new char[m];
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            cin >> arr[i][j];
            if(arr[i][j]=='R'){R.first=i;R.second=j;arr[i][j]='.';}
            if(arr[i][j]=='B'){B.first=i;B.second=j;arr[i][j]='.';}
        }
    dfs(1,R.first,R.second,B.first,B.second);
    if(good)cout <<'1';
    else cout <<'0';
    for(int i=0;i<n;i++)
        delete[] arr[i];
    delete[] arr;
}
