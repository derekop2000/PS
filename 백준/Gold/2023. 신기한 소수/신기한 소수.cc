#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
#include<string>
#include<set>
#include<map>

using namespace std;
int n;
vector<int> arr;
vector<int> ans;
bool is_prime(int a)
{
	if (a < 2)return false;
	for (int i = 2; i * i <= a; i++)
	{
		if (a % i == 0)return false;
	}return true;
}
void dfs()
{
	if (arr.size() == n)
	{
		int temp = 0;
		int x = 1;
		for (int j = arr.size() - 1; j >= 0; j--)
		{
			temp += arr[j] * x;
			x *= 10;
		}
		ans.push_back(temp);
		return;
	}
	for (int i = 1; i <= 9; i++)
	{
		int temp = 0;
		temp += i;
		int x = 10;
		for (int j = arr.size() - 1; j >= 0; j--)
		{
			temp += arr[j] * x;
			x *= 10;
		}
		if (is_prime(temp))
		{
			arr.push_back(i);
			dfs();
			arr.pop_back();
		}
	}
}
void f()
{
	arr.push_back(2);
	dfs();
	arr.pop_back();
	arr.push_back(3);
	dfs();
	arr.pop_back();
	arr.push_back(5);
	dfs();
	arr.pop_back();
	arr.push_back(7);
	dfs();
	arr.pop_back();
}
int main()
{
	cin >> n;
	f();
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << "\n";
	}
}
