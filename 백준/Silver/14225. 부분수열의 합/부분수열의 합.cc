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

vector<vector<int>> arr;
string ans = "";
void f(int r, int c, int n)
{
	int temp = arr[r][c];
	bool pass = true;
	for (int i = r; i < r + n; i++)
	{
		for (int j = c; j < c + n; j++)
		{
			if (arr[i][j] != temp)
			{
				pass = false;
			}
		}
	}
	if (pass)
	{
		ans.push_back(temp+'0');
	}
	else
	{
		ans.push_back('(');
		int range = n / 2;
		f(r, c, range);
		f(r, c+range, range);
		f(r+ range, c, range);
		f(r+ range, c+ range, range);
		ans.push_back(')');
	}
}
int main()
{
	int n;
	cin >> n;
	vector<int> can(100000 * 20 + 1);
	can[0] = true;
	for (int i = 0; i < n; i++)
	{
		int value;
		cin >> value;
		for (int j = can.size(); j >= value; j--)
		{
			if (can[j - value])
				can[j] = true;
		}
	}
	int ans = 100000 * 20 + 1;
	for (int i = 0; i <= 100000 * 20 ; i++)
	{
		if (can[i] == false)
		{
			ans = i;
			break;
		}
	}
	cout << ans;
}

