#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
#include<string>
using namespace std;

int n, m;
vector<bool> visited;
vector<vector<int>> arr;
vector<int> partner;
bool f2(int now)
{
	if (visited[now])return false;
	visited[now] = true;
	for (int i = 0; i < arr[now].size(); i++)
	{
		if (partner[arr[now][i]] == -1 || f2(partner[arr[now][i]]))
		{
			partner[arr[now][i]] = now;
			return true;
		}
	}
	return false;
}
int f()
{
	int ans = 0;
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			visited[j] = false;
		if (f2(i))
			ans++;
	}
	return ans;
}
int main()
{
	cin >> n >> m;
	arr.resize(n);
	visited.resize(n);
	partner.resize(m, -1);
	for (int i = 0; i < n; i++)
	{
		int t;
		cin >> t;
		for (int j = 0; j < t; j++)
		{
			int temp;
			cin >> temp;
			arr[i].push_back(temp-1);
		}
	}
	cout << f();
}
