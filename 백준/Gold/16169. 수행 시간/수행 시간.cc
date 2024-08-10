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

int main()
{
	int n;
	cin >> n;
	vector<vector<vector<int>>> arr(n+1);
	int endPoint = 0;
	for (int i = 1; i <= n; i++)
	{
		int a, b;
		cin >> a >> b;
		a--;
		endPoint = max(endPoint, a);
		arr[a].push_back({ i,b,0}); // 번호, 작업속도, 시작시간
	}
	for (int i = 1; i <= endPoint; i++)
	{
		for (int q = 0; q < (int)arr[i].size(); q++)
		{
			for (int j = 0; j < (int)arr[i - 1].size(); j++)
			{
				auto v = arr[i - 1][j];
				arr[i][q][2] = max(arr[i][q][2], (int)pow(abs(arr[i][q][0] - arr[i - 1][j][0]), 2) + arr[i - 1][j][1]+arr[i-1][j][2]);

			}
		}
	}
	int ans = 0;
	for (int i = 0; i < (int)arr[endPoint].size(); i++)
	{
		ans = max(ans, arr[endPoint][i][1] + arr[endPoint][i][2]);
	}
	cout << ans;
}

