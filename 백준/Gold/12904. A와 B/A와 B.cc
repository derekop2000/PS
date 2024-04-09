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
	string a, b;
	cin >> a >> b;
	int temp = b.size() - a.size();
	int index = b.size()-1;
	for (int i = 0; i < temp; i++)
	{
		bool rever = b.back() == 'B';
		b.pop_back();
		if (rever)
			reverse(b.begin(), b.end());
	}
	if (a.compare(b) == 0)
		cout << "1";
	else cout << "0";
}