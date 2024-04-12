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
using namespace std;

vector<int> parent;
int find_parent(int a)
{
	if (parent[a] == a)return a;
	return parent[a] = find_parent(parent[a]);
}
void my_union(int a, int b)
{
	parent[find_parent(b)] = find_parent(a);
}
bool my_is_union(int a, int b)
{
	return find_parent(a) == find_parent(b);
}
int main()
{
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> moneys;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		moneys.push_back(temp);
		parent.push_back(i);
	}
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		a--; b--;
		my_union(a, b);
	}
	int ans = 0;
	map<int, int> map;
	for (int i = 0; i < n; i++)
	{
		int GrandParent = find_parent(i);
		auto it = map.find(GrandParent);
		if (it == map.end())
		{
			map[GrandParent] = moneys[i];
			ans += moneys[i];
		}
		else
		{
			if (map[GrandParent] > moneys[i])
			{
				ans -= map[GrandParent];
				ans += moneys[i];
				map[GrandParent] = moneys[i];
			}
		}
	}
	if (ans > k)cout << "Oh no";
	else cout << ans;
}