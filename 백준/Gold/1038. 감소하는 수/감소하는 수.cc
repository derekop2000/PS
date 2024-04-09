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

int n;
string str;
int cnt = -1;
bool ans = false;
void f(int total, int now, int last)
{
	if (total == now)
	{
		cnt++;
		if (cnt == n)
		{
			cout << stol(str);
			ans = true;
		}
		return;
	}
	for (int i = 0; i < last; i++)
	{
		str.push_back(i+'0');
		f(total, now + 1, i);
		if (ans)return;
		str.pop_back();
	}
}
void init()
{
	for (int i = 1; i <= 10; i++)
	{
		f(i, 0, 10);
	}
}
int main()
{
	cin >> n;
	init();
	if (ans == false)cout << "-1";
}