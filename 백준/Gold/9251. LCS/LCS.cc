#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
#include<string>
using namespace std;


int main()
{
	int ans = 0;
	string a, b;
	cin >> a >> b;
	vector<vector<int>> arr(a.size()+1, vector<int>(b.size()+1, 0));
	for(int i=1;i<=a.size();i++)
		for (int j = 1; j <= b.size(); j++)
		{
			arr[i][j] = arr[i - 1][j-1] + (a[i-1] == b[j-1] ? 1 : 0);
			arr[i][j] = max(arr[i][j], max(arr[i - 1][j], arr[i][j - 1]));
			ans = max(ans, arr[i][j]);
		}
	cout << ans;
}
