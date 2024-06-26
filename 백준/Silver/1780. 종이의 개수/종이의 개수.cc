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


vector<vector<int>> arr;
int ans[] = { 0,0,0 };
void f(int r, int c, int n)
{
	int first = arr[r][c];
	bool surveAns = true;
	for(int i=r;i<r+n && surveAns;i++)
		for (int j = c; j < c + n ; j++)
		{
			if (arr[i][j] != first)
			{
				surveAns = false;
				break;
			}
		}
	if (surveAns)
	{
		ans[first + 1]++;
		return;
	}
	else
	{
		int n3= n / 3;
		for(int i=0;i<3;i++)
			for (int j = 0; j < 3; j++)
			{
				f(r+n3 * i, c+n3 * j, n3);
			}
	}
}
int main()
{
	int n;
	cin >> n;
	arr.resize(n, vector<int>(n));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}
	f(0, 0, n);
	cout << ans[0] << "\n" << ans[1] << "\n" << ans[2];
}

