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


int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> arr(n,vector<int>(m));
	for(int i=0;i<n;i++)
		for (int j = 0; j < m; j++)
		{
			int temp;
			cin >> temp;
			if (temp == 0)
				arr[i][j] = 1;
		}
	int ans = 0;
	for(int i = n-1;i>=0;i--)
		for (int j = m - 1; j >= 0; j--)
		{
			if (arr[i][j] == 0)continue;
			int r = 0;
			int u = 0;
			if (j + 1 < m)
			{
				r = arr[i][j + 1];
			}
			if (i + 1 < n)
			{
				u = arr[i + 1][j];
			}
			int value = min(r, u);
			if (i + value < n && j + value < m && arr[i + value][j + value])
				value++;
			arr[i][j] = max(1,value);
			ans = max(ans, arr[i][j]);
		}
	cout << ans;

	
}

