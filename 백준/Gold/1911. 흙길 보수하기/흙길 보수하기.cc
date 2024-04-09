#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
#include<string>
using namespace std;


int main()
{
	int n, l;
	cin >> n >> l;
	vector<pair<int, int>> arr(n);
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		arr[i] = make_pair(a, b-1);
	}
	sort(arr.begin(),arr.end());
	int ans = 0;
	int safe_zone = -1;
	for (int i = 0; i < n; i++)
	{
		safe_zone = max(arr[i].first - 1,safe_zone);
		int left_dist = arr[i].second - safe_zone;
		if (left_dist <= 0)continue;
		int add = left_dist / l;
		if (left_dist % l)add++;
		ans += add;
		safe_zone += l * add;
	}
	cout << ans;
}
