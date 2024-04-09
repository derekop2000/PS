#include<iostream>
#include<memory>
#include<queue>
#include<vector>
using namespace std;
int dp[1001][3];
int main()
{
    int n,temp;
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin>>temp;
        dp[i][0] =min(dp[i-1][1],dp[i-1][2])+temp;
        cin>>temp;
        dp[i][1] =min(dp[i-1][0],dp[i-1][2])+temp;
        cin>>temp;
        dp[i][2] =min(dp[i-1][0],dp[i-1][1])+temp;
    }
    cout<< min (min (dp[n][0],dp[n][1]),dp[n][2]);
}
