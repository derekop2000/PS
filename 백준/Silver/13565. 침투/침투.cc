#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> arr;
int m, n;
bool ans = false;
int dir1[] = {-1,0,1,0};
int dir2[] = {0,1,0,-1};
void f(int a,int b)
{
	if (ans)return;
	if (a == m - 1)ans = true;
	for (int i = 0; i < 4; i++)
	{
		int aa = a + dir1[i];
		int bb = b + dir2[i];
		if (0 <= aa && aa < m && 0 <= bb && bb < n && arr[aa][bb] == 0)
		{
			arr[aa][bb] = 1;
			f(aa, bb);
		}
	}
}
int main()
{
	cin >> m >> n;
	arr.resize(m, vector<int>(n));
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			char temp_char;
			cin >> temp_char;
			if (temp_char == '0')
				arr[i][j] = 0;
			else arr[i][j] = 1;
		}

	for (int i = 0; i < n; i++)
	{
		if (arr[0][i] == 0)f(0, i);
	}
	if (ans)cout << "YES";
	else cout << "NO";
}
