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

int cnt;
int n, m;
void f(vector<vector<int>>& arr, int r, int c)
{
	for (int i = 0; i < 8; i++)
	{
		int rr = r + dir[i][0];
		int cc = c + dir[i][1];
		if (0 <= rr && rr < n && 0 <= cc && cc < m && arr[rr][cc])
		{
			arr[rr][cc] = 0;
			f(arr, rr, cc);
		}
	}
}
int main()
{
	while (true)
	{
		cin >> m >> n;
		if (n == 0)
			break;
		vector<vector<int>> arr(n, vector<int>(m));
		for(int i=0;i<n;i++)
			for (int j = 0; j < m; j++)
			{
				cin >> arr[i][j];
			}
		cnt = 0;
		for(int i=0;i<n;i++)
			for (int j = 0; j < m; j++)
			{
				if (arr[i][j])
				{
					cnt++;
					f(arr, i, j);
				}
			}
		cout << cnt<<"\n";
	}
}

