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
	int n;
	cin >> n;
	vector<vector<int>> arr(n, vector<int>(n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];

	queue<tuple<int, int,int,int>> q;
	vector<int> ans(2*n-1);
	q.push({ 0,0,0,0}); // y,x,index,pre_value
	while (q.empty()==false)
	{
		auto now = q.front(); q.pop();
		int y = get<0>(now);
		int x = get<1>(now);
		int index = get<2>(now);
		int preValue = get<3>(now);
		if (index>0 &&preValue < ans[index - 1])
			continue;
		if (arr[y][x] < ans[index])
			continue;
		if (arr[y][x] == 1)
			ans[index] = 1;
		//
		{
			int yy = y + 1;
			int xx = x;
			if (0 <= yy && yy < n && 0 <= xx && xx < n)
			{
				int index2 = index + 1;
				int value = arr[yy][xx];
				q.push({ yy,xx,index + 1,arr[y][x] });
			}
		}
		//
		{
			int yy = y;
			int xx = x+1;
			if (0 <= yy && yy < n && 0 <= xx && xx < n)
			{
				int index2 = index + 1;
				int value = arr[yy][xx];
				q.push({ yy,xx,index + 1,arr[y][x] });
			}
		}
	}
	int sum = 0;
	int v = 1;
	for (int i = ans.size()-1; i >= 0; i--)
	{
		if (ans[i])
			sum += v;
		v *= 2;
	}
	cout << sum;
}

