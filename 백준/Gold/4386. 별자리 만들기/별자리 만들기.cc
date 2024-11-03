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
#include <cmath>
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

struct Pos
{
	float x;
	float y;
};
float GetDistance(Pos a,Pos b)
{
	return sqrt(abs(a.x - b.x) * abs(a.x - b.x) + abs(a.y - b.y) * abs(a.y - b.y));
}
int main()
{
	int n;
	cin >> n;
	vector<Pos> arr(n);
	parent.resize(n);
	priority_queue<tuple<float, int, int>, vector<tuple<float, int, int>>, greater<tuple<float, int, int>>> q;
	for (int i = 0; i < n; i++)
	{
		parent[i] = i;
		float a, b;
		cin >> a >> b;
		arr[i].x = a;
		arr[i].y = b;
	}
	for(int i=0;i<n;i++)
		for (int j = i + 1; j < n; j++)
		{
			q.push({ GetDistance(arr[i],arr[j]),i,j });
		}
	float ans = 0;
	while (q.empty()==false)
	{
		auto current = q.top(); q.pop();
		float value = get<0>(current);
		int a = get<1>(current);
		int b = get<2>(current);
		if (IsUnion(a, b))
			continue;
		else
		{
			Union(a, b);
			ans += value;
		}
	}
	cout <<fixed<<setprecision(3);
	cout << ans;
}
