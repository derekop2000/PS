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

int l, n;
vector<string> s;
vector<string> ss;
bool ans = false;
vector<bool> visit;

void f2()
{
	for(int i=0;i<l;i++)
		for (int j = 0; j < i; j++)
		{
			if (s[i][j] != s[j][i])
				return;
		}
	ans = true;
	for (int i = 0; i < l; i++)
		cout << s[i] << "\n";
}
void f(int floor)
{
	if (floor == l)
	{
		f2();
		return;
	}
	for (int i = 0; i < n; i++)
	{
		if (visit[i])continue;
		visit[i] = true;
		s.push_back(ss[i]);
		f(floor + 1);
		if (ans)return;
		visit[i] = false;
		s.pop_back();
	}
}
int main()
{
	cin >> l >> n;
	visit.resize(n);
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		::ss.push_back(s);
	}
	sort(ss.begin(), ss.end());
	f(0);
	if (ans==false)
		cout << "NONE";
}

