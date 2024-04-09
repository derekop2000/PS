#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
#include<memory.h>
#include<string>
using namespace std;

vector<vector<int>> v[2];
vector<bool> visit;
int n, m; 
int f2(int now,bool is_up)
{
	visit[now] = true;
	int num = 1;
	int temp = is_up ? 0 : 1;
	int temp2 = v[temp][now].size();
	for (int i = 0; i < temp2; i++)
	{
		int next = v[temp][now][i];
		if(visit[next]==false)
			num += f2(next, is_up);
	}
	return num;
}
int ans = 0;
void f()
{
	for (int i = 0; i < n; i++)
	{
		int cnt = 0;
		visit.clear();
		visit.resize(n, false);
		cnt += f2(i, true);
		cnt += f2(i, false);
		if (cnt == n + 1)
			ans++;
	}
}
int main()
{
	cin >> n >> m;
	v[0].resize(n);
	v[1].resize(n);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		a--; b--;
		v[0][a].push_back(b);
		v[1][b].push_back(a);
	}
	f();
	cout << ans;
}
  
