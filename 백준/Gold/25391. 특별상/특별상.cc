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
bool f(pair<long long int, long long int>& a, pair<long long int, long long int>& b)
{
	if (a.first == b.first)
		return a.second > b.second;
	else return a.first > b.first;
}

int main()
{
	long long int n, m, k;
	cin >> n >> m >> k;
	vector<pair<long long int, long long int>> arr;
	arr.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i].second >> arr[i].first;
	}
	sort(arr.begin(), arr.end(), f);
	long long int ans = 0;
	for (int i = 0; i < k; i++)
	{
		ans += arr[i].second;
	}
	priority_queue<long long int>q;

	for (int i = k; i < n; i++)
	{
		q.push(arr[i].second);
	}
	for(int i=0;i<m;i++)
	{
		ans += q.top();
		q.pop();
	}
	cout << ans;
}
