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

using namespace std;
vector<vector<int>> v;
vector<int> parent;
void f(int now)
{
	for (int i = 0; i < v[now].size(); i++)
	{
		int next = v[now][i];
		if (parent[next] == -1)
		{
			parent[next] = now;
			f(next);
		}
	}
}
int main()
{
	int n;
	cin >> n;
	parent.resize(n + 1,-1);
	v.resize(n + 1);
	parent[1] = 0;
	for (int i = 0; i < n - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	f(1);
	for (int i = 2; i <= n; i++)
		cout << parent[i] << "\n";
}


