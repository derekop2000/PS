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
int d;
string num;
long long int move_x, move_y;
pair<long long int, long long int>next_pos;
vector<int> ans;
void f1(long long int min_x, long long int max_x, long long int min_y, long long int max_y, int floor)
{
	if (floor == d)
	{
		next_pos.first = min_x + move_x;
		next_pos.second = min_y + move_y;
		return;
	}
	int quater = num[floor] - '0';
	if (quater > 2)
	{
		max_y = (min_y + max_y) / 2;
	}
	else
	{
		min_y = (min_y + max_y) / 2;
	}
	if (quater == 1 || quater == 4)
	{
		min_x = (min_x + max_x) / 2;
	}
	else
	{
		max_x = (min_x + max_x) / 2;
	}
	f1(min_x, max_x, min_y, max_y, floor + 1);
}
bool can = true;
void f2(long long int min_x, long long int max_x, long long int min_y, long long int max_y, int floor)
{
	if (floor == d)
	{
		return;
	}
	if (!(min_x <= next_pos.first && next_pos.first < max_x && min_y <= next_pos.second && next_pos.second < max_y))
	{
		can = false;
		return;
	}
	long long int mid_x = (min_x + max_x) / 2;
	long long int mid_y = (min_y + max_y) / 2;

	int temp;
	if (mid_x <= next_pos.first && mid_y <= next_pos.second)
	{
		min_x = mid_x;
		min_y = mid_y;
		temp = 1;
	}
	else if (mid_x > next_pos.first && mid_y <= next_pos.second)
	{
		max_x = mid_x;
		min_y = mid_y;
		temp = 2;
	}
	else if (mid_x > next_pos.first && mid_y > next_pos.second)
	{
		max_x = mid_x;
		max_y = mid_y;
		temp = 3;
	}
	else
	{
		min_x = mid_x;
		max_y = mid_y;
		temp = 4;
	}
	ans.push_back(temp);
	f2(min_x, max_x, min_y, max_y, floor + 1);
}

long long int my_pow(int a, int b)
{
	long long int re = 1;
	for (int i = 0; i < b; i++)
	{
		re *= a;
	}
	return re;
}
int main()
{
	cin >> d >> num >> move_x >> move_y;
	long long int temp = my_pow(2, d);
	f1(0, temp, 0, temp, 0);
	f2(0, temp, 0, temp, 0);
	if (can)
	{
		for (int i = 0; i < ans.size(); i++)
			cout << ans[i];
	}
	else cout << "-1";

}