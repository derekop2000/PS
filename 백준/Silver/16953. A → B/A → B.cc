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
	int a, b;
	cin >> a >> b;
	queue<pair<long long int,int>> q;
	q.push({a,1});
	int ans = -1;
	while (q.empty() == false)
	{
		auto now = q.front(); q.pop();
		if (now.first == b)
		{
			if (ans == -1)
				ans = now.second;
			else
				ans = min(ans, now.second);
		}
		long long int n1 = now.first * 2;
		long long int n2 = now.first * 10 + 1;
		if (n1 <= b )
		{
			q.push({ n1 ,now.second+1});
		}
		if (n2 <= b )
		{
			q.push({ n2 ,now.second+1});
		}
	}
	cout << ans;
}

