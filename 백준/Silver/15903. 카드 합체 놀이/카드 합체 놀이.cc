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
	int n, m;
	cin >> n >> m;
	priority_queue<long long int, vector<long long int>, greater<long long int>> q;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		q.push(temp);
	}
	for (int i = 0; i < m; i++)
	{
		long long int a, b;
		a = q.top();
		q.pop();
		b = q.top();
		q.pop();
		q.push(a + b);
		q.push(a + b);
	}
	long long int ans = 0;
	while (!q.empty())
	{
		ans += q.top(); q.pop();
	}
	cout << ans;
}