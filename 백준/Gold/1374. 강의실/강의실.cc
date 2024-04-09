#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
#include<string>
#include<set>
#include<map>

using namespace std;
bool f(pair<int, int> &a, pair<int, int> &b)
{
	return a.second < b.second;
}
vector<pair<int,int>> arr;
int main()
{
	int n;
	cin >> n;
	arr.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i].first >> arr[i].first >> arr[i].second;
	}
	sort(arr.begin(), arr.end());
	priority_queue<int, vector<int>, greater<int>> q;
	q.push(0);
	int ans = 1;
	for (int i = 0; i < n; i++)
	{
		if (q.top() <= arr[i].first)
		{
			q.pop();
		}
		else ans++;
		q.push(arr[i].second);
	}
	cout << ans;
}
