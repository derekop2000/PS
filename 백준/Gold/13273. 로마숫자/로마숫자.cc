#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
#include<memory.h>
#include<string>
#include<sstream>
#include<algorithm>
using namespace std;

pair<int, char> table[] = { {1,'I'},{5,'V'},{10,'X'},{50,'L'},{100,'C'},{500,'D'},{1000,'M'} };
int table_size = 7;
void f(string& s) // digit to R
{
	int str_size = s.size();
	string temp;
	for (int i = 0; i < str_size; i++)
	{
		int index = str_size - i-1;
		if (s[index] - '0' == 0)continue;
		int digit = (s[index]-'0');
		int table_index = i * 2;
		if (digit < 4)
		{
			for (int j = 0; j < digit; j++)
				temp.push_back(table[table_index].second);
		}
		else if (digit == 4)
		{
			temp.push_back(table[table_index+1].second);
			temp.push_back(table[table_index].second);
		}
		else if (digit < 9)
		{
			for(int j=digit-5;j>0;j--)
				temp.push_back(table[table_index].second);
			temp.push_back(table[table_index + 1].second);
		}
		else
		{
			temp.push_back(table[table_index + 2].second);
			temp.push_back(table[table_index].second);
		}
	}
	reverse(temp.begin(), temp.end());
	s = temp;
}
void f2(string& s) // R to digit
{
	int str_size = s.size();
	vector<int> v;
	for (int i = 0; i < str_size; i++)
	{
		for (auto a : table)
		{
			if (a.second == s[i])
			{
				v.push_back(a.first);
				break;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < str_size; i++)
	{
		if (i + 1 < str_size && v[i] < v[i+1])
		{
			ans -= v[i];
			ans += v[i + 1];
			i++;
		}
		else ans += v[i];
	}
	s = to_string(ans);
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		string s;
		cin >> s;
		if (0<= '9' - s[0] && '9' - s[0] <= 9)
		{
			f(s);
		}
		else
		{
			f2(s);
		}
		cout << s << "\n";
	}
}