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
	vector<int> arr(n);
	priority_queue<pair<long long int,int>,vector<pair<long long int,int>>,greater<pair<long long int,int>>> q;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		q.push({ arr[i] ,i});
	}
	int cnt = 0;
	long long int ans = 0;
	while (true)
	{
		pair<long long int, int> now = q.top(); q.pop();
		cnt++;
		if (cnt == m)
		{
			ans = now.first;
			break;
		}
		q.push({ now.first + arr[now.second],now.second });
	}
	cout << ans;
}

