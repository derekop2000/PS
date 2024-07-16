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


int v, e;
bool ans = false;
vector<map<int,bool>> arr;
int cnt = 0;
void f(int now,int cnt)
{
	if (cnt == e)
	{
		ans = true;
		return;
	}
	for (auto& current : arr[now])
	{
		if (current.second == false)
			continue;
		current.second = false;
		arr[current.first][now] = false;
		f(current.first,cnt+1);
	}
}
int main()
{
	vector<long long int[3]> arr(100001);
	arr[1][0] = 1;
	arr[2][1] = 1;
	arr[3][0] = 1;
	arr[3][1] = 1;
	arr[3][2] = 1;
	for (int i = 4; i < 100001; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int q = 1; q <= 2; q++)
			{
				int num = (j + q) % 3;
				arr[i][j] += arr[i - j-1][num];
				arr[i][j] %= 1'000'000'009;
			}
		}
	}
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		cout << (arr[n][0] + arr[n][1] + arr[n][2]) % 1'000'000'009 << "\n";
	}
}

