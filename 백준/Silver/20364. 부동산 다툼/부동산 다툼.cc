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

vector<bool> visited;
int temp2 = 0;
bool f(int pos)
{
	if (pos == 1)return true;
	if (f(pos / 2))
	{
		if(visited[pos]==false)
			return true;
		else
		{
			temp2 = pos;
			return false;
		}
	}
	else return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	int n, q;
	cin >> n >> q;
	visited.resize(n + 1, false);
	for (int i = 0; i < q; i++)
	{
		int temp;
		cin >> temp;
		bool can = f(temp);
		if (can)
		{
			cout << "0\n";
			visited[temp] = true;
		}
		else cout << temp2 << "\n";
	}
}