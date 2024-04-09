#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, k;
vector<pair<int, int>> arr;
vector<int> bags;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin >> n >> k;
	arr.resize(n);
	bags.resize(k);
	for (int i = 0; i < n; i++)
		cin >> arr[i].first >> arr[i].second;
	for (int i = 0; i < k; i++)
		cin >> bags[i];
	sort(arr.begin(), arr.end());
	sort(bags.begin(), bags.end());

	priority_queue<int, vector<int>> q;
	int index = 0;
	long long int ans = 0;
	for (int i = 0; i < k; i++)
	{
		while (index < n && arr[index].first<=bags[i])
		{
			q.push(arr[index].second);
			index++;
		}
		if (!q.empty())
		{
			ans += q.top();
			q.pop();
		}
	}
	cout << ans;
}