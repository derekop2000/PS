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

int main()
{
	int n;
	cin >> n;
	int ans = 0;
	vector<int> can(n, -1);
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		if (temp > 0)
		{
			ans += temp;
			can[i] = 0;
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (can[i] == 0)continue;
		int b = (i + n - 1) % n;
		int f = (i + 1) % n;
		if (can[b] == 1 || can[f] == 1)
			can[i] = 0;
		else
		{
			can[i] = 1;
			ans++;
		}
	}
	cout << ans;
}