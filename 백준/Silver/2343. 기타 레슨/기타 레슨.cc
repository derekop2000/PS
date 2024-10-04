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

int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	long long int ans = 0;
	long long int l = 0, r = n * 10000;
	while (l <= r)
	{
		long long int mid = (l + r) / 2;
		int cnt = 0;
		long long int amount = 0;
		for (int i = 0; i < n; i++)
		{
			if (arr[i] > mid)
			{
				cnt = m + 1;
				break;
			}
			if (amount < arr[i])
			{
				amount = mid;
				cnt++;
			}
			amount -= arr[i];
			if (cnt > m)
				break;
		}
		if (cnt > m)
		{
			l = mid + 1;
		}
		else
		{
			r = mid - 1;
			ans = mid;
		}
	}
	cout << ans;
}

