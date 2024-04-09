#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
vector<int> ans;
int n;
bool check=false;
vector<int> dp;
void f(int floor)
{
    if(check)return;
    if( ans.back()==n )
    {
        check=true;
        for(int i=0;i<ans.size();i++)
        cout << ans[ans.size()-i-1]<<' ';
    }

    if(ans.back()*3 <=n && dp[ans.back()*3]==floor-1 )
    {
        ans.push_back( ans.back()*3 );
        f(floor-1);
        ans.pop_back();
    }
    if(ans.back()*2 <=n && dp[ans.back()*2]==floor-1 )
    {
        ans.push_back( ans.back()*2 );
        f(floor-1);
        ans.pop_back();
    }
    if(ans.back()+1 <=n && dp[ans.back()+1]==floor-1 )
    {
        ans.push_back( ans.back()+1 );
        f(floor-1);
        ans.pop_back();
    }
}
int main()
{
    cin >>n;
    dp.resize(n+1,200000000);
    dp[n]=0;
    for(int i=n-1;i>0;i--)
    {
        int temp=200000000;
        if(i*3 <= n)
            temp= min(temp,dp[i*3]);
        if(i*2 <=n)
            temp = min(temp,dp[i*2]);
        temp = min(temp,dp[i+1]);
        dp[i]=temp+1;
    }
    ans.push_back(1);
    cout << dp[1]<<'\n';
    f(dp[1]);
}
