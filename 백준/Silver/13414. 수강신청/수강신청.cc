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


int main()
{
	map<string, int> map;
	int n, m;
	int cnt = 0;
	cin >> n>>m;
	for (int i = 0; i < m; i++)
	{
		string str;
		cin >> str;
		map[str] = cnt++;
	}
	vector<pair<int, string>> v;
	for (auto it : map)
	{
		v.push_back({ it.second, it.first });
	}
	sort(v.begin(), v.end());
	int size = min(static_cast<int>(v.size()), n);
	for (int i = 0; i < size; i++)
		cout << v[i].second << "\n";
}



