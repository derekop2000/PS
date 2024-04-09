#include<iostream>
#include<vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    vector<pair<int,int>> v(n+1);
    for(int i=1;i<=n;i++)
        cin >> v[i].first >> v[i].second;
    vector<int> dp(n+2,0);
    for(int i=n;i>0;i--)
    {
        if(i+v[i].first > n+1){dp[i]=dp[i+1];}
        else
        {
            dp[i] = max (dp[i+v[i].first]+v[i].second,dp[i+1] );
        }
    }
    cout << dp[1];
}
