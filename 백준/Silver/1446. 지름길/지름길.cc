#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int dp[10001];
bool f(vector<int>&a,vector<int>&b)
{
    return a[0] < b[0];
}
int main()
{
    int n,d;
    cin >> n>> d;
    vector<vector<int>> v;
    int a,b,c;
    for(int i=0;i<n;i++)
    {
        cin >>a>>b>>c;
        if(c < (b-a) )
        {
            vector<int> tempV;
            tempV.push_back(a);
            tempV.push_back(b);
            tempV.push_back(c);
            v.push_back(tempV);
        }
    }
    for(int i=0;i<=d;i++)
    {
        dp[i]=i;
    }
    int temp_index=0;
    sort(v.begin(),v.end(),f );
    while(temp_index<v.size()&&v[temp_index][0]==0)
        {
            dp[v[temp_index][1]] = min (dp[v[temp_index][1]],dp[v[temp_index][0]]+v[temp_index][2] );
            temp_index++;
        }
    for(int i=1;i<=d;i++)
    {
        dp[i]=min(dp[i],dp[i-1]+1);
        while(temp_index<v.size()&&v[temp_index][0]==i)
        {
            dp[v[temp_index][1]] = min (dp[v[temp_index][1]],dp[v[temp_index][0]]+v[temp_index][2] );
            temp_index++;
        }
    }
    cout << dp[d];
}
