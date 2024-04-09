#include<iostream>
using namespace std;
int main()
{
    long long int dp[101];
    dp[1]=1;
    dp[2]=1;
    dp[3]=1;
    dp[4]=2;
    dp[5]=2;
    for(int i=6;i<=100;i++)
        dp[i]=dp[i-1]+dp[i-5];


    int t,n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        cout << dp[n]<<'\n';
    }
}
