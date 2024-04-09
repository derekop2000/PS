#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int dir1[] = {-1,0,1,0};
int dir2[] = {0,1,0,-1};
int r, c, m;
int kingPos = -1;
int ans = 0;
struct shark
{
	int x;
	int y;
	int speed;
	int dir;
	int size;
};
vector<vector<shark>> arr;
queue<shark> q;

void match()
{
	for(int i=0;i<r;i++)
		for (int j = 0; j < c; j++)
		{
			arr[i][j].x = -1;
		}
	while (!q.empty())
	{
		if (arr[q.front().x][q.front().y].x!=-1 && arr[q.front().x][q.front().y].size > q.front().size )
		{
			q.pop();
			continue;
		}
		arr[q.front().x][q.front().y].x = q.front().x;
		arr[q.front().x][q.front().y].y = q.front().y;
		arr[q.front().x][q.front().y].speed = q.front().speed;
		arr[q.front().x][q.front().y].dir = q.front().dir;
		arr[q.front().x][q.front().y].size = q.front().size;
		q.pop();
	}
}
void catch_()
{
	for (int i = 0; i < r; i++)
	{
		if (arr[i][kingPos].x != -1)
		{
			arr[i][kingPos].x = -1;
			ans += arr[i][kingPos].size;
			break;
		}
	}
}
void move_()
{
	for(int i=0;i<r;i++)
		for (int j = 0; j < c; j++)
		{
			if (arr[i][j].x != -1)
			{
				shark newshark;
				newshark.x = arr[i][j].x;
				newshark.y = arr[i][j].y;
				newshark.speed = arr[i][j].speed;
				newshark.dir = arr[i][j].dir;
				newshark.size = arr[i][j].size;
				if (newshark.dir % 2 == 0)
				{
					newshark.speed = newshark.speed % ((r - 1) * 2);
				}
				else
				{
					newshark.speed = newshark.speed % ((c - 1) * 2);
				}
				for (int q = 0; q < newshark.speed; q++)
				{
					newshark.x += dir1[newshark.dir];
					newshark.y += dir2[newshark.dir];
					if (0 <= newshark.x && newshark.x < r && 0 <= newshark.y && newshark.y < c)
						continue;
					else
					{
						newshark.x -= (2*dir1[newshark.dir]);
						newshark.y -= (2 * dir2[newshark.dir]);
						newshark.dir = (newshark.dir + 2) % 4;
					}
				}
				q.push(newshark);
			}
		}
}
void f()
{
	match();
	while (1)
	{
		kingPos++;
		if (kingPos == c)
			break;
		catch_();
		move_();
		match();
	}
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	cin >> r >> c >> m;
	arr.resize(r, vector<shark>(c));
	for (int i = 0; i < m; i++)
	{
		int x, y, speed, dir, size;
		cin >> x >> y >> speed >> dir >> size;
		x--;
		y--;
		switch (dir)
		{
			case 1: {dir = 0; break; }
			case 2: {dir = 2; break; }
			case 3: {dir = 1; break; }
			case 4: {dir = 3; break; }
		}
		q.push({x,y,speed,dir,size});
	}
	f();
	cout << ans;
}