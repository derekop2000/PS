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



int main()
{
	int a, b;
	cin >> a >> b;
	vector<vector<char>> arr(a, vector<char>(b));
	for(int i=0;i<a;i++)
		for (int j = 0; j < b; j++)
		{
			cin >> arr[i][j];
		}
	queue<vector<int>> q;
	vector<int> temp;
	for (int i = 0; i < b; i++)
	{
		temp.push_back(i);
	}
	q.push(temp);
	int cnt = a;
	int level = a - 1;
	while (q.empty() == false)
	{
		cnt--;
		int teams = q.size();
		for (int i = 0; i < teams; i++)
		{
			temp = q.front(); q.pop();
			vector<vector<int>> chars(26);
			for (int j = 0; j < temp.size(); j++)
			{
				int pos = arr[level][temp[j]]-'a';
				chars[pos].push_back(temp[j]);
			}
			for (int j = 0; j < 26; j++)
			{
				if (chars[j].size() > 1)
					q.push(chars[j]);
			}
		}
		level--;
	}
	cout << cnt;
}