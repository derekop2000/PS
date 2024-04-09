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
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<int> arr(n);
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		sort(arr.begin(), arr.end());
		bool f = true;
		deque<int>dq;
		for (int i = 0; i < n; i++)
		{
			if(f)
			{
				dq.push_front(arr[i]);
				f = !f;
			}
			else
			{
				dq.push_back(arr[i]);
				f = !f;
			}
		}
		int ans = 0;
		for (int i = 0; i < n-1; i++)
		{
			ans = max(ans, abs(dq[i] - dq[i + 1]));
		}
		ans = max(ans, abs(dq[0] - dq[n - 1]));
		cout << ans << "\n";
	}
}