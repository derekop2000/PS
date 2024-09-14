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
vector<bool> visit;
void f(int now,bool first)
{
	if (first)
	{
		Union(0, now);
	}
	visit[now] = true;
	for (int i = 0; i < arr[now].size(); i++)
	{
		int next = arr[now][i];
		if (visit[next])
			continue;
		if (findParent(now) == 0)
		{
			f(next,false);
		}
		else
		{
			Union(0, next);
			f(next,false);
		}
	}
}


int main()
{
	int n, k;
	cin >> n >> k;
	vector<int> arr;
	vector<int> arr2;
	for (int i = 1; i <= n; i++)
	{
		char c;
		cin >> c;
		if (c == 'H')
			arr.push_back(i);
		else arr2.push_back(i);
	}
	int cnt = 0;
	int index = 0;
	for (int pos : arr)
	{
		if (index == arr2.size())
			break;
		while (true)
		{

			if (abs(pos - arr2[index]) <= k)
			{
				cnt++;
				index++;
				break;
			}
			else
			{
				if (pos < arr2[index])
					break;
				else
				{
					index++;
				}
			}
		}
	}
	cout << cnt;
}

