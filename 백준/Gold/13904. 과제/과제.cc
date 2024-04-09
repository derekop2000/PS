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
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<pair<int, int>> arr;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		arr.push_back({ a,b });
	}
	sort(arr.begin(), arr.end());
	int ans = 0;
	int last_day = arr[arr.size() - 1].first;
	int index = 0;
	priority_queue<int,vector<int>,greater<int>> q;
	q.push(0);
	for (int i = 1; i <= last_day; i++)
	{
		while (index < arr.size())
		{
			if (arr[index].first > i)
				break;
			if (i > q.size())
				q.push(arr[index].second);
			else if (arr[index].second > q.top())
			{
				q.pop();
				q.push(arr[index].second);
			}
			index++;
		}
	}
	while (!q.empty())
	{
		ans += q.top();
		q.pop();
	}
	cout << ans;
}
