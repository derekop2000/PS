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
	int n;
	cin >> n;
	vector<string> v(n);
	set<string> set;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	int index = 0;
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		set.insert(str);
		if(index < n)
		{ 
			if (v[index] == str)
			{
				index++;
				while (index < n && set.find(v[index]) != set.end())
				{
					index++;
				}
			}
			else
			{
				cnt++;
			}
		}
		
	}
	cout << cnt;
}

