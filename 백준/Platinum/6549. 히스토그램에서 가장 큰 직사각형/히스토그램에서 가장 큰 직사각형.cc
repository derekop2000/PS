#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
#include<memory.h>
#include<string>
#include<sstream>
using namespace std;


int main()
{
	while (true)
	{
		stringstream ss;
		string str;
		getline(cin, str, '\n');
		ss.str(str);
		int n;
		ss >> n;
		if (n == 0)exit(0);
		vector<int> v(n + 1);
		vector<pair<int, int>> s;
		for (int i = 1; i <= n; i++)
		{
			ss >> v[i];
		}
		s.push_back({ 0,0 });
		long long int ans = 0;
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
					if (ans < (i - index) * (long long int)top)
						ans = (i - index) * (long long int)top;
					s.pop_back();
				}
			}

		}
		while (s.empty() == false)
		{
			int top = s.back().first;
			int index = s.back().second;
			s.pop_back();
			if (ans < (n - index + 1) * (long long int)top)
				ans = (n - index + 1) * (long long int)top;
		}
		cout << ans<<"\n";
	}
	
}
  
