#include <iostream>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <queue>
#include <map>
#include<tuple>
using namespace std;

int dir1[] = {-1,-1,0,1,1,1,0,-1};
int dir2[] = {0,1,1,1,0,-1,-1,-1};
int ans = 0;
struct fire_ball
{
	int i, j, m, d, s;
};
int n, m, k;
map<int, fire_ball> _list;
int main()
{
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++)
	{
		fire_ball temp;
		cin >> temp.i >> temp.j >> temp.m >> temp.s >> temp.d;
		temp.i--;
		temp.j--;
		_list.insert({ i, temp });

	}
	for (int i = 0; i < k; i++)
	{
		auto p = _list.begin();
		vector<vector<vector<fire_ball>>> arr(n, vector<vector<fire_ball>>(n));
		while (p != _list.end())
		{
			int temp_i = p->second.i + dir1[p->second.d] * (p->second.s % n);
			int temp_j = p->second.j + dir2[p->second.d] * (p->second.s % n);
			
			temp_i = (temp_i + n) % n;
			temp_j = (temp_j + n) % n;

			p->second.i = temp_i;
			p->second.j = temp_j;
			arr[temp_i][temp_j].push_back(p->second);
			p++;
		}
		_list.clear();
		int _list_size = 0;
		for(int ii=0;ii<n;ii++)
			for (int jj = 0; jj < n; jj++)
			{
				int cnt = arr[ii][jj].size();
				if (cnt > 1)
				{
					int new_m = 0;
					int new_s = 0;
					int check_even = 0;
					int check_odd = 0;
					for (int q = 0; q < cnt; q++)
					{
						new_m += arr[ii][jj][q].m;
						new_s += arr[ii][jj][q].s;
						if (arr[ii][jj][q].d % 2)
							check_odd++;
						else check_even++;
					}
					new_m /= 5;
					new_s /= cnt;
					if (new_m == 0)continue;
					if (check_even!=cnt && check_odd != cnt)//다름
					{
						for (int four = 1; four < 8; four += 2)
						{
							fire_ball temp;
							temp.i = ii;
							temp.j = jj;
							temp.m = new_m;
							temp.d = four;
							temp.s = new_s;
							_list.insert({_list_size++, temp});
						}
					}
					else// 모두 짝, 홀
					{
						for (int four = 0; four < 8; four += 2)
						{
							fire_ball temp;
							temp.i = ii;
							temp.j = jj;
							temp.m = new_m;
							temp.d = four;
							temp.s = new_s;
							_list.insert({ _list_size++, temp });
						}
					}
				}
				else if (cnt == 1)
				{
					_list.insert({ _list_size++, arr[ii][jj][0]});
				}
			}
		
	}
	for (auto p = _list.begin(); p != _list.end(); p++)
	{
		ans += p->second.m;
	}
	cout << ans;
}
