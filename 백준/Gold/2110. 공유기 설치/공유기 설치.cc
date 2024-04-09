#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;


int main()
{
	int n, c;
	cin >> n >> c;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	sort(v.begin(), v.end(), less<int>());
	
	int start = 1;
	int end = v[v.size() - 1];
	int mid;
	int ans = 1;
	while (start <= end)
	{
		int mid = (end + start) / 2;
		int cnt = 1;
		int last_pos = v[0];
		for (int i = 1; i < v.size(); i++)
		{
			if (v[i] - last_pos >= mid)
			{
				cnt++;
				last_pos = v[i];
			}
		}

		if (cnt == c)
		{
			start = mid + 1;
			ans = max(ans, mid);
		}
		else if (cnt > c)
		{
			start = mid + 1;
			ans = max(ans, mid);
		}
		else
		{
			end = mid - 1;
		}
	}
	cout << ans;
}