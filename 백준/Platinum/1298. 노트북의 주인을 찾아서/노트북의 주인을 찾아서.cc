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
using namespace std;

int n, m;
vector<vector<int>> arr;
vector<bool> visit;
vector<int> partner;
bool f2(int now)
{
	if (visit[now])
		return false;
	visit[now] = true;
	for (int i = 0; i < arr[now].size(); i++)
	{
		int notebook = arr[now][i];
		if (partner[notebook] == -1 || f2(partner[notebook]))
		{
			partner[notebook] = now;
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
		visit.clear();
		visit.resize(n, false);
		if (f2(i))
			ans++;
	}
	return ans;
}
int main()
{
	cin >> n >> m;
	arr.resize(n);
	partner.resize(n, -1);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		a--; b--;
		arr[a].push_back(b);
	}
	cout << f();
}