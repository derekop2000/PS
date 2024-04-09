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
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	sort(v.begin(), v.end());
	int l = 0;
	int r = n - 1;
	int ans = v[l] + v[r];
	pair<int, int> ans_pair = { l,r };
	while (l < r)
	{
		int temp = v[l] + v[r];
		if (abs(temp) < abs(ans))
		{
			ans = temp;
			ans_pair = { l,r };
		}
		if (temp < 0)
		{
			l++;
		}
		else r--;
	}
	cout << v[ans_pair.first] << " " << v[ans_pair.second];
}