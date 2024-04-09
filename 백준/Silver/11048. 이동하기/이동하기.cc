#include <iostream>
#include<sstream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<memory>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin >>n>>m;
    vector<vector<int>> v;
    v.resize(n);
    for(int i=0;i<n;i++)
    {
        v[i].resize(m);
        for(int j=0;j<m;j++)
            cin>>v[i][j];
    }
    vector<vector<int>> v2;
    v2.resize(n);
    for(int i=0;i<n;i++)
    {
        v2[i].resize(m,0);

    }
    v2[0][0]=v[0][0];
    for(int i=1;i<m;i++)
        v2[0][i]=v2[0][i-1]+v[0][i];
    for(int i=1;i<n;i++)
        v2[i][0]=v2[i-1][0]+v[i][0];
    for(int i=1;i<n;i++)
        for(int j=1;j<m;j++)
            v2[i][j]=max(max(v2[i-1][j-1],v2[i-1][j]),v2[i][j-1])+v[i][j];
    cout << v2[n-1][m-1];
}
