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
	vector<long long int> v(10);
	vector<bool> can(10, true);
	vector<string> strs;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		can[s[0]-'A'] = false;
		strs.push_back(s);
		long long int value = 1;
		for (int j = s.size() - 1; j >= 0; j--)
		{
			int index = s[j] - 'A';
			v[index] += value;
			value *= 10;
		}
	}
	vector<pair<long long int,int>> v2;
	for (int i = 0;i<10;i++)
	{
		v2.push_back({ v[i],i });
	}
	sort(v2.begin(), v2.end());
	int zero=0;
	for (int i = 0; i < 10; i++)
	{
		if (can[v2[i].second])
		{
			zero = v2[i].second;
			break;
		}
		
	}
	int num = 1;
	for (int i = 0; i < 10; i++)
	{
		if (v2[i].second == zero)
			v[v2[i].second] = 0;
		else
			v[v2[i].second] = num++;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < strs[i].size(); j++)
		{
			strs[i][j] = v[strs[i][j] - 'A']+'0';
		}
	}
	long long int ans = 0;
	for (int i = 0; i < n; i++)
	{
		ans += stoll(strs[i]);
	}
	cout << ans;
}

