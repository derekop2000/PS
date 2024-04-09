#include<iostream>
using namespace std;
int n,k;
int cnt=0;
int* value;
int* dp;
int main()
{
    cin >> n >> k;
    dp = new int[k+1];
    value = new int[n];
    for(int i=0;i<n;i++)
    {
        cin >> value[i];
    }
    for(int i=0;i<=k;i++)
        dp[i]=0;
    dp[0]=1;
    for(int i=0;i<n;i++)
        for(int j=value[i];j<=k;j++)
            dp[j]=dp[j]+dp[j-value[i]];
    cout << dp[k];


    delete[] dp;
    delete[] value;
}

