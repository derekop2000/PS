#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int max_cast = 10000;
vector<int> dp;
int main()
{
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> app;
	dp.resize(max_cast+1,0);
	app.resize(n);
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		app[i].first = temp;
	}
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		app[i].second = temp;
	}
	
	for (int i = 0; i < n; i++)
	{
		for (int j = max_cast; j >= app[i].second; j--)
		{
			dp[j] = max(dp[j], dp[j - app[i].second]+app[i].first );
		}
	}
	int cast=-1;
	for (int i = 0; i <= max_cast; i++)
	{
		if (dp[i] >= m) { cast = i; break; }
	}
	cout << cast;
}

