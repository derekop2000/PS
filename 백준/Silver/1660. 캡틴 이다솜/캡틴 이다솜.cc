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


int main()
{
	int n;
	cin >> n;
	int cnt = 2;
	vector<int> arr1;
	vector<int> arr2;
	arr1.push_back(1);
	while (true)
	{
		int temp = arr1.back() + cnt;
		if (temp > 300000)break;
		arr1.push_back(temp);
		cnt++;
	}
	cnt = 0;
	for (int i = 0; i < arr1.size(); i++)
	{
		cnt += arr1[i];
		if (cnt > 300000)break;
		arr2.push_back(cnt);
	}
	vector<int> dp(300001, 300000);
	dp[0] = 0;
	for (int i = 0; i < arr2.size(); i++)
	{
		dp[arr2[i]] = 1;
	}
	for (int i = 0; i < arr2.size(); i++)
	{
		for (int j = arr2[i]; j <= n; j++)
		{
			dp[j] = min(dp[j], dp[j -arr2[i]] + 1);
		}
	}
	cout << dp[n];
}