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
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<int> v;
	bool ans = false;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == 'R')
			v.push_back(0);
		else if (s[i] == 'G')
			v.push_back(1);
		else
			v.push_back(2);
	}
	int ccnt = INT_MAX;
	for (int i = 0; i < 3; i++)
	{
		int cnt = 0;
		vector<int> v2(n, i);
		for (int j = 0; j < n - 2; j++)
		{
			while(v[j] != v2[j])
			{
				cnt++;
				v2[j] = (v2[j] + 2) % 3;
				v2[j+1] = (v2[j+1] + 2) % 3;
				v2[j+2] = (v2[j+2] + 2) % 3;
			}
		}
		if (v2[n - 2] == v[n - 2] && v2[n - 1] == v[n - 1])
		{
			ccnt = min(ccnt, cnt);
			ans = true;
		}
	}
	if (ans)
		cout << ccnt;
	else cout << "-1";
}

