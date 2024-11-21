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
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		int n;
		cin >> n;
		parent.resize(n);
		for (int j = 0; j < n; j++)
			parent[j] = j;
		int m;
		cin >> m;
		for (int j = 0; j < m; j++)
		{
			int a, b;
			cin >> a >> b;
			Union(a, b);
		}
		int q;
		cin >> q;
		cout << "Scenario " << i << ":\n";
		for (int j = 0; j < q; j++)
		{
			int a, b;
			cin >> a >> b;
			if (IsUnion(a, b))
				cout << "1\n";
			else cout << "0\n";
		}
		cout << "\n";
	}
}
