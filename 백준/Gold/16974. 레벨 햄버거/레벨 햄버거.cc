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

int main()
{
	long long int n, x;
	cin >> n >> x;
	vector<long long int> dpCnt(51, 0);
	vector<long long int> dpP(51, 0);
	dpCnt[0] = 1;
	dpP[0] = 1;
	for (int i = 1; i <= 50; i++)
	{
		dpCnt[i] = dpCnt[i - 1] * 2 + 3;
		dpP[i] = dpP[i - 1] * 2 + 1;
	}

	long long int ans = 0;
	
	while (true)
	{
		if (n == 0)
		{
			if (x > 0)ans++;
			break;
		}
		long long int mid = dpCnt[n] / 2;
		if (x > mid)
		{
			ans++;
		}
		if (x >= mid)
		{
			ans += dpP[n - 1];
			x -= (mid + 1);
			n--;
		}
		else
		{
			n--;
			x--;
		}
	}
	cout << ans;
}