#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for(int i=0;i<n;i++)
            cin >> v[i];
        int m;
        cin >> m;
        vector<vector<int>> dp(m+1, vector<int>(n, 0));
        for(int i=0;i<n;i++)
            if( v[i]<=m )dp[ v[i] ][ i ]=1;

        for(int i=1;i<=m;i++)
            for(int j=0;j<n;j++)
            {
                if(i-v[j]>0)
                {
                    for(int q=0;q<n;q++)
                    {
                        if(v[j] < v[q])break;
                        dp[i][j]+=dp[i- v[j]][q];
                    }
                }
            }
        int ans=0;
        for(int i=0;i<n;i++)
            ans+=dp[m][i];
        cout << ans <<'\n';

    }
}
