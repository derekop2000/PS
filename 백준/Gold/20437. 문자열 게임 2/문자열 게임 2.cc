#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		string w;
		int k;
		cin >> w;
		cin >> k;
		vector<vector<int>> arr(26);
		for (int i = 0; i < w.size(); i++)
		{
			arr[w[i] - 'a'].push_back(i);
		}
		bool aright = false;
		int min_ = 10000;
		int max_ = 0;
		for (int i = 0; i < 26; i++)
		{
			if (arr[i].size() < k)continue;
			aright = true;
			for (int j = 0; j<=(arr[i].size() - k); j++)
			{
				min_ = min(min_, arr[i][j + k - 1] - arr[i][j] + 1);
				max_ = max(max_, arr[i][j + k - 1] - arr[i][j] + 1);
			}
		}
		if (aright)
		{
			cout << min_ << " " << max_ << "\n";
		}
		else cout << "-1\n";
	}
}