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

int cnt = 0;
int n, m;
vector<vector<char>> v;
void f(int r, int c)
{
	for (int i = 0; i < 4; i++)
	{
		int rr = r + dir[i][0];
		int cc = c + dir[i][1];
		if (0 <= rr && rr < n && 0 <= cc && cc < m && v[rr][cc] != 'X')
		{
			if (v[rr][cc] == 'P')
				cnt++;
			v[rr][cc] = 'X';
			f(rr, cc);
		}
	}
}
pair<int, int> pos;
int main()
{
	cin >> n >> m;
	v.resize(n, vector<char>(m));
	for(int i=0;i<n;i++)
		for (int j = 0; j < m; j++)
		{
			cin >> v[i][j];
			if (v[i][j] == 'I')
			{
				pos = { i,j };
			}
		}
	f(pos.first, pos.second);
	if (cnt)
		cout << cnt;
	else cout << "TT";
}

