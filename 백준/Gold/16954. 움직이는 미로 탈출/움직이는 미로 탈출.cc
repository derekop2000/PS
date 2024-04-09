#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int dir1[] = {-1,-1,0,1,1,1,0,-1};
int dir2[] = {0,1,1,1,0,-1,-1,-1};

char arr[8][8];
int visit[8][8];
int time_ = 1;
bool ans;
void f()
{
	while (1)
	{
		bool alive = false;
		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 8; j++)
			{
				if (visit[i][j] == time_)
				{
					alive = true;
					visit[i][j] = time_ + 1;
					for (int q = 0; q < 8; q++)
					{
						int ii = i + dir1[q];
						int jj = j + dir2[q];
						if (0 <= ii && ii < 8 && 0 <= jj && jj < 8 && arr[ii][jj] != '#'&&visit[ii][jj]!=time_)
						{
							visit[ii][jj] = time_ + 1;
						}
					}
				}
			}
		if (!alive)break;
		if (visit[0][7]) { ans = true; break; }
		for (int i = 7; i >= 0; i--)
			for (int j = 0; j < 8; j++)
			{
				if (arr[i][j] == '#' && i == 7)arr[i][j] = '.';
				else if (arr[i][j] == '#')
				{
					arr[i][j] = '.';
					arr[i + 1][j] = '#';
					visit[i + 1][j] = 0;
				}
			}
		time_++;
	}
}
int main()
{
	for(int i=0;i<8;i++)
		for (int j = 0; j < 8; j++)
		{
			cin >> arr[i][j];
		}
	visit[7][0] = 1;
	f();
	if (ans)cout << "1";
	else cout << "0";
}

