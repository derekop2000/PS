#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
#include<string>
#include<set>
#include<map>
#include<cmath>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> arr(n+1);

	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	vector<pair<int, int>> dp(n+1);
	dp[0] = { -1000,-1000 };
	int ans = -1000;
	for (int i = 1; i <= n; i++)
	{
		dp[i].first = max(dp[i - 1].first + arr[i], arr[i]);
		dp[i].second = max(arr[i] + dp[i - 1].second, dp[i - 1].first);
		ans = max(ans, dp[i].second);
		ans = max(ans, dp[i].first);
	}
	cout << ans;
}
