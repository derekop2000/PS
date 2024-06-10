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
	vector<int> v(n);
	vector<int> v2(10);
	int cnt = 0;
	for (int i = 0; i < n; i++)
		cin >> v[i];
	int l = -1, r = -1;
	int ans = 0;
	while (true)
	{
		r++;
		if (r == n)
			break;
		int value = v[r];
		if (v2[value])
		{
			v2[value]++;
			ans = max(ans, r - l);
		}
		else
		{
			if (cnt < 2)
			{
				cnt++;
				v2[value]++;
				ans = max(ans, r - l);
			}
			else
			{
				while (cnt == 2)
				{
					l++;
					int value2 = v[l];
					v2[value2]--;
					if (v2[value2] == 0)
						cnt--;
				}
				r--;
			}
		}
	}
	cout << ans;
}