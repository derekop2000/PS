#include<iostream>
#include<memory>
#include<queue>
#include<vector>
using namespace std;
int dp[1001];
int ans=0;
int main()
{
    int n;
    cin >>n;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++)
        cin >> v[i];
    dp[1]=v[1];
    ans = dp[1];
    for(int i=2;i<=n;i++)
    {
        int temp=0;
        for(int j=i-1;j>=1;j--)
        {
            if(v[i]>v[j]&&dp[j]>temp)
                temp=dp[j];
        }
        dp[i]=temp+v[i];
        if(dp[i]>ans)
            ans=dp[i];
    }
    cout << ans;
}
