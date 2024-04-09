#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> dp(n + 1, 0);
	dp[0] = 1;
	for (int i = 1; i <= n; i *= 2)
	{
		for (int j = i; j <= n; j++)
		{
			dp[j] += dp[j - i];
			dp[j] %= 1000000000;
		}
	}
	cout << dp[n];
}
