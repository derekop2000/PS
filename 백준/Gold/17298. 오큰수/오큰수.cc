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
	vector<pair<int, int>> s;
	vector<int> ans(n);
	for (int i = 0; i < n; i++)
	{
		int value;
		cin >> value;
		while (s.empty() == false && s.back().first < value)
		{
			ans[s.back().second] = value;
			s.pop_back();
		}
		s.push_back({ value,i });
	}
	while (s.empty()==false)
	{
		ans[s.back().second] = -1;
		s.pop_back();
	}
	for (auto a : ans)
	{
		cout << a << " ";
	}
}
