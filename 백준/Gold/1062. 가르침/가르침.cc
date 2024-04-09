#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
#include<string>
#include<set>
#include<map>
using namespace std;

int n, k;
vector<string> arr;
vector<bool> selected;
vector<bool> useable;
int ans = 0;
void f()
{
	int temp_ans = 0;
	for (int i = 0; i < n; i++)
	{
		bool ok = true;
		for (int j = 0; j < arr[i].size(); j++)
		{
			if (!selected[arr[i][j] - 'a'])
			{
				ok = false; break;
			}
		}
		if (ok)temp_ans++;
	}
	ans = max(ans, temp_ans);
}
void dfs(int floor,int cnt)
{
	if (cnt == k)
	{
		f();
		return;
	}
	for (int i=floor; i<26; i++)
	{
		if (useable[i])
		{
			selected[i] = true;
			dfs(i+1,cnt+1);
			selected[i] = false;
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> k;
	k -= 5;
	cin.ignore(100, '\n');
	selected.resize(26, false);
	useable.resize(26, false);
	selected['a' - 'a'] = true;
	selected['n' - 'a'] = true;
	selected['t' - 'a'] = true;
	selected['i' - 'a'] = true;
	selected['c' - 'a'] = true;
	for (int i = 0; i < n; i++)
	{
		string temp;
		getline(cin, temp, '\n');
		arr.push_back(temp);
		for (int j = 0; j < temp.size(); j++)
		{
			char c = temp[j];
			if (!(c == 'a' || c == 'n' || c == 't' || c == 'i' || c == 'c'))
			{
				useable[c - 'a'] = true;
			}
		}
	}
	int temp = 0;
	for (int i = 0; i < 26; i++)
		if (useable[i])temp++;
	k = min(k, temp);
	dfs(0,0);
	cout << ans;
	
}
