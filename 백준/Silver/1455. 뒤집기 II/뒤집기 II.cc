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
	vector<vector<bool>> arr(n, vector<bool>(m));
	for(int i=0;i<n;i++)
		for (int j = 0; j < m; j++)
		{
			char temp;
			cin >> temp;
			if (temp == '0')
				arr[i][j] = true;
		}
	int cnt = 0;
	for (int i = n - 1; i >= 0;i--)
	{
		for (int j = m - 1; j >= 0; j--)
		{
			if (arr[i][j] == false)
			{
				cnt++;
				for (int ii = 0; ii <= i; ii++)
				{
					for (int jj = 0; jj <= j ; jj++)
					{
						arr[ii][jj] = !arr[ii][jj];
					}
				}
			}
		}
	}
	cout << cnt;
}

