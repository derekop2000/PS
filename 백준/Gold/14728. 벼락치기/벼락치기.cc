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
#include<climits>
using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	vector<int> dp(k + 1);
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		for (int j = k; j >= a; j--)
		{
			dp[j] = max(dp[j], dp[j - a] + b);
		}
	}
	cout << dp[k];
}