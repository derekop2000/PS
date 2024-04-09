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
bool ans = false;
int n;
vector<vector<int>> arr;
vector<vector<int>> visit;
vector<int> temps;
void dfs(int floor)
{
	if (floor == n + 1)
	{
		ans = true;
		return;
	}
	for (int i = 0; i < arr[floor].size(); i++)
	{
		int temp = arr[floor][i];
		if (temps.size()>0 && temp == temps[temps.size() - 1])continue;
		if (visit[floor][i])continue;
		visit[floor][i] = true;
		temps.push_back(temp);
		dfs(floor + 1);
		if(ans)return;
		temps.pop_back();
	}
}
int main()
{
	cin >> n;
	arr.resize(n+1);
	visit.resize(n + 1);
	for (int i = 1; i <= n; i++)
	{
		int _size;
		cin >> _size;
		arr[i].resize(_size);
		visit[i].resize(_size,false);
		for (int j = 0; j < _size; j++)
		{
			int temp;
			cin >> temp;
			arr[i][j] = temp;
		}
	}
	dfs(1);
	if (ans)
	{
		for (int i = 0; i < temps.size(); i++)
		{
			cout << temps[i] << "\n";
		}
	}
	else cout << "-1";
}
