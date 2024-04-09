#include <iostream>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <queue>
#include <map>
#include<tuple>
using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	vector<int> dp(n + 1, 0);
	for (int i = 0; i < k; i++)
	{
		int a, b;
		cin >> a >> b;
		for (int j = n; j >= 0; j--)
		{
			if ( (j-b)>=0&&dp[j] < dp[j - b] + a)
				dp[j] = dp[j - b] + a;
		}
	}
	int ans = 0;
	for (int i = 0; i <= n; i++)
		ans = max(dp[i], ans);
	cout << ans;
}
