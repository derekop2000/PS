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


int v, e;
bool ans = false;
vector<map<int,bool>> arr;
int cnt = 0;
void f(int now,int cnt)
{
	if (cnt == e)
	{
		ans = true;
		return;
	}
	for (auto& current : arr[now])
	{
		if (current.second == false)
			continue;
		current.second = false;
		arr[current.first][now] = false;
		f(current.first,cnt+1);
	}
}
int main()
{
	cin >> v >> e;
	arr.resize(v);
	for (int i = 0; i < e; i++)
	{
		int a, b;
		cin >> a >> b;
		a--; b--;
		arr[a][b] = true;
		arr[b][a] = true;
	}
	
	auto temp = arr;
	for (int i = 0; i < v; i++)
	{
		cnt = 0;
		arr = temp;
		f(i,0);
		if (ans)
		{
			break;
		}
	}
	if (ans)
		cout << "YES";
	else cout << "NO";
}

