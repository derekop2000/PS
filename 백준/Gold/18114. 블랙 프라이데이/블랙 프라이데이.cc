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
	int n, m;
	cin >> n >> m;
	vector<int> v;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end());
	bool ans = false;
	for (int i = 0;i < n; i++)
	{
		if (v[i] == m)
		{
			ans = true;
			break;
		}
		if (v[i] > m)
			continue;
		int goal = m - v[i];
		for (int j = 0; j < n; j++)
		{
			if (i == j) continue;
			if (v[j] == goal)
			{
				ans = true;
				break;
			}
			int index = upper_bound(v.begin(), v.end(), goal - v[i]) - v.begin();
			if (index == v.size() || index == i || index == j)
				continue;
			if (v[index] + v[j] == goal)
			{
				ans = true;
				break;
			}
		}
		if (ans)
			break;
	}
	if (ans)
		cout << "1";
	else cout << "0";
}

