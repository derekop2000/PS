#include <iostream>
#include<string.h>
#include<sstream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int arr[1024][1024];
int dp[1024][1024];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n,m;
    cin >> n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cin>>arr[i][j];
    }
    dp[0][0]=arr[0][0];
    for(int i=1;i<n;i++)
        dp[0][i]=dp[0][i-1]+arr[0][i];
    for(int i=1;i<n;i++)
        dp[i][0]=dp[i-1][0]+arr[i][0];
    for(int i=1;i<n;i++)
        for(int j=1;j<n;j++)
        {
            dp[i][j] = dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+arr[i][j];
        }


    while(m--)
    {
        int a,b,c,d;
        cin >>a>>b>>c>>d;
        a--;b--;c--;d--;
        int temp = dp[c][d];
        if(a>0&&b>0)
        {
            temp = temp-dp[c][b-1]-dp[a-1][d]+dp[a-1][b-1];
        }
        else if(a>0&&!b)
        {
            temp -= dp[a-1][d];
        }
        else if(!a&&b>0)
        {
            temp -=dp[c][b-1];
        }
        cout << temp<<'\n';
    }
}
