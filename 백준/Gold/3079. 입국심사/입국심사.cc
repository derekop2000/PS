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

int main(void)
{
	int n, m;
	long long r, l, mid, sum, ans;
	cin >> n >> m;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	r = (long long int)m * v[0];
	ans = r;
	l = 0;
	while (l<=r)
	{
		mid = (l+r) / 2;
		sum = 0;
		for (int i = 0; i < n; i++)
		{
			sum += mid / v[i];
			if (sum >= m)
				break;
		}
		if (sum >= m)
		{
			ans = min(ans, mid);
			r = mid - 1;
		}
		else
			l = mid + 1;
	}
	cout << ans;
}
