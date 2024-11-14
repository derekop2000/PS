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
	int n;
	cin >> n;
	vector<vector<int>> arr(n, vector<int>(6));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 6; j++)
			cin >> arr[i][j];
	map<int, int> friends;
	friends[0] = 5;
	friends[1] = 3;
	friends[2] = 4;
	friends[3] = 1;
	friends[4] = 2;
	friends[5] = 0;
	int ans = 0;
	for (int i = 0; i < 6; i++)
	{
		int pos = i;
		int sum = 0;
		for (int j = 0; j < n; j++)
		{
			bool six = false;
			bool five = false;
			int under = arr[j][pos];
			pos = friends[pos];
			int top = arr[j][pos];
			if (under == 6)
				six = true;
			if (under == 5)
				five = true;
			if (top == 6)
				six = true;
			if (top == 5)
				five = true;
			if (j != n - 1)
			{
				for (int q = 0; q < 6; q++)
				{
					if (arr[j + 1][q] == top)
					{
						pos = q;
						break;
					}
				}
			}
			int temp = 6;
			if (six)
			{
				temp = 5;
				if (five)
					temp = 4;
			}
			sum += temp;

		}
		ans = max(ans, sum);
	}
	cout << ans;
	
}
