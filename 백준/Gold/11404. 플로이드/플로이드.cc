#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int INF = 10000000;
vector<vector<int>> arr;
int n,m;
int main()
{
	cin >> n >> m;
	arr.resize(n, vector<int>(n, INF));
	for (int i = 0; i < n; i++)
	{
		arr[i][i] =0;
	}
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		a--; b--;
		arr[a][b] = min(arr[a][b], c);
	}
	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				arr[i][j] = min(arr[i][k] + arr[k][j], arr[i][j]);
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] == INF)cout << "0 ";
			else cout << arr[i][j] << " ";
		}cout << "\n";
	}
}

