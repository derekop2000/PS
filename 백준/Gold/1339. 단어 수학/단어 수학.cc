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

vector<int> const_value;
vector<pair<int, int>> value;
vector<string> strs;
vector<pair<int, int>> v;
int now = 9;
int main()
{
	for (int i = 0; i < 26; i++)
	{
		value.push_back({ 0,i });
		const_value.push_back(0);
	}
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		strs.push_back(s);
	}
	for (int i = 0; i < n; i++)
	{
		int str_size = strs[i].size();
		for (int j = 0; j < str_size; j++)
		{
			char c = strs[i][str_size-j-1];
			value[c - 'A'].first += (int)pow(10, j);
		}
	}
	sort(value.begin(), value.end(), greater<pair<int, int>>());
	int now = 9;
	for (int i = 0; i < value.size(); i++)
	{
		const_value[value[i].second] += now--;
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < strs[i].size(); j++)
		{
			char c = strs[i][j];
			strs[i][j] = const_value[c - 'A'] + '0';
		}
		ans += stoi(strs[i]);
	}
	cout << ans;
}