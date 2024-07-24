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

int n, m;
int cnt = 0;
vector<vector<int>> arr;
void f(int r, int c, int num1, int num2,int now)
{
	int rr = r + dir[1][0];
	int cc = c + dir[1][1];
	if (cc < m && arr[rr][cc] > 0)
	{
		if (arr[rr][cc] == 1 && arr[rr][cc] != now)
		{
			arr[rr][cc] = 0;
			f(rr, cc, num1 + 1, num2, 1);
		}
		else if(arr[rr][cc] == 2 && arr[rr][cc] != now)
		{
			arr[rr][cc] = 0;
			f(rr, cc, num1, num2+1,2);
		}
		else
		{
		arr[rr][cc] = 0;
		f(rr, cc, num1, num2,now);

		}
	}
	else
	{
		cnt += min(num1, num2);
		cnt++;
	}
}
int main()
{
	cin >> n >> m;
	arr.resize(n, vector<int>(m));
	for(int i=0;i<n;i++)
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];

		}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			if(arr[i][j]==1)
				f(i, j, 1, 0,1);
			else if (arr[i][j] == 2)
				f(i, j, 0, 1,2);
		}
	cout << cnt;
}

