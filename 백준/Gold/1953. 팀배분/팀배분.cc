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
	int n;
	cin >> n;
	arr.resize(n);
	visit.resize(n);
	parent.resize(n);
	for (int i = 0; i < n; i++)
	{
		parent[i] = i;
		int t;
		cin >> t;
		for (int j = 0; j < t; j++)
		{
			int temp;
			cin >> temp;
			arr[i].push_back(temp-1);
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (visit[i] == false)
		{
			f(i,true);
		}
	}
	vector<int> v1;
	vector<int> v2;
	for (int i = 0; i < n; i++)
	{
		if (findParent(i) == 0)
		{
			v1.push_back(i);
		}
		else v2.push_back(i);
	}
	cout << v1.size()<<"\n";
	for (auto temp : v1)
	{
		cout << temp+1 << " ";
	}
	cout << "\n" << v2.size() << "\n";
	for (auto temp : v2)
	{
		cout << temp+1 << " ";
	}
}

