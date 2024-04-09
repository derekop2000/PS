#include <iostream>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <queue>
#include <map>
#include<tuple>
using namespace std;
int n, p, f, s, v;
vector<vector<int>> arr;
vector<int> ans_index;
vector<int> confirmed_ans_index;
int ans = 999999;
int mp, mf, ms, mv;
void func(int now,int money)
{
	if (mp >= p && mf >= f && ms >= s && mv >= v)
	{
		ans = money;
		confirmed_ans_index = ans_index;
		return;
	}
	for(int i = now + 1; i < arr.size(); i++)
	{
		if (arr[i][4] + money < ans)
		{
			ans_index.push_back(i);
			mp += arr[i][0];
			mf += arr[i][1];
			ms += arr[i][2];
			mv += arr[i][3];
			func(i, arr[i][4] + money);
			ans_index.pop_back();
			mp -= arr[i][0];
			mf -= arr[i][1];
			ms -= arr[i][2];
			mv -= arr[i][3];
		}
	}
}
int main()
{
	cin >> n >> p >> f >> s >> v;
	arr.resize(n, vector<int>(5));
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2] >> arr[i][3] >> arr[i][4];
	}
	func(-1, 0);
	if (confirmed_ans_index.size() == 0)
	{
		cout << "-1";
	}
	else
	{
		cout << ans << "\n";
		for (int i = 0; i < confirmed_ans_index.size(); i++)
		{
			cout << confirmed_ans_index[i]+1 << " ";
		}
	}
}
