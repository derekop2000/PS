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
	long long int ans = 0;
	vector<int> v;
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		long long int temp;
		cin >> temp;
		if (temp > 0)
		{
			cnt++;
			v.push_back(i);
			ans += temp;
		}
	}
	if (cnt == n)
	{

	}
	else if (cnt == 0)
	{
		ans = n / 2;
	}
	else
	{

		for (int i = 0; i < (int)v.size() - 1; i++)
		{
			int temp = v[i + 1] - v[i]-1;
			if (temp < 1)continue;
			ans += (temp +1) / 2;
		}
		int temp = (v[0] - 0) + (n - v[v.size() - 1] - 1);
		ans += (temp +1) / 2;
	}
	cout << ans;
}