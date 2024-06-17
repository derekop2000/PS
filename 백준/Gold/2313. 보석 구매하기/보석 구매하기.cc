#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin >> t;
    long long int ans = 0;
    vector<pair<int, int>> ranges;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        
        long long int serveAns = arr[0];
        pair<int, int> range = {0, 0};
        long long int currentSum = arr[0];
        int startIdx = 0;

        for (int i = 1; i < n; i++)
        {
            if (currentSum + arr[i] > arr[i])
            {
                currentSum += arr[i];
            }
            else
            {
                currentSum = arr[i];
                startIdx = i;
            }

            if (currentSum > serveAns)
            {
                serveAns = currentSum;
                range = {startIdx, i};
            }
            else if (currentSum == serveAns)
            {
                int currentLength = i - startIdx;
                int bestLength = range.second - range.first;
                if (currentLength < bestLength)
                {
                    range = {startIdx, i};
                }
                else if (currentLength == bestLength)
                {
                    if (startIdx < range.first || (startIdx == range.first && i < range.second))
                    {
                        range = {startIdx, i};
                    }
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
}
