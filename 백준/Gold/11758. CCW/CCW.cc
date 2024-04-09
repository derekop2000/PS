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

pair<int, int> poss[3];
int main()
{
	for (int i = 0; i < 3; i++)
	{
		cin >> poss[i].first >> poss[i].second;
	}
	int value = poss[0].first * poss[1].second + poss[1].first * poss[2].second + poss[2].first * poss[0].second - (poss[0].first * poss[2].second + poss[1].first * poss[0].second + poss[2].first * poss[1].second);
	if (value > 0) cout << "1";
	else if (value < 0)cout << "-1";
	else cout << 0;
}