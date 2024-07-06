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
			char c;
			cin >> c;// . = 0    //  x = 1 // # = 2
			int ii;
			if (c == '.')
				ii = 0;
			else if (c == 'X')
				ii = 1;
			else ii = 2;
			arr[i][j]=ii;
		}
	int cnt = n;
	for (int i = 0; i < m; i++)
	{
		int level = n - 1;
		int ground = n-1;
		while (true)
		{
			if (level < 0)
				break;
			if (arr[level][i] == 2)
				ground = level;
			if (arr[level][i] == 1)
			{
				cnt = min(ground - level, cnt);
			}
			level--;
		}
	}
	cnt--;
	for(int i=n-1;i>=0;i--)
		for (int j = 0; j < m; j++)
		{
			if (arr[i][j] == 1)
			{
				arr[i + cnt][j] = 1;
				arr[i][j] = 0;
			}
		}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (arr[i][j] == 0)
				cout << ".";
			else if (arr[i][j] == 1)
				cout << "X";
			else cout << "#";
		}
		cout << "\n";
	}
}



