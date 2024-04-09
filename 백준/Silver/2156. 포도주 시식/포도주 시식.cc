#include <iostream>
#include<string.h>
#include<sstream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int n;
vector<int> v;
int dp[10001];
int main()
{

    cin>>n;
    v.resize(n+1);
    for(int i=1;i<=n;i++)
    {
        cin >> v[i];
    }
    dp[0]=0;
    dp[1]=v[1];
    if(n==1){cout << dp[1];return 0;}
    dp[2]=v[1]+v[2];
    for(int i=3;i<=n;i++)
    {
        dp[i]= max(max( (v[i]+v[i-1]+dp[i-3]),(v[i]+dp[i-2]) ),dp[i-1]);
    }
    cout << dp[n];
}
