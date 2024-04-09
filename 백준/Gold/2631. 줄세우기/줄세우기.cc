#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<cstdio>
using namespace std;
int dp[1001];
int main()

{
    int ans=1;
    int n;
    cin >> n;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++)
        {cin >> v[i];dp[i]=1;}
    dp[n]=1;
    for(int i=2;i<=n;i++)
        for(int j=1;j<i;j++)
            if(v[i]>v[j])
                {
                    dp[i]=max(dp[i],dp[j]+1);
                    if(dp[i]>ans)ans=dp[i];
                }
    cout << n-ans;
}
