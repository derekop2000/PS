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
int ans = 0;
void f(vector<vector<int>>& arr, int i, int j)
{
	queue<tuple<int, int,int>> q;
	q.push({ i,j,0 });
	while (q.empty() == false)
	{
		auto current = q.front(); q.pop();
		int ii = get<0>(current);
		int jj = get<1>(current);
		int value = get<2>(current);
		for (int d = 0; d < 8; d++)
		{
			int iii = ii + dir[d][0];
			int jjj = jj + dir[d][1];
			int value2 = value + 1;
			if (0 <= iii && iii < n && 0 <= jjj && jjj < m && arr[iii][jjj] != -1 && value2 < arr[iii][jjj])
			{
				arr[iii][jjj] = value2;
				q.push({ iii,jjj,value2 });
			}
		}
	}
}

int main()
{

	cin >> n >> m;
	vector<vector<int>> arr(n, vector<int>(m));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			int temp;
			cin >> temp;
			if (temp == 1)
				arr[i][j] = -1;
			else arr[i][j] = 9999;
		}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			if (arr[i][j] == -1)
				f(arr, i, j);
		}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			ans = max(ans, arr[i][j]);
		}
	cout << ans;
}

