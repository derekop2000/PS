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

int n;
vector<int> goal = {0,0,0};
set<tuple<int, int, int>> visit;
vector<vector<int>> list=
{ {1,3,9},{1,9,3},{3,1,9},{3,9,1},{9,1,3},{9,3,1} };
int ans = 9999;
void f(int a, int b, int c,int cnt)
{
	if (a >= goal[0] && b >= goal[1] && c >= goal[2])
	{
		ans = min(ans, cnt);
		return;
	}
	for (int i = 0; i < 6; i++)
	{
		int aa = a + list[i][0];
		int bb = b + list[i][1];
		int cc = c + list[i][2];
		if (bb > cc)
		{
			bb += cc;
			cc = bb - cc;
			bb -= cc;
		}
		if (aa > bb)
		{
			aa += bb;
			bb = aa - bb;
			aa -= bb;
		}
		if (bb > cc)
		{
			bb += cc;
			cc = bb - cc;
			bb -= cc;
		}
		tuple<int, int, int> temp = { aa,bb,cc };
		if (visit.find(temp) == visit.end())
		{
			visit.insert(temp);
			f(aa, bb, cc, cnt + 1);
		}
	}
}
int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> goal[i];
	}
	sort(goal.begin(), goal.end());
	f(0, 0, 0, 0);
	cout << ans;
}

