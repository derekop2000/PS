#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
#include<string>
using namespace std;

int n;
vector<vector<int>> arr;
vector<bool> visit;
int ans = 0;
bool f(int k)
{
	bool me = false;
	bool leaf = true;
	visit[k] = true;
	for (int i = 0; i < arr[k].size(); i++)
	{
		if (visit[arr[k][i]] == false)
		{
			leaf = false;
			if (f(arr[k][i]) == false)me = true;
		}
	}
	if (leaf)return false;
	if (me)ans++;
	return me;
}
int main()
{
    ios_base::sync_with_stdio(false);

cin.tie(NULL);

cout.tie(NULL);
	cin >> n;
	arr.resize(n,vector<int>());
	visit.resize(n, false);
	for (int i = 0; i < n - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		a--; b--;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	visit[0] = true;
	f(0);
	cout << ans;
}
