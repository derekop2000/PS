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

int n, c;
vector<int> arr;
vector<int> dp;
int main()
{
	cin >> n >> c;
	arr.resize(n);
	dp.resize(c + 1,101);
	dp[0] = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = c; j >= arr[i]; j--)
		{
			dp[j] = min(dp[j - arr[i]] + 1, dp[j]);
		}
	}
	if (dp[c] > 100)
		cout << "-1";
	else
		cout << dp[c];
}