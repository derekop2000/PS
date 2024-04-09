#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
#include<memory.h>
#include<string>
using namespace std;

int dp[201][3][201];
int arr[201][2];
int main()
{
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i][0] >> arr[i][1];
	}
	int temp;
	cin >> temp >> temp;
	for (int i = 1; i <= n; i++)
	{
		dp[i][2][0] = dp[i - 1][2][0]+arr[i][0]+arr[i][1];
		for (int j = 1; j <= i; j++)
		{
			dp[i][0][j] = max(dp[i-1][0][j - 1], dp[i-1][2][j - 1]) + arr[i][1];
			dp[i][1][j] = max(dp[i-1][1][j - 1], dp[i-1][2][j - 1]) + arr[i][0];
			int temp = max(max(dp[i - 1][0][j], dp[i - 1][1][j]), dp[i - 1][2][j]);
			if(temp>0)
				dp[i][2][j] = temp + arr[i][1]+arr[i][0];
		}
	}
	int ans = max(max(dp[n][0][k], dp[n][1][k]), dp[n][2][k]);
	cout << ans;
}
  
