#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int main()
{
    int t=3;
    while(t--)
    {
        int sum=0;
        int n;
        cin >> n;
        vector<pair<int,int>> v(n);
        for(int i=0;i<n;i++)
        {
            cin >> v[i].first >>v[i].second;
            sum+= v[i].first*v[i].second;
        }
        if(sum%2==1){cout << "0\n";continue;}
        bool* dp = new bool[50001];
        for(int i=1;i<=50000;i++)
            dp[i]=false;
        dp[0]=true;
        //sort(v.begin(),v.end());
        for(int i=0;i<n;i++)
        {
            for(int j=sum/2;j>=v[i].first;j--)
            {
                if(dp[j-v[i].first])
                {
                    for(int k=0;k<v[i].second;k++)
                    {
                        if( j+k*v[i].first >sum/2)break;
                        dp[j+k*v[i].first]=true;
                    }
                }
            }
        }
        if(dp[sum/2])
            cout << "1\n";
        else cout << "0\n";
    }
}
