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

int n;
string str;
int cnt = 0;
bool ans = false;
void mySTOI(string& str)
{
	for (int i = 0; i < str.size(); i++)
		cout << str[i];
}
void f(int total, int now, int last)
{
	if (total == now)
	{
		cnt++;
		if (cnt == n)
		{
			mySTOI(str);
			ans = true;
		}
		return;
	}
	for (int i = 0; i < last; i++)
	{
		str.push_back(i + '0');
		f(total, now + 1, i);
		if (ans)return;
		str.pop_back();
	}
}
void init()
{
	for (int i = 1; i <= 10; i++)
	{
		f(i, 0, 10);
	}
}



int main()
{
	cin >> n;
	init();
	if (ans == false)cout << "-1";
}