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
    int a;
    cin >>a;
    int* dp = new int[a+1];
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=a;i++)
    {
        dp[i]=i;
        for(int j=2;j*j<=i;j++)
        {
            dp[i]= min(dp[i],dp[i-j*j]+1);
        }
    }
    cout << dp[a];
    delete[] dp;
}
