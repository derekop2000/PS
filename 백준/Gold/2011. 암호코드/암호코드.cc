#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<map>
#include<sstream>
using namespace std;

int dp[5001];
int main()
{
	string s;
	stringstream ss;
	cin >> s;
	ss.str(s);
	char temp;
	char new_temp;
	ss >> temp;
	if (temp == '0')
	{
		cout << "0";
		exit(0);
	}
	dp[0] = 1;
	dp[1] = 1;
	int index_ = 2;
	while (ss >> new_temp)
	{
		if (new_temp == '0')
		{
			if (temp == '1' || temp == '2')
			{
				dp[index_] = dp[index_ - 2];
				index_++;
				temp = new_temp;
				dp[index_] %= 1000000;
				continue;
			}
			else
			{
				cout << "0";
				exit(0);
			}
		}
		int sum = (temp - '0') * 10 + new_temp - '0';
		if (temp!='0' && sum <= 26)
		{
			dp[index_] = dp[index_ - 1] + dp[index_ - 2];
		}
		else dp[index_] = dp[index_ - 1];
		dp[index_] %= 1000000;
		temp = new_temp;
		index_++;
	}
	index_--;
	cout << dp[index_];
}

