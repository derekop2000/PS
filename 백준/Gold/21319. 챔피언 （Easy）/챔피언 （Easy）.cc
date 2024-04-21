#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
#include<memory.h>
#include<string>
#include<sstream>
#include<algorithm>
#include<map>
#include<set>
#include<iomanip>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	vector<int> ans;
	int index = lower_bound(v.begin(), v.end(), v[n-1]) - v.begin();
	if (index == n - 1)
		ans.push_back(n - 1);
	int min_value = v[n - 1] + 1;
	for (int i = n-2; i >= 0; i--)
	{
		bool left = (i == lower_bound(v.begin(), v.end(), v[i]) - v.begin());
		bool right = (i + v[i] >= min_value);
		min_value = max(min_value - 1, v[i] + 1);
		if (left && right)
			ans.push_back(i);
	}
	int size = ans.size();
	if (size == 0)cout << "-1";
	else
	{
		for (int i = size - 1; i >= 0; i--)
			cout << ans[i] + 1 << " ";
	}
	
}