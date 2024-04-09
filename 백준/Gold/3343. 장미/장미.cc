#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
#include<string>
using namespace std;

int dir1[] = { -1,0,1,0 };
int dir2[] = { 0,1,0,-1 };

long long n, a, b, c, d, ans = 9223372036854775807LL;
pair<long long,long long> set[2];

int main()
{
	cin >> n >> a >> b >> c >> d;
	if (((double)b / a) > ((double)d / c))
	{
		set[0].first = c;
		set[0].second = d;
		set[1].first = a;
		set[1].second = b;
	}
	else
	{
		set[0].first = a;
		set[0].second = b;
		set[1].first = c;
		set[1].second = d;
	}
	for (long long i = 0; i < set[0].first; i++)
	{
		long long j = (n - (i * set[1].first) + set[0].first - 1) / set[0].first;
		ans = min(ans, i * set[1].second + j * set[0].second);
	}
	cout << ans;
}