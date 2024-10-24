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

vector<vector<int>> arr;
vector<vector<bool>> visit;
vector<pair<int, int>> arr2;
int n, m;


bool f()
{
	if (arr2.size() == 0)
		return false;
	queue<tuple<int, int, int>> q;
	for (int i = 0; i < 4; i++)
	{
		q.push({ arr2.back().first,arr2.back().second ,i });
	}
	arr2.pop_back();
	while (q.empty() == false)
	{
		auto current = q.front(); q.pop();
		int d = get<2>(current);
		int y = get<0>(current) + dir[d][0];
		int x = get<1>(current) + dir[d][1];
		if (0 <= y && y < n && 0 <= x && x < m)
		{
			visit[y][x] = true;
			int value = arr[y][x];
			switch (value)
			{
			case 0:
			{
				q.push({ y,x,d });
				break;
			}
			case 1:
			{
				if (d == 0 || d == 2)
				{
					q.push({ y,x,d });
				}
				break;
			}
			case 2:
			{
				if (d == 1 || d == 3)
				{
					q.push({ y,x,d });
				}
				break;
			}
			case 3:
			{
				if (d == 0)
					d = 1;
				else if (d == 1)
				{
					d = 0;
				}
				else if (d == 2)
				{
					d = 3;
				}
				else d = 2;
				q.push({ y,x,d });
				break;
			}
			case 4:
			{
				if (d == 0)
					d = 3;
				else if (d == 1)
				{
					d = 2;
				}
				else if (d == 2)
				{
					d = 1;
				}
				else d = 0;
				q.push({ y,x,d });
				break;
			}
			case 9:
			{
				break;
			}
			}
		}
	}
	return true;
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
	cin >> n >> m;
	arr.resize(n, vector<int>(m));
	visit.resize(n, vector<bool>(m, false));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 9)
			{
				arr2.push_back({ i,j });
				visit[i][j] = true;
			}
		}
	while (f() == true)
	{
		;
	}
	int cnt = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (visit[i][j])
				cnt++;
	cout << cnt;
}


