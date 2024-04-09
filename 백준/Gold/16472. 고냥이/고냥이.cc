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
int alphabet[26];
int cnt = 0; 
int ans = 0;
int main()
{
	cin >> n >> str;
	int l = 0; int r = 0; 
	while (true)
	{
		if (r >= str.size())break;
		char c = str[r];
		if (cnt < n)
		{
			if (alphabet[c - 'a'] == 0) 
			{
				cnt++;
			}
		}
		else
		{
			if (alphabet[c - 'a']==0) 
			{
				cnt++;
				while (true)
				{
					alphabet[str[l] - 'a']--;
					if (alphabet[str[l] - 'a'] == 0)
					{
						cnt--;
						l++;
						break;
					}
					l++;
				}
			}
		}

		alphabet[c - 'a']++;
		ans = max(ans, r - l + 1);
		r++;
	}
	cout << ans;
}