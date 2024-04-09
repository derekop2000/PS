#include<iostream>
#include<vector>
using namespace std;
int dp[17];

int main()
{
    int n;
    cin >>n;
    vector<pair<int,int>> v;
    v.resize(n+1);
    for(int i=1;i<=n;i++)
    {
        cin >>v[i].first;
        cin >>v[i].second;
    }

    dp[n+1]=0;
    int maxNum=0;
    for(int i=n;i>0;i--)
    {
        if(v[i].first+i>n+1)
            dp[i]=maxNum;
        else
        {
            dp[i]=max(v[i].second+dp[i+v[i].first],maxNum);
            if(maxNum<dp[i])maxNum=dp[i];
        }
    }

    cout<< dp[1];
}
