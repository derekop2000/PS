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
	int n,m;
	cin >> n;
	vector<int> value;
	vector<pair<int,int>> sorted;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		value.push_back(temp);
		sorted.push_back({ temp,i });
	}
	cin >> m;
	sort(sorted.begin(), sorted.end());
	if (sorted.size() == 1 && sorted[0].second == 0)
	{
		cout << 0;
		return 0;
	}
	if (sorted[0].second == 0 && sorted[1].first > m)
	{
		cout << 0;
		return 0;
	}
	vector<int> ans;
	if (sorted[0].second == 0)
	{
		ans.push_back(sorted[1].second);
		m -= sorted[1].first;
	}
	while (m>=sorted[0].first)
	{
		ans.push_back(sorted[0].second);
		m -= sorted[0].first;
	}
	for (int i = 0; i < ans.size(); i++)
	{
		for (int j = value.size() - 1; j >= 0; j--)
		{
			if (j > ans[i] && (m + value[ans[i]]) >= value[j])
			{
				m += value[ans[i]];
				m -= value[j];
				ans[i] = j;
				break;
			}
		}
	}
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i];
}