#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
#include<string>
using namespace std;
int n, m;
bool useable[10];
int place = 1;
string str;
vector<int> ans2;
int ans3;
int get_digit(int v);
void f(bool _up, bool _over)
{
	if (ans2.size() == place)
	{
		ans3 = 0;
		int ii = 1;
		for (int i = 0; i < place; i++)
		{
			ans3 += (ans2.back() * ii);
			ans2.pop_back();
			ii *= 10;
		}
	}
	if (ans3 != -1)return;
	int add = 1;
	if (_up == false)add = -1;
	int i = str[ans2.size()] - '0';
	if (_over)
	{
		if (_up)i = 0;
		else i = 9;
	}
	for (;; i += add)
	{
		if (i < 0 || i >9)break;
		if (useable[i])
		{
			if (i != str[ans2.size()] - '0')
				_over = true;
			ans2.push_back(i);
			f(_up, _over);
			if (ans3 != -1)return;
			ans2.pop_back();
		}
	}
}
int main()
{
	int big = 0;
	int small = 9;
	cin >> n >> m;
	str = to_string(n);
	for (int i = 0; i < 10; i++)
		useable[i] = true;
	for (int i = 0; i < m; i++)
	{
		int temp;
		cin >> temp;
		useable[temp] = false;

	}
	for (int i = 0; i <= 9; i++)
	{
		if (useable[i])
		{
			big = max(big, i);
			small = min(small, i);
		}
	}
	int ans1 = abs(100 - n);
	if (m == 10)
	{
		cout << ans1;
		return 0;
	}
	int temp = n;
	while (temp / 10)
	{
		temp /= 10;
		place++;
	}
	ans3 = -1;
	f(true, false);
	bool change = false;
	if (ans3 == -1)
	{
		if (small == 0 && m == 9);
		else
		{
			change = true;
			ans3 = 0;
			if (small == 0)
				for (int i = 1; i < 10; i++)
				{
					if (useable[i])
					{
						ans3 += i;
						break;
					}
				}
			for (int i = 0; i <= place; i++)
			{
				ans3 += small;
				ans3 *= 10;
			}
			ans3 /= 10;
		}
		
	}
	if (ans3 != -1)ans1 = min(ans1, abs(ans3 - n) + get_digit(ans3));
	ans3 = -1;
	f(false, false);
	change = false;
	if (ans3 == -1 && place>1)
	{
		change = true;
		ans3 = 0;
		for (int i = 0; i < place - 1; i++)
		{
			ans3 += big;
			ans3 *= 10;
		}
		ans3 /= 10;
	}
	if(ans3!=-1)ans1 = min(ans1, abs(ans3 - n) + get_digit(ans3));
	cout << ans1;
}
int get_digit(int v)
{
	int re = 1;
	while (v / 10)
	{
		re++;
		v /= 10;
	}
	return re;
}