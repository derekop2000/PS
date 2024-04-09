#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
#include<memory.h>
#include<string>
using namespace std;


int main()
{
	int n;
	cin >> n;
	vector<int> v(n + 1);
	vector<pair<int,int>> s;
	for (int i = 1; i <= n; i++)
	{
		cin >> v[i];
	}
	s.push_back({0,0});
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		int index_temp = i;
		while (true)
		{
			int top = s.back().first;
			int index = s.back().second;
			
			if (v[i] > top)
			{
				s.push_back({ v[i], index_temp });
				break;
			}
			else if (v[i] == top)
			{
				break;
			}
			else
			{
				index_temp = index;
				ans = max(ans, (i - index) * top);
				s.pop_back();
			}
		}
		
	}
	while (s.empty() == false)
	{
		int top = s.back().first;
		int index = s.back().second;
		s.pop_back();
		ans = max(ans, (n - index + 1) * top);
	}
	cout << ans;
}
  
