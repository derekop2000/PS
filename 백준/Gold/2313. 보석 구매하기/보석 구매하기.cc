#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin >> t;
    long long ans = 0;
    vector<pair<int, int>> ranges;

    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        vector<pair<int, int>> dp(n);
        dp[0] = { arr[0], 0 };
        long long serveAns = arr[0];
        pair<int, int> range = { 0, 0 };
        
        for (int i = 1; i < n; i++)
        {
            if (arr[i] + dp[i - 1].first > arr[i])
            {
                dp[i] = { arr[i] + dp[i - 1].first, dp[i - 1].second };
            }
            else
            {
                dp[i] = { arr[i], i };
            }

            if (dp[i].first > serveAns)
            {
                serveAns = dp[i].first;
                range = { dp[i].second, i };
            }
            else if (dp[i].first == serveAns)
            {
                int currentLength = i - dp[i].second;
                int bestLength = range.second - range.first;
                
                if (currentLength < bestLength || (currentLength == bestLength && (dp[i].second < range.first || (dp[i].second == range.first && i < range.second))))
                {
                    range = { dp[i].second, i };
                }
            }
        }
        ranges.push_back(range);
        ans += serveAns;
    }
    
    cout << ans << "\n";
    for (auto a : ranges)
    {
        cout << a.first + 1 << " " << a.second + 1 << "\n";
    }

    return 0;
}
