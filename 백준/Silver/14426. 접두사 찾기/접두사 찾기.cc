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


vector<vector<int>> arr;
vector<vector<int>> arr2;
vector<int> points;

void f(int node)
{
	for (int i = 0; i < arr[node].size(); i++)
	{
		int next = arr[node][i];
		if (points[next] > points[node])
			continue;
		points[next] = points[node]+1;
		f(next);
	}
	for (int i = 0; i < arr2[node].size(); i++)
	{
		int back = arr2[node][i];
		if (points[back] < points[node])
			continue;
		points[back] = points[node] - 1;
		f(back);
	}
}

unordered_set<string> s;
int main()
{
	int n, m;
	cin >> n >> m;
	cin.ignore(LLONG_MAX, '\n');
	for (int i = 0; i < n; i++)
	{
		string s;
		getline(cin, s,'\n');
		string s2 = "";
		for (int j = 0; j < s.size(); j++)
		{
			s2.push_back(s[j]);
			::s.insert(s2);
		}
	}
	int cnt = 0;
	for (int i = 0;i < m; i++)
	{
		string s;
		getline(cin, s);
		if (::s.find(s) != ::s.end())
			cnt++;
	}
	cout << cnt;
}

