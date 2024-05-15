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
#include<cmath>
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
	int n, m;
	cin >> n >> m;
	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> q;
	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>> q2;
	for (int i = 0; i < m + 1; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		q.push({ c,a,b });
		q2.push({ c,a,b });
	}

	for (int i = 0; i <= n; i++)
	{
		parent.push_back(i);
	}
	int cnt = n;
	int ansCnt = 0;
	while (cnt)
	{
		auto now = q.top(); q.pop();
		int value = get<0>(now);
		int a = get<1>(now);
		int b = get<2>(now);
		if (IsUnion(a, b))continue;
		Union(a, b);
		cnt--;
		if (value == 0)
			ansCnt++;
	}
	//////////////////////////
	parent.clear();
	for (int i = 0; i <= n; i++)
	{
		parent.push_back(i);
	}
	int cnt2 = n;
	int ansCnt2 = 0;
	while (cnt2)
	{
		auto now = q2.top(); q2.pop();
		int value = get<0>(now);
		int a = get<1>(now);
		int b = get<2>(now);
		if (IsUnion(a, b))continue;
		Union(a, b);
		cnt2--;
		if (value == 0)
			ansCnt2++;
	}
	cout << abs(pow(ansCnt, 2)- pow(ansCnt2, 2));
}


