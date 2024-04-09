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

using namespace std;

map<string, string> dic
= { {"a", "a"},{"b","b"},{"k","c"},{"d","d"},{"e","e"},{"g","f"},
	{"h","g"},{"i","h"},{"l","i"},{"m","j"},{"n","k"},{"ng","l"},{"o","m"},{"p","n"},
	{"r","o"},{"s","p"},{"t","q"},{"u","r"},{"w","s"},{"y","t"} };
vector<pair<string, string>> v;
int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		string str;
		cin >> str;
		string temp_str = "";
		for (int j = 0; j < str.size(); j++)
		{
			if (str[j] == 'n'&& j != str.size() - 1 && str[j + 1] == 'g')
			{
				j++;
				temp_str += "l";
			}
			else
			{
				string s="";
				s+=str[j];
				auto iter = dic.find(s);
				temp_str += (*iter).second;
			}
		}
		v.push_back({ temp_str,str });
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i].second << "\n";
	}
}