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
using namespace std;


int main()
{
	int n, m;
	cin >> n >> m;
	if (n > m)
	{
		cout << "!";
		return 0;
	}
	vector<char> ans;
	bool _fail = false;
	for (int i = 1; i <= n; i++)
	{
		if (m - 1 <= (n - i) * 26)
		{
			ans.push_back('A');
			m--;
		}
		else
		{
			int temp = m - (n - i) * 26;
			if (temp > 26)
			{
				_fail = true;
				break;
			}
			else
			{
				ans.push_back(temp+'A'-1);
				m -= temp;
			}
		}
	}
	if (_fail)
		cout << "!";
	else
	{
		for (int i = 0; i < n; i++)
			cout << ans[i];
	}
}
