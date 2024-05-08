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
    int n,m;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    cin >> m;

    int cnt = 0;
    for (int i = 0; i < m; i++)
    {
        cnt += v[n - 1 - i];
    }
    int temp = v[n - 1];
    v[n - 1] = cnt;
    for (int i = n - 2; i >= m-1; i--)
    {
        int temp2 = temp;
        temp = v[i];
        cnt = cnt - temp2 + v[i - m + 1];
        v[i] = cnt;
    }
    vector<vector<int>> dp(n + 1, vector<int>(3));
    for (int i = m; i <= n; i++)
    {
        dp[i][0] = max(v[i-1],dp[i-1][0]);
        dp[i][1] = max(dp[i - m][0] + v[i - 1],dp[i-1][1]);
        dp[i][2] = max(dp[i - m][1] + v[i - 1],dp[i-1][2]);
    }
    cout << dp[n][2];
}
