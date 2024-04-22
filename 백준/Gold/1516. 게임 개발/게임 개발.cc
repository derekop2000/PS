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
	vector<vector<int>> arr(n+1, vector<int>(n+1, INT_MAX));
	for (int i = 1; i <= n; i++)
	{
		int time;
		cin >> time;
		int cnt = 0;
		while (true)
		{
			int prevV;
			cin >> prevV;
			if (prevV == -1)break;
			cnt++;
			arr[prevV][i] = min(arr[prevV][i], time);
		}
		if (cnt == 0)
			arr[0][i] = time;
	}
	for(int k=0;k<=n;k++)
		for(int i=0;i<=n;i++)
			for (int j = 0; j <= n; j++)
			{
				if (i == j)continue;
				if (arr[i][k] < INT_MAX && arr[k][j] < INT_MAX)
				{
					if (arr[i][j] == INT_MAX)
						arr[i][j] = arr[i][k] + arr[k][j];
					else arr[i][j] = max(arr[i][k] + arr[k][j], arr[i][j]);
				}
			}
	for (int i = 1; i <= n; i++)
		cout << arr[0][i] << "\n";
}