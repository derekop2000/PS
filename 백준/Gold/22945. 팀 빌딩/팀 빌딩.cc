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
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	int l = 0, r = n - 1;
	int ans = (r - l - 1) * min(arr[l], arr[r]);
	while (l + 1 < r)
	{
		ans = max(ans, (r - l - 1) * min(arr[l], arr[r]));
		if (arr[l] < arr[r])
			l++;
		else r--;
	}
	cout << ans;
}
