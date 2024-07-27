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

int main()
{
	int n, m;
	cin >> n >> m;
	priority_queue<int> q;
	priority_queue<int,vector<int>,greater<int>> q2;

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		q.push(temp);
		q2.push(temp);
	}
	long long int ans = 0;
	ans += q.top(); q.pop();
	int turn = 1;
	int last = ans;
	for (int i = 0; i < m-1; i++)
	{
		if (turn)
		{
			last = q2.top(); q2.pop();
			turn = 0;
		}
		else
		{
			ans += (q.top() - last); q.pop();
			turn = 1;
		}
	}
	cout << ans;
}

