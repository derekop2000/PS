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
	vector<bool> arr(40001,false);
	arr[0] = true;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		for (int j = 40000; j >= temp; j--)
		{
			if (arr[j - temp])
				arr[j] = true;
		}
	}
	int m;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		bool ok = false;
		int temp;
		cin >> temp;
		if (arr[temp])
			ok = true;
		else
		{
			for (int j = 40000; j >= temp; j--)
			{
				if (arr[j] && arr[j - temp])
				{
					ok = true;
					break;
				}
			}
		}

		if (ok)
		{
			cout << "Y ";
		}
		else
		{
			cout << "N ";
		}
	}
}
