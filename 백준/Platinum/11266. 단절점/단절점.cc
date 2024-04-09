#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
#include<string>
#include<set>
#include<map>
#include<cmath>
#include <iomanip>
#include<climits>

using namespace std;

vector<int> population;
vector<vector<int>> arr;
int n;
vector<bool> isDan;
vector<int> dfsTree;
int cnt = 0;
int f(int now,bool isRoot)
{
	dfsTree[now] = cnt++;
	int num = dfsTree[now];
	int child = 0;
	for (int i = 0; i < arr[now].size(); i++)
	{
		int next = arr[now][i];
		if (dfsTree[next] == -1)
		{
			child++;
			int temp = f(next, false);
			num = min(temp, num);
			if (!isRoot && temp >= dfsTree[now])
				isDan[now] = true;
		}
		else
		{
			num = min(dfsTree[next],num);
		}
	}
	if (isRoot && child > 1)isDan[now] = true;
	return num;
}
int main()
{
	int m;
	cin >> n>>m;
	arr.resize(n);
	population.resize(n);
	isDan.resize(n);
	dfsTree.resize(n, -1);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		arr[a - 1].push_back(b - 1);
		arr[b - 1].push_back(a - 1);
	}
	/*for (int i = 0; i < n; i++)
		cin >> population[i];
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
	}*/
	f(0,true);
	for (int i = 0; i < n; i++)
	{
		if (dfsTree[i] == -1)
			f(i, true);
	}
	vector<int> temp;
	for (int i = 0; i < n; i++)
	{
		if (isDan[i])
			temp.push_back(i);
	}
	reverse(temp.begin(), temp.end());
	cout << temp.size() << "\n";
	while (!temp.empty())
	{
		cout << temp.back()+1 << " "; temp.pop_back();
	}
}