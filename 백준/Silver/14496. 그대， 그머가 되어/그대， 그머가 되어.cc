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
	int a, b,n,m;
	cin >> a >> b>>n>>m;
	vector<vector<int>> arr(n + 1);
	for (int i = 0; i < m; i++)
	{
		int s, e;
		cin >> s >> e;
		arr[s].push_back(e);
		arr[e].push_back(s);
	}
	vector<bool> visit(n + 1);
	int ans = -1;
	{
		queue<pair<int, int>> q;
		q.push({ a,0 });
		visit[a] = true;
		while(q.empty()==false)
		{
			auto now = q.front(); q.pop();
			if (now.first == b)
			{
				ans = now.second;
				break;
			}
			for (int i = 0; i < arr[now.first].size(); i++)
			{
				int next = arr[now.first][i];
				if (visit[next] == false)
				{
					visit[next] = true;
					q.push({ next,now.second + 1 });
				}
			}
		}
	}
	cout << ans;
}

