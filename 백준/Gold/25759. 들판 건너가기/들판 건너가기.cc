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
#include<stack>
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

#include<limits>
void f(int s, int e, int num)
{
	if (num == 1)
	{
		cout << s << " " << e << "\n";
	}
	else
	{
		int another = (6 - s - e);
		f(s, another, num - 1);
		cout << s << " " << e << "\n";
		f(another, e, num - 1);
	}
}
vector<int> ans(100, 0);
int ansSize = 1;
void mul()
{
	int index = 0;
	bool carry = false;
	for (; index < ansSize; index++)
	{
		int temp = ans[index] * 2;
		ans[index] = temp % 10;
		if (carry)
			ans[index]++;
		carry = false;
		if (temp > 9)
			carry = true;
	}
	if (carry)
	{
		ansSize++;
		ans[index]++;
	}
}
void add()
{
	int index = 0;
	while (true)
	{
		ans[index]++;
		if (ans[index] == 10)
		{
			ans[index] = 0;
			index++;
		}
		else break;
	}
}

int main()
{
	int n;
	cin >> n;
	int dp[101];
	for (int i = 0; i <= 100; i++)
		dp[i] = -1;
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		if (i == 0)
		{
			dp[temp] = 0;
		}
		else
		{
			for (int i = 1; i <= 100; i++)
			{
				if (dp[i] > -1)
				{
					dp[temp] = max(dp[temp], dp[i] + (abs(temp - i) * abs(temp - i)));
					ans = max(ans, dp[temp]);
				}
			}
		}
	}
	cout << ans;
}