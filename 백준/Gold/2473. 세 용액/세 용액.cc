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
	long long int n;
	cin >> n;
	vector<long long int> v(n);
	for (long long int i = 0; i < n; i++)
		cin >> v[i];
	sort(v.begin(), v.end());
	long long int real_ans = v[0] + v[1] + v[2];
	tuple<long long int, long long int, long long int> real_triple = { 0,1,2 };
	for (long long int i = 1; i < n - 1;i++)
	{
		long long int l = 0;
		long long int r = n - 1;
		long long int ans = v[l] + v[r]+v[i];
		pair<long long int, long long int> ans_pair = { l,r };
		while (l < r)
		{
			long long int temp = v[l] + v[r]+v[i];
			if (abs(temp) < abs(ans))
			{
				ans = temp;
				ans_pair = { l,r };
			}
			if (temp < 0)
			{
				l++;
				if (l == i)l++;
			}
			else
			{
				r--;
				if (r == i)r--;
			}
		}
		if (abs(real_ans) > abs(ans))
		{
			real_ans = ans;
			real_triple = { i,ans_pair.first,ans_pair.second};
		} 
	}
	vector<long long int> vv;
	vv.push_back(get<0>(real_triple));
	vv.push_back(get<1>(real_triple));
	vv.push_back(get<2>(real_triple));
	sort(vv.begin(), vv.end());
	for (long long int i = 0; i < 3; i++)
		cout << v[vv[i]] << " ";
}