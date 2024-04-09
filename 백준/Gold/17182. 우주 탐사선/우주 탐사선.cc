#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
#include<string>
using namespace std;

int n, k;
vector<vector<int>> arr;
vector<vector<int>> floyd;
vector<bool> visit;
int ans = 10000;
void floyd_f()
{
	for(int k=0;k<n;k++)
		for(int i=0;i<n;i++)
			for (int j = 0; j < n; j++)
			{
				floyd[i][j] = min(floyd[i][j], arr[i][k] + arr[k][j]);
			}
}
void f(int floor,int current_visit,int sum)
{
	if (floor == n)
	{
		ans = min(ans, sum);
		return;
	}
	visit[current_visit] = true;
	for (int i = 0; i < n; i++)
	{
		if (!visit[i])
		{
			f(floor + 1, i,floyd[current_visit][i]+sum);
			visit[i] = false;
		}
	}
}
int main()
{
	cin >> n >> k;
	arr.resize(n, vector<int>(n));
	floyd.resize(n, vector<int>(n,10000));
	visit.resize(n, false);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
			floyd[i][j] = arr[i][j];
		}
	floyd_f();
	f(1,k,0);
	cout << ans;
}