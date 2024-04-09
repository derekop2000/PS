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
using namespace std;

int main()
{
	vector<long long int> dp;
	int n;
	cin >> n;
	dp.resize(101);
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;
	dp[4] = 4;
	dp[5] = 5;
	dp[6] = 6;
	for (int i = 7; i <= n; i++)
	{
		long long int temp = 0;
		for (int j = i - 3; j > 0; j--)
		{
			temp = max(dp[j] * (i - j - 1), temp);
		}
		dp[i] = temp;
	}
	cout << dp[n];
}
