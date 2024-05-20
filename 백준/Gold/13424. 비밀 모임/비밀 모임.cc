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

vector<vector<int>> arr;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		arr.clear();
		arr.resize(n, vector<int>(n,10000000));
		for (int i = 0; i < m; i++)
		{
			int a, b, c;
			cin >> a >> b >> c;
			a--; b--;
			arr[a][b] = c;
			arr[b][a] = c;
		}
		for(int k=0;k<n;k++)
			for(int i=0;i<n;i++)
				for (int j = 0; j < n; j++)
				{
					if (i == j)
						continue;
					arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
				}
		int ans = 10000000;
		int ansRoom = 10000;
		int temp;
		int cnt;
		cin >> cnt;
		vector<int> who;
		for (int i = 0; i < cnt; i++)
		{
			int temp;
			cin >> temp;
			who.push_back(temp-1);
		}
		for (int i = 0; i < n; i++)
		{
			temp = 0;
			for (int j = 0; j < cnt; j++)
			{
				if (i == who[j])continue;
				temp += arr[who[j]][i];
			}
			if (temp < ans)
			{
				ans = temp;
				ansRoom = i;
			}
		}
		cout << ansRoom+1 << "\n";
	}
}