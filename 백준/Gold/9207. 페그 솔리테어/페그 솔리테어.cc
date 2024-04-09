#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
#include<string>
using namespace std;

int dir1[] = {-1,0,1,0};
int dir2[] = {0,1,0,-1};
pair<int,int> ans;
void dfs(vector<vector<char>> v,int _time)
{
	bool is_move =false;
	for(int i=0;i<5;i++)
		for (int j = 0; j < 9; j++)
		{
			if (v[i][j] == 'o')
			{
				for (int k = 0; k < 4; k++)
				{
					int ii = i + dir1[k];
					int jj = j + dir2[k];
					if (0 <= ii && ii < 5 && 0 <= jj && jj < 9)
					{
						if (v[ii][jj] == 'o')
						{
							int iii = ii + dir1[k];
							int jjj = jj + dir2[k];
							if (0 <= iii && iii < 5 && 0 <= jjj && jjj < 9 && v[iii][jjj] == '.')
							{
								is_move = true;
								vector<vector<char>> v2 = v;
								v2[i][j] = '.';
								v2[ii][jj] = '.';
								v2[iii][jjj] = 'o';
								dfs(v2, _time + 1);
							}
						}
					}
				}
			}
		}
	if (is_move == false)
	{
		int cnt = 0;
		for(int i=0;i<5;i++)
			for (int j = 0; j < 9; j++)
			{
				if (v[i][j] == 'o')cnt++;
			}
		if (ans.first > cnt)
			ans = { cnt,_time };
		else if (ans.first == cnt && _time < ans.second)
			ans = { cnt,_time };
		return;
	}
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		vector<vector<char>> v(5, vector<char>(9));
		for(int i=0;i<5;i++)
			for (int j = 0; j < 9; j++)
			{
				cin >> v[i][j];
			}
		ans.first = 2147483647;
		dfs(v, 0);
		cout << ans.first<<" "<<ans.second<<"\n";
	}
}