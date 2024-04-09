#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
#include<string>
using namespace std;


int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> arr(n,vector<int>(m));
	int ans = 0;
	for(int i=0;i<n;i++)
		for (int j = 0; j < m; j++)
		{
			char temp;
			cin >> temp;
			arr[i][j] = temp-'0';
			if (arr[i][j] == 1)ans = 1;
		}
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < m; j++)
		{
			if (arr[i][j] == 1)
			{
				int temp = min(arr[i][j - 1],min(arr[i - 1][j - 1], arr[i - 1][j]))+1;
				arr[i][j] = max(1, temp);
				ans = max(ans, arr[i][j]);
			}
		}
	}
	cout << ans*ans;
}
