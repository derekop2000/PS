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
    int n;
    cin >> n;
    vector<int> dp[2]{vector<int>(n+1,100000 ),vector<int>(n+1,100000) };
    dp[0][1] = 0;
    vector<pair<int, int>> temp;
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        temp.push_back({ a,b });
    }
    int m;
    cin >> m;
    for (int i = 1; i < n; i++)
    {
        int next = i + 1;
        if (next <= n)
        {
            dp[0][next] = min(dp[0][next], dp[0][i] + temp[i - 1].first);
            dp[1][next] = min(dp[1][next], dp[1][i] + temp[i - 1].first);
        }
        next++;
        if (next <= n)
        {
            dp[0][next] = min(dp[0][next], dp[0][i] + temp[i - 1].second);
            dp[1][next] = min(dp[1][next], dp[1][i] + temp[i - 1].second);
        }
        next++;
        if (next <= n)
        {
            dp[1][next] = min(dp[1][next], dp[0][i] + m);
        }
    }
    cout << min(dp[1][n], dp[0][n]);
}
