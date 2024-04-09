#include<iostream>
#include<vector>
#include<memory>
using namespace std;
int dir1[] = {-1,0,1,0};
int dir2[] = {0,1,0,-1};
unique_ptr<unique_ptr<int[]>[]> arr;
int n, m;
int dir;
int ans = 0;
pair<int, int> pos;
void f()
{
	while (1)
	{
		if (arr[pos.first][pos.second] == 0)
		{
			arr[pos.first][pos.second] = 2;
			ans++;
		}
		bool empty = false;
		for (int i = 0; i < 4; i++)
		{
			int checkY = pos.first + dir1[i];
			int checkX = pos.second + dir2[i];
			if (0 <= checkY && checkY < n && 0 <= checkX && checkX < m && arr[checkY][checkX] == 0)
				empty = true;
		}
		if (!empty)
		{
			int checkY = pos.first + dir1[(dir + 2) % 4];
			int checkX = pos.second + dir2[(dir + 2) % 4];
			if (0 <= checkY && checkY < n && 0 <= checkX && checkX < m && arr[checkY][checkX] != 1)
			{
				pos.first = checkY;
				pos.second = checkX;
				continue;
			}
			else
			{
				return;
			}
		}
		else
		{
			for (int i = 1; i < 5; i++)
			{
				int checkY = pos.first + dir1[(dir + 4-i) % 4];
				int checkX = pos.second + dir2[(dir + 4-i) % 4];
				if (0 <= checkY && checkY < n && 0 <= checkX && checkX < m && arr[checkY][checkX] == 0)
				{
					dir = (dir + 4 - i) % 4;
					pos.first = checkY;
					pos.second = checkX;
					break;
				}
			}
		}
	}
}
int main()
{
	cin >> n >> m;
	cin >> pos.first >> pos.second >> dir;
	arr = make_unique<unique_ptr<int[]>[]>(n);
	for (int i = 0; i < n; i++)
		arr[i] = make_unique<int[]>(m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];
	f();
	cout << ans;
}