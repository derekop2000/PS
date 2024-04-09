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
	int n, m;
	cin >> n >> m;
	vector<int> arr;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		arr.push_back(temp);
	}
	int ans = INT_MAX;
	sort(arr.begin(), arr.end());
	for (int i = 0; i < n; i++)
	{
		int _index = lower_bound(arr.begin(), arr.end(), arr[i] + m) - arr.begin();
		if (_index == arr.size())break;
		ans = min(ans, arr[_index] - arr[i]);
	}
	cout << ans;
}
