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
#include<sstream>
#include<deque>
using namespace std;


int main()
{
	string str;
	getline(cin, str, '\n');
	int str_size = str.size();
	vector<char> c_v;
	vector<int> v(str_size+2,0);
	bool wrong = false;
	for (int i = 0; i < str_size; i++)
	{
		if (str[i] == '(' || str[i] == '[')
		{
			c_v.push_back(str[i]);
		}
		else
		{
			if (c_v.empty() || str[i]==')'&&c_v.back()=='[' || str[i]==']' && c_v.back()=='(')
			{
				wrong = true;
				break;
			}
			int temp = c_v.size();
			int temp2;
			if (v[temp + 1] > 0)
			{
				temp2 = v[temp + 1] * (str[i] == ')' ? 2 : 3);
			}
			else temp2 = (str[i] == ')' ? 2 : 3);
			v[temp + 1] = 0;
			v[temp] += temp2;
			c_v.pop_back();
		}
	}
	if (wrong) cout << "0";
	else cout << v[1];
}