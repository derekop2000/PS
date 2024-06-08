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

int n;
vector<int> a;
vector<int> b;
vector<int> c;
int main()
{
	int n;
	vector<pair<int, int>> v;
	int maxV = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
		if (b > maxV)
			maxV = b;
	}
	sort(v.begin(), v.end());
	int level = 0;
	int ans = 0;
	int lastPoint = v[0].first;
	int A = 0;
	for (int now = 0; now < v.size(); now++)
	{
		int a = v[now].first;
		int b = v[now].second;
		
		if (level < b)
		{
			ans += level * (a - lastPoint);
			level = b;
			lastPoint = a;
		}
		if (b == maxV)
		{
			A = a;
			break;
		}
	}
	lastPoint = v[v.size() - 1].first + 1;
	level = 0;
	int B = 0;
	for (int now = v.size() - 1; now >= 0; now--)
	{
		int a = v[now].first;
		int b = v[now].second;
		if (level < b)
		{
			ans += level * (lastPoint -(a+1));
			level = b;
			lastPoint = a+1;
		}
		if (b == maxV)
		{
			B = a + 1;
			break;
		}
	}
	ans += maxV * (B - A);
	cout << ans;
}