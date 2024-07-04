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
	int n, m;
	cin >> n >> m;
	vector<int> army;
	for (int i = 0; i <n;i++)
	{
		int temp;
		cin >> temp;
		army.push_back(temp);
		parent.push_back(i);
	}
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		b--; c--;
		if (a == 1)
		{
			int bb = findParent(b);
			int cc = findParent(c);
			int temp = army[bb] + army[cc];
			Union(b, c);
			army[bb] = 0;
			army[cc] = 0;
			army[findParent(bb)] = temp;

		}
		else
		{
			int bb = findParent(b);
			int cc = findParent(c);
			if (army[bb] == army[cc])
			{
				army[bb] = 0;
				army[cc] = 0;
			}
			else if(army[bb] > army[cc])
			{
				int temp = army[bb] - army[cc];
				army[bb] = 0;
				army[cc] = 0;
				Union(bb, cc);
				army[findParent(bb)] = temp;
			}
			else
			{
				int temp = army[cc] - army[bb];
				army[bb] = 0;
				army[cc] = 0;
				Union(bb, cc);
				army[findParent(bb)] = temp;
			}
		}
	}
	vector<int> v;
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		if (army[i])
		{
			cnt++;
			v.push_back(army[i]);
		}
	}
	sort(v.begin(), v.end());
	cout << cnt << "\n";
	for (auto now : v)
	{
		cout << now << " ";
	}
}

