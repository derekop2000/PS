#include<iostream>
#include<vector>
using namespace std;
int dp[1001];
int main()
{

    int n;
    cin >> n;
    int temp;
    for(int i=1;i<=n;i++)
    {
        cin >> temp;
        for(int j=i;j<=n;j++)
        {
            dp[j] = max(dp[j],dp[j-i]+temp);
        }
    }
    cout << dp[n];
}
