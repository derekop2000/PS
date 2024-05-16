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

int dir[8][2] = { {-1,0},{0,1},{1,0},{0,-1},{-1,1} ,{1,1},{1,-1} ,{-1,-1} };
int main()
{
	int arr[250][250];
	int n, m;
	cin >> n >> m;
	for(int i=0;i<n;i++)
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}

	function<void(int,int)> temp = [&](int r, int c)
		{
			arr[r][c] = 0;
			for (int i = 0; i < 8; i++)
			{
				int rr = r + dir[i][0];
				int cc = c + dir[i][1];
				if (0 <= rr && rr < n && 0 <= cc && cc < m && arr[rr][cc] == 1)
				{
					temp(rr, cc);
				}
			}
		};

	int cnt = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			
			if (arr[i][j])
			{
				temp(i, j);

				cnt++;
			}
		}
	cout << cnt;
}


