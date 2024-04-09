#include<iostream>
#include<vector>
using namespace std;
int dp[100001];
int ans = -1000;
int main()
{
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	vector<int> v;
	int n;
	cin >> n;
	v.resize(n+1);
	for(int i = 1; i <= n; i++)
		cin >> v[i];
	for (int i = 1; i <= n; i++)
	{
		if (v[i] <0)
		{
			dp[i] = dp[i - 1] + v[i];
		}
		else
		{
			if (dp[i - 1] > 0)
				dp[i] = dp[i - 1] + v[i];
			else dp[i] = v[i];
		}
		if (dp[i] > ans)
			ans = dp[i];
		if (v[i] > ans)
			ans = v[i];
	}
	cout << ans;
}