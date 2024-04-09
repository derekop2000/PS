#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
#include<string>
using namespace std;
int a, b;
long long int sum_n(long long int cnt)
{
	return cnt * cnt;
}
int main()
{
	cin >> a >> b;
	a = b - a;
	long long int cnt = 1;
	if (a)
	{
		while (true)
		{
			long long int temp = sum_n(cnt);
			if (temp == a)break;
			else if (temp > a) { cnt--; break; }
			else;
			cnt++;
		}
		a -= sum_n(cnt);
		int c = a / cnt;
		if (a % cnt)c++;
		cnt += (cnt - 1);
		cnt += c;
	}
	else cnt = 0;
	cout << cnt;
}