#include <iostream>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <queue>
#include <map>
using namespace std;

int n;
vector<pair<int, int>>v;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        v.push_back(make_pair(a, b));
    }
    sort(v.begin(), v.end());
    vector<int> dp(n, 0);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int temp = 0;
        for (int j = 0; j < i; j++)
        {
            if (v[j].second < v[i].second)
                temp = max(temp, dp[j]);
        }
        dp[i] = temp + 1;
        ans = max(dp[i], ans);
    }
    cout << n - ans;
}
