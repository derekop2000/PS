#include <iostream>
#include<vector>
#include<queue>
#include<tuple>
#include<map>
#include<algorithm>
using namespace std;

int c, n;
vector<int> dp;
int main()
{
	cin >> c >> n;
	dp.resize(c + 1, 2147483640);
	dp[0] = 0;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		for (int j = 1; j <= c; j++)
		{
			if (j < b)dp[j] = min(dp[j], a);
			else
			{
				if (dp[j] > dp[j - b] + a)
				{
					dp[j] = dp[j - b] + a;
				}
			}
		}
	}
	cout << dp[c];
}