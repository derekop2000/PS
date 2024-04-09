#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int dir1[] = { -1,0,1,0 };
int dir2[] = { 0,1,0,-1 };
int w, h;
pair<int, int> pos1;
pair<int, int> pos2;
vector<vector<int>> arr;
vector<vector<bool>> visit;
queue<pair<int,int>> q;
void bfs()
{
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int xx = x + dir1[i];
			int yy = y + dir2[i];
			while (1)
			{
				if ( !(0 <= xx && xx < h && 0 <= yy && yy < w && arr[xx][yy] >= 0) )
				{
					break;
				}
				else if (!visit[xx][yy])
				{
					visit[xx][yy] = true;
					arr[xx][yy] = arr[x][y] + 1;
					q.push(make_pair(xx, yy));
				}
				xx += dir1[i];
				yy += dir2[i];
			}
		}
	}
}
int main()
{
	cin >> w >> h;
	arr.resize(h, vector<int>(w,0));
	visit.resize(h, vector<bool>(w, false));
	pos1.first = -1;
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
		{
			char char_temp;
			cin >> char_temp;
			if (char_temp == '*')arr[i][j] = -1;
			else if (char_temp == 'C' && pos1.first == -1)
			{
				pos1.first = i;
				pos1.second = j;
				arr[i][j] = 0;
			}
			else if (char_temp =='C' && pos1.first != -1)
			{
				pos2.first = i;
				pos2.second = j;
				arr[i][j] = 0;
			}
		}
	
	q.push(make_pair(pos1.first,pos1.second));
	visit[pos1.first][pos1.second] = true;
	bfs();
	cout << arr[pos2.first][pos2.second] - 1;
}