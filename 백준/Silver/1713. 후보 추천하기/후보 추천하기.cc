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

int dir[][2] = { {-1,0}, {0,1}, {1,0} ,{0,-1} };

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
	int photo;
	cin >> photo;
	int n;
	cin >> n;
	int cnt = 0;
	pair<int, int> reset = { 0,0 };
	vector<pair<int, int>> v(101, reset);
	v[0] = { 0,1000 };
	static int order = 1;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		if (cnt < photo)
		{
			pair<int, int> p = v[temp];
			if (p.first == 0)
			{
				p.first = order++;
				p.second = 1;
				cnt++;
			}
			else
			{
				p.second++;
			}
			v[temp] = p;
		}
		else
		{
			if (v[temp].first != 0)
			{
				v[temp].second++;
			}
			else
			{
				int index = 0;
				for (int i = 1; i <= 100; i++)
				{
					if (v[i].first == 0)continue;
					if (v[i].second < v[index].second)
						index = i;
					else if (v[i].second == v[index].second)
						index = v[i].first < v[index].first ? i : index;
				}
				v[temp] = { order++,1 };
				v[index] = reset;
			}
		}
	}
	vector<int> s;
	for (int i = 1; i <= 100; i++)
	{
		if (v[i].first > 0)
		{
			s.push_back(i);
		}
	}
	sort(s.begin(), s.end());
	for (int i = 0; i < s.size(); i++)
	{
		cout << s[i] << " ";
	}
}

