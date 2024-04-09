#include<iostream>
#include<memory>
#include<queue>
#include<vector>
using namespace std;
int dp[100001];

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int n,k;
    cin >>n>>k;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++)
    {
        cin >> v[i];
        dp[i]=dp[i-1]+v[i];
    }
    for(int i=0;i<k;i++)
    {
        int a,b;
        cin >>a>>b;
        cout << dp[b]-dp[a-1]<<'\n';
    }
}