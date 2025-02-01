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
#include<stack>
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
vector<vector<bool>> air;
vector<vector<int>> arr;
void DfsAir(int a, int b)
{
	if (air[a][b] == true)
		return;
	if (arr[a][b] == 0)
	{
		air[a][b] = true;
		for (int i = 0; i < 4; i++)
		{
			int aa = a + dir[i][0];
			int bb = b + dir[i][1];
			if(0<=aa&&aa<n&&0<=bb&&bb<m)
				DfsAir(aa, bb);
		}
	}
}
queue<pair<int, int>> q;
bool CheckAir(int a, int b)
{
	int cnt = 0;
	for (int i = 0; i < 4; i++)
	{
		int aa = a + dir[i][0];
		int bb = b + dir[i][1];
		if (0 <= aa && aa < n && 0 <= bb && bb < m && air[aa][bb])
		{
			cnt++;
		}
	}
	if (cnt >= 2)
		return true;
	else return false;
}
void UpdateAir(int a,int b)
{
	arr[a][b] = 0;
	air[a][b] = true;

	for (int i = 0; i < 4; i++)
	{
		int aa = a + dir[i][0];
		int bb = b + dir[i][1];
		if (0 <= aa && aa < n && 0 <= bb && bb < m)
		{
			if (arr[aa][bb] == 0 && air[aa][bb] == false)
			{
				DfsAir(aa, bb);
			}
		}
	}
}
int cheeseCnt = 0;
int main()
{
	cin >> n >> m;
	air.resize(n, vector<bool>(m, false));
	arr.resize(n, vector<int>(m));
	for(int i=0;i<n;i++)
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 1)
				cheeseCnt ++;
		}
	for (int i = 0; i < n; i++)
	{
		DfsAir(i, 0);
		DfsAir(i, m-1);
	}
	for (int i = 0; i < m; i++)
	{
		DfsAir(0, i);
		DfsAir(n-1, i);
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			if (arr[i][j] == 1)
			{
				if (CheckAir(i, j))
					q.push(pair<int, int>(i,j));
			}
		}
	int time = 0;
	while (cheeseCnt)
	{
		time++;
		int qSize = q.size();
		for (int i = 0; i < qSize; i++)
		{
			auto now = q.front(); q.pop();
			UpdateAir(now.first, now.second);
			cheeseCnt--;
		}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
			{
				if (arr[i][j] == 1)
				{
					if (CheckAir(i, j))
						q.push(pair<int, int>(i, j));
				}
			}
	}
	cout << time;
}