#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
#include<memory.h>
#include<string>
using namespace std;

int v, e;
vector<vector<int>> arr;
vector<int> dfsOrder;
int dfsCnt = 0;
bool c_cnt = false;
int f(int now,int parent)
{
	dfsOrder[now] = dfsCnt++;
	int re = 0;
	int last = 0;
	for (int i = 0; i < arr[now].size(); i++)
	{
		int next = arr[now][i];
		if (next == parent)continue;
		if (dfsOrder[next] == -1)
		{
			re += f(next,now);
		}
		else if (dfsOrder[next] > dfsOrder[now])
		{
			last++;
		}
		else
		{
			re++;
		}
	}
	if (re > 1)
		c_cnt = true;
	re -= last;
	return re;
}
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
	cin >> v >> e;
	arr.resize(v);
	dfsOrder.resize(v,-1);
	for (int i = 0; i < e; i++)
	{
		int a, b;
		cin >> a >> b;
		a--; b--;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	f(0,-1);
	if (c_cnt)cout << "Not cactus";
	else cout << "Cactus";
}
  
