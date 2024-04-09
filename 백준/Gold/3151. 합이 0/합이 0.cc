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

long long int ans = 0;
int f(vector<int> arr,int num)
{
	int s = 0;
	int e = arr.size()-1;
	while (s <= e)
	{
		int mid = (s + e) / 2;
		if (arr[mid] == num)
		{
			return mid;
		}
		if (arr[mid] > num)
		{
			e = mid - 1;
		}
		else
		{
			s = mid + 1;
		}
	}
	return -1;
}
int main()
{
	int n;
	cin >> n;
	vector<int> arr;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		arr.push_back(temp);
	}
	sort(arr.begin(), arr.end());
	for(int i=0;i<n;i++)
		for (int j = i + 1; j < n; j++)
		{
			int temp = arr[i] + arr[j];
			temp *= -1;
			auto a = upper_bound(arr.begin() + j + 1, arr.end(), temp) - arr.begin();
			auto b = lower_bound(arr.begin() + j + 1, arr.end(), temp) - arr.begin();
			ans += (a - b);
		}
	cout << ans;
}
