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

int n;
vector<int> a;
vector<int> b;
vector<int> c;
int main()
{
	int t;
	cin >> t;
	vector<int>  dp(100'001, 0);
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 2;
	for (int i = 4; i <= 100'000; i++)
	{
		int temp = i;
		for (int j = 0; j < 3; j++)
		{
			temp -= 2;
			if (temp >= 0)
			{
				dp[i] += dp[temp];
				dp[i] %= 1'000'000'009;
			}
			else break;
		}
	}
	for (int i = 0; i < t; i++)
	{
		int n;
		cin >> n;
		cout << dp[n] << "\n";
	}
}