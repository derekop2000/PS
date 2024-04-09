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
	vector<int> arr;
	cin >> n;
	arr.resize(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	long long int ans = 0;
	priority_queue<int, vector<int>, greater<int>> q;
	
	for (int i = 0; i < n; i++)
	{
		ans += n - 1 - i;
		int cnt = 0;
		while (!q.empty()&&q.top() <= arr[i])
		{
			cnt++;
			q.pop();
		}
		ans -= cnt * (n - i);
		q.push(arr[i]);
	}
	cout << ans;
}
 