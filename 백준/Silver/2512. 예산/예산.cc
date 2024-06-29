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

int dir[][2] = { {-1,0}, {0,1}, {1,0} ,{0,-1} };

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
	int n;
	cin >> n;
	vector<int> v;
	int maxV = 0;
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		sum += temp;
		maxV = max(maxV, temp);
		v.push_back(temp);
	}
	int m;
	cin >> m;
	int l = 0;
	int r = 100'000;
	int ans = 0;
	if (sum <= m)
	{
		ans = maxV;
	}
	else
	{

		while (l <= r)
		{
			int mid = (l + r) / 2;
			int mm = 0;
			for (int i = 0; i < n; i++)
			{
				if (v[i] <= mid)
				{
					mm += v[i];
				}
				else
				{
					mm += mid;
				}
			}
			if (mm > m)
			{
				r = mid - 1;
			}
			else
			{
				ans = max(ans, mid);
				l = mid + 1;
			}
		}
	}
	cout << ans;
}

