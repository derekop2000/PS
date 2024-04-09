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
#include<sstream>
#include<deque>
using namespace std;


int main()
{
	int n;
	cin >> n;
	vector<int> arr(n);
	bool _zero = false;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		if (arr[i] == 0)_zero = true;
	}
	sort(arr.begin(), arr.end());
	int l = 1;
	int r = n - 2;
	int ans = 0;
	int rr = n - 1;
	while (r>=0 && arr[r]>1)
	{
		ans += arr[r] * arr[r + 1];
		rr = r-1;
		r -= 2;
	}
	while (l<n&&arr[l]<0)
	{
		ans += arr[l] * arr[l - 1];
		l += 2;
	}
	l--;
	for (; l <= rr; l++)
	{
		if (arr[l] < 0)
		{
			if (!_zero)ans += arr[l];
			continue;
		}
		ans += arr[l];
	}
	cout << ans;
}