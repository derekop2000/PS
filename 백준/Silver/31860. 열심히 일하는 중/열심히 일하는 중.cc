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
	int n, m, k;
	cin >> n >> m >> k;
	priority_queue<int> q;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		if(temp >= k)
			q.push(temp);
	}
	int point = 0;
	vector<int> points;
	while (q.empty() == false)
	{
		int now = q.top(); q.pop();
		int newPoint = point / 2 + now;
		point = newPoint;
		points.push_back(newPoint);
		now -= m;
		if (now > k)
			q.push(now);
	}
	cout << points.size() << "\n";
	for (auto a : points)
	{
		cout << a << "\n";
	}
}



