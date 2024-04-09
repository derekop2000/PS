#include<iostream>
#include<vector>
using namespace std;

int v[3];
int dp[2][3];
int dp2[2][3];
int main()
{
	int n;
	cin >> n;
	cin >> v[0];
	cin >> v[1];
	cin >> v[2];
	dp[0][0] = v[0];
	dp[0][1] = v[1];
	dp[0][2] = v[2];
	dp2[0][0] = v[0];
	dp2[0][1] = v[1];
	dp2[0][2] = v[2];
	if (n == 1)
	{
		int big = max(max(dp[0][0], dp[0][1]), dp[0][2]);
		int small = min(min(dp2[0][0], dp2[0][1]), dp2[0][2]);
		cout << big << " " << small;
		return 0;
	}
	for (int i = 1; i < n; i++)
	{
		cin >> v[0];
		cin >> v[1];
		cin >> v[2];
		dp[1][0] = v[0] + max(dp[0][0], dp[0][1]);
		dp[1][1] = v[1] + max(max(dp[0][0], dp[0][1]),dp[0][2]);
		dp[1][2] = v[2] + max(dp[0][1], dp[0][2]);
		dp2[1][0] = v[0] + min(dp2[0][0], dp2[0][1]);
		dp2[1][1] = v[1] + min(min(dp2[0][0], dp2[0][1]), dp2[0][2]);
		dp2[1][2] = v[2] + min(dp2[0][1], dp2[0][2]);
		dp[0][0] = dp[1][0];
		dp[0][1] = dp[1][1];
		dp[0][2] = dp[1][2];
		dp2[0][0] = dp2[1][0];
		dp2[0][1] = dp2[1][1];
		dp2[0][2] = dp2[1][2];
	}
	int big = max(max(dp[1][0], dp[1][1]), dp[1][2]);
	int small = min(min(dp2[1][0], dp2[1][1]), dp2[1][2]);
	cout << big << " " << small;
}