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

int main()
{
	const int maxValue = 34;
	string s;
	cin >> s;
	vector<int> v;
	v.push_back(0);
	for (int i = 0; i < s.size(); i++)
	{
		int temp = s[i]-'0';
		if (temp == 0)
		{
			int temp2 = v.back();
			v.pop_back();
			v.push_back(temp2 * 10 + temp);
		}
		else
		v.push_back(temp);
	}
	vector<int> dp(v.size() + 1, 0);
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 1;
	if (v.size() > 2)
	{
		for (int i = 2; i < v.size(); i++)
		{
			dp[i] = dp[i - 1];
			string s;
			s.append(to_string(v[i -1]));
			s.append(to_string(v[i]));
			if (stoi(s) <= maxValue)
			{
				dp[i] += dp[i - 2];
			}
		}
	}
	cout << dp[v.size()-1];
}