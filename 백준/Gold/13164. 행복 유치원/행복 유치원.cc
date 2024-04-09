#include <iostream>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <queue>
#include <map>
using namespace std;
int n, k;
vector<pair<int, int>> _distance;
int main()
{
    cin >> n >> k;
    int pre=0;
    int current=0;
    for (int i = 0; i < n; i++)
    {
        cin >> current;
        if (i > 0)
        {
            _distance.push_back(make_pair(current - pre, i - 1));
        }
        pre = current;
    }
    if (n == 1)
    {
        cout << "0";
        return 0;
    }
    sort(_distance.begin(), _distance.end(), greater<pair<int,int>>());
    long ans = 0;
    for (int i = k-1; i < n-1; i++)
    {
        ans += _distance[i].first;
    }
    cout << ans;
}
