#include<iostream>
using namespace std;
int dp[10][1001];
int main()
{
    int n;
    cin >> n;
    for(int i=0;i<10;i++)
        dp[i][1]=1;
    for(int i=2;i<=n;i++)
        for(int j=0;j<10;j++)
        {
            for(int q=0;q<=j;q++)
            {
                dp[j][i] +=dp[q][i-1];
            }
            dp[j][i]%=10007;
        }
    int ans=0;
    for(int i=0;i<10;i++)
        ans+=dp[i][n];
    ans%=10007;
    cout << ans;
}
