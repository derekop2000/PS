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
using namespace std;

vector<vector<int>> arr;
vector<bool> visit;
int ans = 0;
int temp_ans = 0;
void f(int n)
{
	if (n == 11)
	{
		ans = max(temp_ans, ans);
		return;
	}
	for (int i = 0; i < 11; i++)
	{
		if (visit[i] == false && arr[n][i]!=0)
		{
			visit[i] = true;
			temp_ans += arr[n][i];
			f(n + 1);
			temp_ans -= arr[n][i];
			visit[i] = false;
		}
	}
}
void init()
{
	arr.resize(11, vector<int>(11));
	for (int i = 0; i < 11; i++)
		for (int j = 0; j < 11; j++)
			cin >> arr[i][j];
	f(0);
	cout << ans<<"\n";
	ans = 0;
}
int main()
{
	int n;
	cin >> n;
	visit.resize(11, false);
	for (int i = 0; i < n; i++)
		init();
}
