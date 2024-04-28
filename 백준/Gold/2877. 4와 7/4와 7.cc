#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
#include<memory.h>
#include<string>
#include<sstream>
#include<algorithm>
#include<map>
#include<set>
#include<iomanip>
#include<climits>
using namespace std;


int main()
{
	int n;
	cin >> n;
	n++;
	string s;
	while (true)
	{
		if (n % 2 == 0)
			s.push_back('4');
		else s.push_back('7');
		n /= 2;
		if (n == 1)break;
	}
	for (int i = s.size() - 1; i >= 0; i--)
		cout << s[i];
}