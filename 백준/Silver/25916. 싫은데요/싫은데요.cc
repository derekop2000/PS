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
using namespace std;



int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	int ans = 0;
	int l = 0, r = 0, now = v[0];
	while (true)
	{
		bool plus = false;
		if (now > m)
		{
			now -= v[l];
			l++;
			if (r < l)
			{
				r++;
				plus = true;
			}
		}
		else
		{
			r++;
			plus = true;
		}
		if (r >= n)
			break;
		if (plus)
		{
			now += v[r];
		}
		if(now <=m)
			ans = max(ans, now);
	}
	cout << ans;
}