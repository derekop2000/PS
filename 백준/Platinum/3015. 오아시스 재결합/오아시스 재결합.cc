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

using namespace std;

int main()
{
	int n;
	cin >> n;
	long long int ans = 0;
	vector<pair<int,int>> stack;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;

		if (stack.empty())
		{
			stack.push_back({temp,1});
			continue;
		}
		if (temp > stack.back().first)
		{
			int temp2 = 0;
			while (stack.empty() == false && stack.back().first < temp)
			{
				temp2 += stack.back().second;
				stack.pop_back();
			}
			if (stack.empty())
			{
				stack.push_back({ temp,1 });
			}
			else if (stack.back().first == temp)
			{
				temp2 += stack.back().second;
				if (stack.size() > 1)
					temp2++;
				stack.back().second++; //?
			}
			else
			{
				temp2++;
				stack.push_back({ temp,1 });
			}
			ans += temp2;
		}
		else if (temp == stack.back().first)
		{
			int temp2 = 0;
			temp2 += stack.back().second;
			if (stack.size() > 1)
				temp2++;
			stack.back().second++;
			ans += temp2;
		}
		else
		{
			ans++;
			stack.push_back({ temp ,1});
		}
	}
	cout << ans;
}