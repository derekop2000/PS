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
	vector<vector<int>> arr(n+1,vector<int>(n+1));
	for(int i=1;i<=n;i++)
		for (int j = 1; j <= n; j++)
		{
			int temp;
			cin >> temp;
			arr[i][j] = arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1] + temp;
		}
	int ans = -1000;
	for (int k = 0; k < n; k++)
	{
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
			{
				if (k + i > n || k + j > n)
					continue;
				ans = max(ans, arr[i + k][j + k] - arr[i+k][j -1] - arr[i-1][j+k] + arr[i - 1][j - 1]);
			}
	}
	cout << ans;
}
