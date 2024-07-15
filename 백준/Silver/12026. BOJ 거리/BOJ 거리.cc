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


int v, e;
bool ans = false;
vector<map<int,bool>> arr;
int cnt = 0;
void f(int now,int cnt)
{
	if (cnt == e)
	{
		ans = true;
		return;
	}
	for (auto& current : arr[now])
	{
		if (current.second == false)
			continue;
		current.second = false;
		arr[current.first][now] = false;
		f(current.first,cnt+1);
	}
}
int main()
{
	int n;
	cin >> n;
	vector<char> v;
	for (int i = 0; i < n; i++)
	{
		char c;
		cin >> c;
		v.push_back(c);
	}
	vector<int> dp(n,-1);
	dp[0] = 0;
	for (int i = 0; i < n; i++)
	{
		int outNum = 0;
		if (v[i] == 'O')
			outNum = 1;
		if (v[i] == 'J')
			outNum = 2;
		int checkNum = (outNum + 2) % 3;
		for (int j = 0; j < i; j++)
		{
			int inNum = 0;
			if (v[j] == 'O')
				inNum = 1;
			if (v[j] == 'J')
				inNum = 2;
			if (checkNum == inNum)
			{
				if (dp[j] == -1)continue;
				if (dp[i] == -1)
					dp[i] = dp[j] + (j - i) * (j - i);
				else dp[i] = min(dp[i], dp[j] + (j - i) * (j - i));
			}
		}
	}
	cout << dp[n - 1];
}

