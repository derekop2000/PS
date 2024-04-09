#include<iostream>
#include<vector>
using namespace std;


int main()
{
	int n, m;
	cin >> m >> n;
	vector<vector<long long int>> dp(n+1,vector<long long int>(m+1,0));
	vector<vector<vector<bool>>> arr(n+1, vector<vector<bool>>(m+1, vector<bool>(2,true)));
	
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int a, b, c, d;
		cin >> b >> a >> d >> c;
		if (a + b > c + d)
		{
			a = a + c;
			c = a - c;
			a = a - c;
			b = b + d;
			d = b - d;
			b = b - d;
		}
		int row_col = 1;
		if (c > a)row_col = 0;
		arr[a][b][row_col] = false;
	}
	dp[0][0] = 1;
	for(int i=0;i<=n;i++)
		for (int j = 0; j <=m; j++)
		{
			if (i == 0 && j == 0)continue;
			int x1, y1, x2, y2;
			long long int a1 = 0, a2 = 0;
			x1 = i-1;
			y1 = j;
			x2 = i;
			y2 = j-1;
			if (0 <= x1 && x1 <= n && 0 <= y1 && y1 <= m && arr[x1][y1][0])
			{
				a1 = dp[x1][y1];
			}
			if (0 <= x2 && x2 <= n && 0 <= y2 && y2 <= m && arr[x2][y2][1])
			{
				a2 = dp[x2][y2];
			}
			dp[i][j] = a1 + a2;
		}
	cout << dp[n][m];
}