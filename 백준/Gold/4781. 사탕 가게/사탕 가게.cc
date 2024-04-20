#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
#include<memory.h>
#include<string>
#include<sstream>
#include<algorithm>
#include<map>
#include<set>
#include<iomanip>
using namespace std;

int main()
{
	vector<int> dp(10001);

	while (true)
	{
		int n;
		double m;
		cin >> n >> m;
		m *= 100;
		if (n == 0)break;
		vector<int> dp(m + 1);
		for (int i = 0; i < n; i++)
		{
			int a;
			double b;
			cin >> a >> b;
			b *= 100;
			for (int j = b; j <= m; j++)
			{
				dp[j] = max(dp[j - b] + a, dp[j]);
			}
		}
		cout << dp[m]<<"\n";
	}
}