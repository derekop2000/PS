#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
#include<memory.h>
#include<string>
#include<sstream>
#include<algorithm>
using namespace std;

int n, m;
vector<vector<int>> arr;
vector<vector<int>> arr2;
int main()
{
	cin >> n >> m;
	arr.resize(n, vector<int>(n,99999));
	arr2.resize(n, vector<int>(n));
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		a--; b--;
		arr[a][b] = c;
		arr[b][a] = c;
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			if (i == j)
			{
				arr[i][i] = 0;
				arr2[i][j] = -1;
			}
			else
				arr2[i][j] = j;
		}
	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (i == j)continue;
				int temp = arr[i][k] + arr[k][j];
				if (temp < arr[i][j])
				{
					arr[i][j] = temp;
					arr2[i][j] = arr2[i][k];
				}
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)cout << "- ";
			else cout << arr2[i][j]+1 << " ";
		}
		cout << "\n";
	}
}