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

bool Temp(const tuple<int, int, int>& a, const tuple<int, int, int>& b)
{
	return get<1>(a) < get<1>(b);
}
int main()
{
	int n, m;
	cin >> n >> m;
	vector<tuple<int, int, int>> arr(m);
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		arr[i] = tuple<int, int, int>{ a,b,c };
	}
	sort(arr.begin(), arr.end(),Temp);
	pair<int, int> level = pair<int, int>{ 0,0 };
	bool ans = true;
	for (int i = 0; i < m; i++)
	{
		auto Tdata = arr[i];
		int a = get<0>(Tdata);
		int b = get<1>(Tdata);
		int c = get<2>(Tdata);
		if (a == 0)
		{
			level.second -= b - level.first;
			level.first = b;
			if (level.second <= c)
				level.second = c + 1;
		}
		else
		{
			level.second -= b - level.first;
			level.first = b;
			if (level.second >= c)
			{
				ans = false;
				break;
			}
		}
	}
	{
		level.second -= (n - 1) - level.first;
		level.first = n - 1;

		if (level.second > 1)
			ans = false;
	}
	if (ans)
		cout << "stay";
	else cout << "adios";
}