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

vector<vector<int>> arr;
vector<vector<bool>> visit;
int r, c, k;
int ans = 0;
void f(int rr, int cc,int cnt)
{
	if (rr == 0 && cc == c - 1)
	{
		if (cnt == k)
			ans++;
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		int rrr = rr + dir[i][0];
		int ccc = cc + dir[i][1];
		if (0 <= rrr && rrr < r && 0 <= ccc && ccc < c && arr[rrr][ccc] ==0 && visit[rrr][ccc]==false)
		{
			visit[rrr][ccc] = true;
			f(rrr, ccc, cnt + 1);
			visit[rrr][ccc] = false;
		}
	}
}
int main()
{
	cin >> r >> c >> k;
	k--;
	arr.resize(r, vector<int>(c));
	visit.resize(r, vector<bool>(c));
	for(int i=0;i<r;i++)
		for (int j = 0; j < c; j++)
		{
			char c;
			cin >> c;
			if (c == '.')
				arr[i][j] = 0;
			else arr[i][j] = 1;
		}
	visit[r - 1][0] = true;
	f(r - 1, 0,0);
	cout << ans;
}

