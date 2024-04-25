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

int _n,_m,_k;
vector<vector<int>> _arr;
queue<tuple<int, int,int>> _q; // pos + K_Cnt
vector<vector<vector<int>>> _dp;
int dir[4][2] = { {-1,0} ,{0,1} ,{1,0} ,{0,-1} };
int _ans = INT_MAX;
void f()
{
	bool light = true;
	int time = 2;
	_dp[0][0][0] = 1;
	_q.push({ 0,0,0});
	while (_q.empty() == false)
	{
		int size = _q.size();
		for (int i = 0; i < size; i++)
		{
			auto info = _q.front();_q.pop();
			int y = get<0>(info);
			int x = get<1>(info);
			int kCnt = get<2>(info);
			if (y == _n - 1 && x == _m - 1)
			{
				_ans = time-1;
				return;
			}
			bool canStop = false;
			for (int j = 0; j < 4; j++)
			{
				int yy = y + dir[j][0];
				int xx = x + dir[j][1];
				if (0 <= yy && yy < _n && 0 <= xx && xx < _m)
				{
					if (light) // 낮
					{
						if (_arr[yy][xx] == 0 && time < _dp[yy][xx][kCnt])
						{
							_dp[yy][xx][kCnt] = time;
							_q.push({ yy,xx,kCnt});
						}
						else if (_arr[yy][xx] == 1 && kCnt < _k && time < _dp[yy][xx][kCnt + 1])
						{
							_dp[yy][xx][kCnt + 1] = time;
							_q.push({ yy,xx,kCnt + 1 });
						}
					}
					else // 밤
					{
						if (_arr[yy][xx] == 0 && time < _dp[yy][xx][kCnt])
						{
							_dp[yy][xx][kCnt] = time;
							_q.push({ yy,xx,kCnt });
						}
						else if (_arr[yy][xx] == 1 && kCnt < _k)
						{
							canStop = true;
						}
					}
				}
			}
			if (canStop)
			{
				_q.push({ y,x,kCnt });
			}
		}
		light = !light;
		time++;
		// 낮밤 바꾸기 + 시간 
	}
}

int main()
{
	cin >> _n >>_m >>_k;
	_arr.resize(_n, vector<int>(_m));
	_dp.resize(_n, vector<vector<int>>(_m,vector<int>(_k+1,INT_MAX)));
	for(int i=0;i<_n;i++)
		for (int j = 0; j < _m; j++)
		{
			char temp;
			cin >> temp;
			_arr[i][j] = temp - '0';
		}
	f();
	
	if (_ans == INT_MAX)
		cout << "-1";
	else cout <<_ans;
}