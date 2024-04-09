#include<iostream>
#include<memory>
#include<queue>
#include<vector>
using namespace std;
int dp[10001][3];
int main()
{
    dp[0][0]=1;
    dp[0][1]=1;
    dp[0][2]=1;
    dp[1][0]=1;
    dp[1][1]=0;
    dp[1][2]=0;
    dp[2][0]=1;
    dp[2][1]=1;
    dp[2][2]=0;
    dp[3][0]=1;
    dp[3][1]=1;
    dp[3][2]=1;
    for(int i=4;i<=10000;i++)
    {
        dp[i][0]=dp[i-1][0];
        dp[i][1]=dp[i-2][1]+dp[i-2][0];
        dp[i][2]=dp[i-3][2]+dp[i-3][1]+dp[i-3][0];
    }
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        int temp;
        cin >> temp;
        if(temp<=3)
            {cout << temp<<'\n';continue;}
        else cout << dp[temp][0]+dp[temp][1]+dp[temp][2]<<'\n';

    }
}
