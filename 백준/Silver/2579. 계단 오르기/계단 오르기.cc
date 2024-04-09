#include<iostream>
using namespace std;
int big(int a,int b){if(a>b)return a; else return b;}
int main()
{
    int n;
    cin >> n;
    int* stair = new int[n+1];
    int* dp=new int[n+1];
    int temp;
    for(int i=1;i<=n;i++)
    {
        cin >> temp;
        stair[i] = temp;
    }
    dp[0]=0;
    dp[1]=stair[1];
    if(n>1)
    {
        dp[2]=stair[1]+stair[2];
        dp[3]=big(stair[3]+stair[2],stair[1]+stair[3]);
        for(int i=4;i<=n;i++)
        {
            dp[i] = big(dp[i-3]+stair[i-1]+stair[i],dp[i-2]+stair[i]);
        }
    }
    cout << dp[n];
    delete[] stair;
    delete[] dp;
}
