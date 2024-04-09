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
    int n,k;
    cin >>n>>k;
    vector<int> v(n);
    for(int i=0;i<n;i++)
        cin >>v[i];
    bool ans=false;
    vector<int> dp(k+1);
    dp[0]=0;
    for(int i=1;i<=k;i++)
    {
        int temp=10001;
        for(int j=0;j<v.size();j++)
        {
            if(v[j]<=i)
            {
                if(dp[i-v[j]]==0&& (i-v[j]) )continue;
                temp = min(temp,dp[i-v[j]]);
            }
        }
        if(temp==10001)
            dp[i]=0;
        else dp[i]=temp+1;
    }
    if(dp[k]==0)
        cout<<"-1";
    else cout << dp[k];
}
