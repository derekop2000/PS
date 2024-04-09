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
	int n, d, k, c;
	cin >> n >> d >> k >> c;
	c--;
	vector<int> arr;
	vector<int> collected;
	collected.resize(d);
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		arr.push_back(temp-1);
	}
	for (int i = 0; i < k; i++)
	{
		collected[arr[i]]++;
		if (collected[arr[i]] == 1)cnt++;
	}
	int ans = cnt;
	if (collected[c] == 0)ans++;
	for (int i = k; i < n; i++)
	{
		collected[arr[i]]++;
		if (collected[arr[i]] == 1)cnt++;
		
		collected[arr[i-k]]--;
		if (collected[arr[i-k]] == 0)cnt--;
		bool coupon = false;
		if (collected[c] == 0)coupon = true;
		if (coupon)
			ans = max(ans, cnt + 1);
		else ans = max(ans, cnt);
	}
	for (int i = n-k; i < n; i++)
	{
		int next = (i + k) % (n);
		collected[arr[next]]++;
		if (collected[arr[next]] == 1)cnt++;

		collected[arr[i]]--;
		if (collected[arr[i]] == 0)cnt--;
		bool coupon = false;
		if (collected[c] == 0)coupon = true;
		if (coupon)
			ans = max(ans, cnt + 1);
		else ans = max(ans, cnt);
	}
	cout << ans;
}
 