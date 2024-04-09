#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
#include<string>
#include<set>
#include<map>
#include<cmath>
#include <climits>
using namespace std;

int main()
{
	long long int a, b;
	cin >> a >> b;
	long long int c = sqrt((long double)b) + 1;
	vector<bool> arr(c + 1, true);
	arr[0] = false;
	arr[1] = false;
	for (long long int i = 2; i*i <= c; i++)
	{
		if (arr[i])
		{
			for (long long int j = i * 2; j <= c; j+=i)
			{
				arr[j] = false;
			}
		}
	}
	long long int ans = 0;
	for (long long int i = 2; i <= c; i++)
	{
		if (arr[i])
		{
			for (long long int j = i * i; j <= b; j *= i)
			{
				if(j>=a)
					ans++;
				if (j > LLONG_MAX / i)break;
			}
		}
	}
	cout << ans;
}
