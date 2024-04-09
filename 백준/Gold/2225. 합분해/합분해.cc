#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
#include<string>
using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	vector<vector<int>> dp(k+1,vector<int>(n+1,0));
	for (int i = 0; i <= n; i++)
		dp[1][i] = 1;
	for(int i=2;i<=k;i++)
		for (int j = 0; j <= n; j++)
		{
			for (int q = 0; q <= j; q++)
			{
				dp[i][j] += dp[i - 1][q];
				dp[i][j] %= 1000000000;
			}
		}
	cout << dp[k][n];
}
