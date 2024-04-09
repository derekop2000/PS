#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
#include<string>
using namespace std;
bool cmp(pair<int, int>& a, pair<int, int>& b)
{
	if (a.first != b.first)
	{
		return a.first < b.first;
	}
	else
	{
		return a.second > b.second;
	}
}
int main()
{
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> arr(n);
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		arr[i] = make_pair(b, a);
	}
	sort(arr.begin(), arr.end(),cmp);

	int amount = 0;
	int price = 0;
	int last_price = 0;
	for (int i = 0; i < n; i++)
	{
		amount += arr[i].second;
		if (last_price == arr[i].first)
		{
			price += arr[i].first;
		}
		else
		{
			price = arr[i].first;
			last_price = arr[i].first;
			
		}
		if (amount >= m)
		{
			int j = i + 1;
			while (j < n)
			{
				if (arr[j].first > arr[i].first)
				{
					price = min(price, arr[j].first);
					break;
				}
				j++;
			}
			break;
		}
	}
	if (amount < m)price = -1;
	cout << price;
}
