#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<map>
#include<sstream>
using namespace std;

int dp[1001];
int main()
{
	int arr[1001];
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	for (int i = 2; i <= n; i++)
	{
		int max_ = arr[i];
		int min_ = arr[i];
		for (int j = i - 1; j > 0; j--)
		{
			max_ = max(max_, arr[j]);
			min_ = min(min_, arr[j]);
			dp[i] = max((max_ - min_ + dp[j - 1]), dp[i]);
		}
	}
	cout << dp[n];
}

