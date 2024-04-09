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
	int n, k;
	cin >> n >> k;
	priority_queue<int, vector<int>, greater<int>> q;
	vector<int> v;
	v.push_back(n);
	int level = 0;
	while (true)
	{
		if (v[level] > 1)
		{
			int temp = v[level] / 2;
			v.push_back(temp);
			v[level] -= temp * 2;
			level++;
		}
		else break;
	}
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i])
		{
			int temp = (int)(pow(2, i));
			q.push(temp);
		}
	}
	int ans = 0;
	while (q.size() > k)
	{
		int now = q.top(); q.pop();
		if (now == q.top())
		{
			q.pop();
			q.push(now * 2);
		}
		else
		{
			ans += now;
			q.push(now * 2);
		}
	}
	cout << ans;
}