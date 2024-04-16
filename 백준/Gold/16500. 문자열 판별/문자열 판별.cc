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
	string s;
	cin >> s;
	int size = s.size();
	int n;
	cin >> n;
	set<string> set;
	for (int i = 0; i < n; i++)
	{
		string temp;
		cin >> temp;
		set.insert(temp);
	}
	vector<bool> dp(size+1,false);
	dp[0] = true;
	for (int i = 1; i <= size; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (dp[j])
			{
				auto it = set.find(s.substr(j, i-j));
				if (it != set.end())
				{
					dp[i] = true;
					break;
				}
			}
		}
	}
	if (dp[size])
		cout << 1;
	else cout << 0;
}