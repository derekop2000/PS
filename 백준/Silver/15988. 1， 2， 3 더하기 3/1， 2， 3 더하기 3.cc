#include<iostream>
using namespace std;
long long int dp[1000001];
int main()
{
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= 1000000; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
		dp[i] %= 1000000009;
	}
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		cout << dp[n] << '\n';
	}
}