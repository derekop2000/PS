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

using namespace std;

vector<vector<int>> arr(500, vector<int>(500));
vector<vector<int>> dp(500, vector<int>(500));
int n;

int main()
{
	cin >> n;
	for(int i=0;i<n;i++)
		for (int j = 0; j <= i; j++)
		{
			cin >> arr[i][j];
		}
	dp[0][0] = arr[0][0];
	for (int i = 1; i < n; i++)
		for (int j = 0; j <= i; j++)
		{
			if (j == 0)
				dp[i][j] = dp[i - 1][j] + arr[i][j];
			else
			{
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + arr[i][j];
			}
		}
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		ans = max(ans, dp[n - 1][i]);
	}
	cout << ans;
}