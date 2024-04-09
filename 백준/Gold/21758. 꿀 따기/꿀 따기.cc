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
	vector<int> v;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	int first_value = 0;
	for (int i = 2; i < n; i++)
	{
		first_value += v[i]*2;
	}
	int ans = first_value;
	for (int i = 2; i < n - 1; i++)
	{
		first_value = first_value + v[i - 1] - v[i] - v[i];
		ans = max(ans, first_value);
	}
	first_value = 0;
	for (int i = 0; i < n - 2; i++)
	{
		first_value += v[i] * 2;
	}
	ans = max(ans, first_value);
	for (int i = n - 3; i > 0; i--)
	{
		first_value = first_value + v[i + 1] - v[i] - v[i];
		ans = max(ans, first_value);
	}
	first_value = 0;
	for (int i = 1; i < n - 1; i++)
	{
		first_value += v[i];
	}
	for (int i = 1; i < n - 1; i++)
	{
		ans = max(ans, first_value + v[i]);
	}
	cout << ans;
}
