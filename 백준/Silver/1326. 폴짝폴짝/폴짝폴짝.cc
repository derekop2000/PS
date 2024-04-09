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

int n, a, b;
vector<int> arr;
vector<int> dp;
void f(int num)
{
	queue<int> q;
	q.push(num);
	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		int r = 1;
		while (true)
		{
			int next = now + arr[now] * r;
			if (next >= n)break;
			if (dp[next] > dp[now] + 1)
			{
				dp[next] = dp[now] + 1;
				q.push(next);
			}
			r++;
		}
		int l = -1;
		while (true)
		{
			int next = now + arr[now] * l;
			if (next<0)break;
			if (dp[next] > dp[now] + 1)
			{
				dp[next] = dp[now] + 1;
				q.push(next);
			}
			l--;
		}

	}
}
int main()
{
	cin >> n;
	arr.resize(n);
	dp.resize(n,INT_MAX);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	cin >> a >> b;
	a--; b--;
	dp[a] = 0;
	f(a);
	if (dp[b] == INT_MAX)cout << "-1";
	else cout << dp[b];
}