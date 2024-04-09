#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
#include<string>
#include<set>
#include<map>
#include<cmath>
#include <iomanip>
#include<climits>
#include<sstream>
#include<deque>
using namespace std;


int main()
{
	int n, m;
	cin >> n >> m;
	vector<bool> arr(n + 1);
	vector<vector<int>> dp(n + 1, vector<int>(150, -1));
	for (int i = 0; i < m; i++)
	{
		int temp;
		cin >> temp;
		arr[temp] = true;
	}
	dp[1][0] = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < 150; j++)
		{
			if (dp[i][j] >= 0)
			{
				for (int k = -1; k <= 1; k++)
				{
					if (j + k > 0 && (i + j + k) <= n && arr[i + j + k] == false)
					{
						if (dp[i + j + k][j + k] >= 0)
							dp[i + j + k][j + k] = min(dp[i + j + k][j + k], dp[i][j] + 1);
						else dp[i + j + k][j + k] = dp[i][j] + 1;
					}
				}
			}
		}
	}
	int ans = n;
	for (int i = 0; i < 150; i++)
	{
		if (dp[n][i] != -1)
			ans = min(ans, dp[n][i]);
	}
	if (ans == n) cout << "-1";
	else cout << ans;
}