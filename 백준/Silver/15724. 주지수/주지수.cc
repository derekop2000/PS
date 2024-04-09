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
     ios_base::sync_with_stdio(0);cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> arr(n, vector<int>(m));
	vector<vector<int>> dp(n, vector<int>(m));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];
	dp[0][0] = arr[0][0];
	for (int j = 1; j < m; j++)
		dp[0][j] = dp[0][j - 1] + arr[0][j];
	for (int i = 1; i < n; i++)
	{
		int temp = 0;
		for (int j = 0; j < m; j++)
		{
			temp += arr[i][j];
			dp[i][j] = dp[i - 1][j] + temp;	
		}
	}
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		a--; b--; c--; d--;
		pair<int, int> first = { c,b - 1 };
		pair<int, int> second = { a - 1,d };
		int ans = 0;
		ans = dp[c][d];
		if (first.second >= 0)
		{
			ans -= dp[first.first][first.second];
		}
		if (second.first >= 0)
		{
			ans -= dp[second.first][second.second];
		}
		if (a > 0 && b > 0)
		{
			ans += dp[a - 1][b - 1];
		}
		cout << ans << "\n";
	}
}