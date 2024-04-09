#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

	int n, h;
	cin >> n >> h;
	vector<int> arr(n/2);
	vector<int> arr2(n/2);
	for (int i = 0; i < n / 2; i++)
		cin >> arr[i] >> arr2[i];
	sort(arr.begin(), arr.end());
	sort(arr2.begin(), arr2.end());
	int ans = 2147483647;
	int cnt = 0;
	for (int i = 0; i < h; i++)
	{
		int temp_ans = 0;
		int temp = upper_bound(arr.begin(), arr.end(),i) - arr.begin();
		if (temp != n / 2)temp_ans += n/2-temp;
		temp = upper_bound(arr2.begin(), arr2.end(), h - i-1) - arr2.begin();
		if (temp != n / 2)temp_ans += n / 2 - temp;
		if (temp_ans < ans)
		{
			ans = temp_ans;
			cnt = 1;
		}
		else if (temp_ans == ans)
			cnt++;
	}
	cout << ans << " " << cnt;
}