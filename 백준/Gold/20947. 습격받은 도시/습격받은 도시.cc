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

int main()
{
	// 0 - . 빈 // 1 - X 잔해 // 2 - O 건물 // 3 - B폭탄
	int n;
	cin >> n;
	vector<vector<int>> v(n, vector<int>(n));
	queue<pair<int, int>> house;
	for(int i=0;i<n;i++)
		for (int j = 0; j < n; j++)
		{
			char c;
			cin >> c;
			switch (c)
			{
			case '.':
				v[i][j] = 3;
				break;
			case 'X':
				v[i][j] = 1;
				break;
			case 'O':
				v[i][j] = 2;
				house.push({ i,j });
				break;
			}
		}
	while (house.empty()==false)
	{
		auto current = house.front(); house.pop();
		for (int i = 0; i < 4; i++)
		{
			int r = current.first+dir[i][0];
			int c = current.second+dir[i][1];
			while ((0 <= r && r < n && 0 <= c && c < n))
			{
				if (v[r][c] == 1 || v[r][c] == 2)break;
				v[r][c] = 0;
				r +=dir[i][0];
				c +=dir[i][1];
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (v[i][j] == 0)
			{
				cout << ".";
			}
			else if (v[i][j] == 1)
			{
				cout << "X";
			}
			else if (v[i][j] == 2)
			{
				cout << "O";
			}
			else
			{
				cout << "B";
			}
		}
		cout << "\n";
	}
}