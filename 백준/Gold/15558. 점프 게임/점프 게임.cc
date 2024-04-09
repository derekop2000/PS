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

int n, k;
string str[2];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	cin >> n >> k >> str[0] >> str[1];
	queue<tuple<bool, int, int>> q;
	q.push({ 0,0,0 }); // is_right, distacne, time
	bool ans = false;
	while (q.empty() == false)
	{
		auto now = q.front(); q.pop();
		int _is_right = get<0>(now);
		int _dis = get<1>(now);
		int _time = get<2>(now);
		
		if (_dis + k >= n)
		{
			ans = true;
			break;
		}
		if (str[_is_right][_dis + 1] == '1' && _time + 1 <= _dis + 1)
		{
			str[_is_right][_dis+1] = '0';
			q.push({ _is_right,_dis + 1,_time + 1 });
		}
		if (_dis > 0 && str[_is_right][_dis - 1] == '1' && _time + 1 <= _dis - 1)
		{
			str[_is_right][_dis-1] = '0';
			q.push({ _is_right,_dis - 1,_time + 1 });
		}
		if (str[_is_right ^ 1][_dis + k] == '1' && _time + 1 <= _dis + k)
		{
			str[_is_right^1][_dis+k] = '0';
			q.push({ _is_right ^ 1,_dis + k,_time + 1 });
		}
	}
	if (ans) cout << "1";
	else cout << "0";
}