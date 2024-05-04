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
#include<climits>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int ans = 0;
	vector<int> v;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		if (temp > 0)
		{
			v.push_back(i);
			ans += temp;
		}
	}
	for (int i = 0; i < (int)v.size() - 1; i++)
	{
		int temp = v[i + 1] - v[i]-1;
		if (temp < 1)continue;
		ans++;
		ans += (temp - 1) / 2;
	}
	int temp;
	if (v.size() > 0)
	{
		temp = (v[0] - 0) + (n - v[v.size() - 1] - 1);
	}
	else temp = n-1;
	if (temp >= 1)
	{
		ans++;
		ans += (temp - 1) / 2;
	}
	cout << ans;
}