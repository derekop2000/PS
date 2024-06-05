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
	int index = 0;
	int n;
	cin >> n;
	deque<pair<int,int>> q;
	for (int i = 1; i <= n; i++)
	{
		int temp;
		cin >> temp;
		q.push_back({ i,temp });
	}
	while (q.empty() == false)
	{
		int who = q.front().first;
		int moveCnt = q.front().second;
		q.pop_front();
		cout << who << " ";
		if (q.empty())
			break;
		if (moveCnt > 0)
		{
			moveCnt--;
			while (moveCnt)
			{
				q.push_back(q.front());
				q.pop_front();
				moveCnt--;
			}
		}
		else
		{
			moveCnt *= -1;
			while (moveCnt)
			{
				q.push_front(q.back());
				q.pop_back();
				moveCnt--;
			}
		}
	}
}