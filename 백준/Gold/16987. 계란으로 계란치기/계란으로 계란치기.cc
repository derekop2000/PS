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

int n;
vector<pair<int, int>> arr;
int ans = 0;
void f(int now)
{
	if (now >= n)
	{
		int temp=0;
		for (int i = 0; i < n; i++)
		{
			if (arr[i].first < 1)
				temp++;
		}
		ans = max(ans, temp);
		return;
	}
	if (arr[now].first < 1)
	{
		f(now + 1);
		return;
	}
	bool last = true;
	for (int i =0; i < n; i++)
	{
		if (arr[i].first < 1 || i==now)continue;
		last = false;
		arr[now].first -= arr[i].second;
		arr[i].first -= arr[now].second;
		f(now + 1);
		arr[now].first += arr[i].second;
		arr[i].first += arr[now].second;
	}
	if(last)
		f(now + 1);
}
int main()
{
	cin >> n;
	arr.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i].first >> arr[i].second;
	}
	f(0);
	cout << ans;
}
 