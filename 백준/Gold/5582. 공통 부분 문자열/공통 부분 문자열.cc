#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
#include<string>
using namespace std;


int main()
{
	string s1;
	string s2;
	getline(cin, s1);
	getline(cin, s2);
	int ans = 0;
	vector<vector<int>> arr(s1.size()+1, vector<int>(s2.size()+1,0));
	for(int i=0;i<s1.size();i++)
		for (int j = 0; j < s2.size(); j++)
		{
			if (s1[i] == s2[j])
				arr[i + 1][j + 1] = arr[i][j] + 1;
			else arr[i + 1][j + 1] = 0;
			ans = max(ans, arr[i + 1][j + 1]);
		}
	cout << ans;

}