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
using namespace std;

bool f(pair<int,int>a, pair<int,int> b)
{
	return a.second > b.second;
}

int main()
{
	int n;
	cin >> n;
	vector<pair<int, int>> v;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}
	sort(v.begin(), v.end(), f);
	int temp = 1000000;
	for (int i = 0; i < n; i++)
	{
		v[i].second = min(v[i].second, temp);
		temp = v[i].second - v[i].first;
		if (temp < 0)
			break;
	}
	if (temp < 0)temp = -1;
	cout << temp;
}
