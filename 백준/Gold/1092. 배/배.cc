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

int main()
{
	int n;
	cin >> n;
	vector<int> arr;
	int c1 = 0, c2 = 0;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		c1 = max(c1, temp);
		arr.push_back(temp);
	}
	sort(arr.begin(), arr.end(),greater<int>());
	int m;
	cin >> m;
	vector<int> arr2;
	for (int i = 0; i < m; i++)
	{
		int temp;
		cin >> temp;
		c2 = max(c2, temp);
		arr2.push_back(temp*-1);
	}
	if (c2 > c1)
	{
		cout << "-1";
		return 0;
	}
	sort(arr2.begin(), arr2.end());
	int cnt = 0;
	while (arr2.size())
	{
		cnt++;
		for (int i = 0; i < n; i++)
		{
			if (arr2.empty())break;
			auto temp = lower_bound(arr2.begin(), arr2.end(), arr[i] * -1);
			int pos = temp - arr2.begin();
			if (pos == arr2.size())break;
			arr2.erase(temp);
		}
	}
	cout << cnt;
}
