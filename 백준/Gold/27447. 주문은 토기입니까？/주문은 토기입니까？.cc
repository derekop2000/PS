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
	queue<int> q;
	queue<int> q2;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		q.push(temp);
	}
	int cnt = 0;
	int time = 0;
	bool ans = true;
	while (true)
	{
		if (q.empty())
			break;
		if (q.front() == time && q2.empty())
		{
			ans = false;
			break;
		}
		if (q2.empty() == false && q2.front() == time)
		{
			q2.pop();
			time++;
			continue;
		}
		if (q.front() - m <= time && cnt)
		{
			q2.push(q.front());
			q.pop();
			cnt--;
			time++;
			continue;
		}
		time++;
		cnt++;
	}
	if (ans)
		cout << "success\n";
	else cout << "fail\n";
}

