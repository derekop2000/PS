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

#define my_max 1000000

int main()
{
	int ans = my_max;
	int n;
	cin >> n;
	vector<vector<int>> colors;
	colors.resize(n + 1, vector<int>(3));
	for (int i = 1; i <= n; i++)
	{
		cin >> colors[i][0] >> colors[i][1] >> colors[i][2];
	}
	vector<int> arr[3];
	for (int i = 0; i < 3; i++)
		arr[i].resize(n+1);
	for (int k = 0; k < 3; k++)
	{
		for (int i = 0; i < 3; i++)
		{
			if (k == i)
			{
				arr[i][1] = colors[1][i];
			}
			else
			{
				arr[i][1] = my_max;
			}
		}
		for (int i = 2; i <= n; i++)
		{
			arr[0][i] = min(arr[1][i - 1], arr[2][i - 1]) + colors[i][0];
			arr[1][i] = min(arr[0][i - 1], arr[2][i - 1]) + colors[i][1];
			arr[2][i] = min(arr[0][i - 1], arr[1][i - 1]) + colors[i][2];
		}
		for (int i = 0; i < 3; i++)
		{
			if(k!=i)
				ans = min(ans, arr[i][n]);
		}
	}
	cout << ans;
}
