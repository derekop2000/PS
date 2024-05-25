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

vector<bool> visited;
int temp2 = 0;
bool f(int pos)
{
	if (pos == 1)return true;
	if (f(pos / 2))
	{
		if(visited[pos]==false)
			return true;
		else
		{
			temp2 = pos;
			return false;
		}
	}
	else return false;
}
int main()
{
	int n;
	cin >> n;
	priority_queue<int, vector<int>, greater<int>> q;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		q.push(temp);
	}
	int max = 0;
	bool ans= false;
	while (q.empty() == false)
	{
		int value = q.top();
		q.pop();
		int s = max + 1;
		int e = max + value;
		for (int i = s; i <= e; i++)
		{
			int temp = i - value;
			if (0 <= temp && temp <= max)
				continue;
			else
			{
				max = i-1;
				ans = true;
				break;
			}
		}
		if (ans)
			break;
		max = e;
	}
	cout << max+1;

}