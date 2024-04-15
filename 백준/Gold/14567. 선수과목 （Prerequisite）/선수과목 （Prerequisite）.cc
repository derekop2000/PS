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
using namespace std;

vector<int> RefCount;
void f(pair<int, int>& now, queue<pair<int, int>>& q, vector<vector<int>>arr)
{
	for (int i = 0; i < arr[now.first].size(); i++)
	{
		int next = arr[now.first][i];
		RefCount[next]--;
		if(RefCount[next]==0)
			q.push({ next,now.second+1});
	}
}
int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> arr(n);
	vector<int> able(n,1);
	RefCount.resize(n, 0);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		a--; b--;
		arr[a].push_back(b);
		able[b] = n;
		RefCount[b]++;
	}
	int cnt = n;
	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++)
		if (able[i]==1)
			q.push({ i,1 });
	int now = 1;
	while(cnt)
	{
		while (q.empty() == false && q.front().second == now)
		{
			auto temp = q.front();
			able[temp.first] = temp.second;
			q.pop();
			cnt--;
			f(temp,q,arr);
		}
		now++;
	}
	for (int i = 0; i < n; i++)
	{
		cout << able[i] << " ";
	}
}