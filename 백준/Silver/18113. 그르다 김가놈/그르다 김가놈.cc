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
#include <functional>

using namespace std;

int dir[][2] = { {-1,0}, {0,1}, {1,0} ,{0,-1},{-1,1},{1,1},{1,-1},{-1,-1} };

vector<int> parent;
int findParent(int a)
{
	if (parent[a] == a)
		return a;
	return parent[a] = findParent(parent[a]);
}
void Union(int a, int b)
{
	parent[findParent(b)] = findParent(a);
}
bool IsUnion(int a, int b)
{
	return findParent(a) == findParent(b);
}

int main()
{
	int n, k, m;
	cin >> n >> k >> m;
	vector<int> v;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		if (temp >= k * 2)
			temp -= k * 2;
		else temp -= k;
		if (temp > 0)
			v.push_back(temp);

	}
	int ans = -1;
	int l = 1;
	int r = 1'000'000'000;
	while (l <= r)
	{
		int mid = (l + r) / 2;
		int cnt = 0;
		for (auto value : v)
		{
			cnt += value / mid;
		}
		if (cnt >= m)
		{
			ans = mid;
			l = mid + 1;
		}
		else
		{
			r = mid - 1;
		}
	}
	cout << ans;
}

