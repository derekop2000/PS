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


int main()
{
	int n, k;
	cin >> n >> k;
	vector<int> dp(n + 1, 0);
	dp[0] = 1;
	for (int i = 0; i < k; i++)
	{
		int a, b;
		cin >> a >> b;
		vector<int> dp2(n + 1, 0);
		for (int j = 1; j <= b; j++)
		{
			int temp = a * j;
			for (int q = n; q >=temp; q--)
			{
				if (dp[q - temp])
					dp2[q] += dp[q - temp];
					//dp[q] = dp[q - temp] + dp[q];
			}
		}
		for (int j = 1; j <= n; j++)
			dp[j] += dp2[j];
	}
	cout << dp[n];
}