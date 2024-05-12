#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
#include<memory.h>
#include<string>
#include<sstream>
#include<algorithm>
#include<map>
#include<set>
#include<iomanip>
#include<climits>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    vector<pair<int, int>> dp(b + 1, {1000000,1000000});
    dp[a].first = 0;
    for (int i = a; i <= b; i++)
    {
        int next = i+ 1;
        if(next <= b)
        {
            dp[next].first = min(dp[i].first + 1, dp[next].first);
            dp[next].second = min(dp[next].second, dp[i].second + 1);
        }
        next = i *2;
        if(next <= b)
        {
            dp[next].first = min(dp[i].first + 1, dp[next].first);
            dp[next].second = min(dp[next].second, dp[i].second + 1);
        }
        next = i *10;
        if(next <= b)
        {
            dp[next].second = min(dp[next].second, dp[i].first + 1);
        }

    }
    cout << min(dp[b].first, dp[b].second);
}
