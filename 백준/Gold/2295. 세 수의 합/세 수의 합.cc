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
#include <unordered_set>
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

bool myCompare(tuple<int, int, int>& a, tuple<int, int, int>& b)
{
	if (get<0>(a) == get<0>(b))
	{
		return get<2>(a) > get<2>(b);
	}
	else return get<0>(a) < get<0>(b);
}
int main()
{
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	sort(v.begin(), v.end());
	vector<tuple<int, int, int>> v2;
	for(int i=0;i<n;i++)
		for (int j = i + 1; j < n; j++)
		{
			v2.push_back({ v[j] - v[i],v[i],v[j] });
		}
	sort(v2.begin(), v2.end(),myCompare);
	int ans = -1;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			int l = 0;
			int r = v2.size()-1;
			int sum = v[i] + v[j];
			int index = -1;
			while (l <= r)
			{
				int mid = (l + r) / 2;
				int value = get<0>(v2[mid]);
				int ii = get<1>(v2[mid]);
				int jj = get<2>(v2[mid]);
				if (sum <= value)
				{
					if (sum == value)
						index = mid;
					r = mid - 1;
				}
				else if (sum > value)
				{
					l = mid + 1;
				}
			}
			if (index == -1)
				continue;
			ans = max(get<2>(v2[index]), ans);
		}
	cout << ans;
}

