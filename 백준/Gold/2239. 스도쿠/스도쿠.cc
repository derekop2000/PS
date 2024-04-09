#include <iostream>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <queue>
using namespace std;

int arr[9][9];
pair<int, int> where_am_i(int i,int j)
{
    pair<int, int> ans;
    if (i < 3)ans.first = 0;
    else if (i < 6)ans.first = 3;
    else ans.first = 6;

    if (j < 3)ans.second = 0;
    else if (j < 6)ans.second = 3;
    else ans.second = 6;

    return ans;
}
bool can_set(int i, int j, int num)
{
    for (int q = 0; q < 9; q++)
    {
        if (arr[q][j] == num)return false;
    }
    for (int q = 0; q < 9; q++)
    {
        if (arr[i][q] == num)return false;
    }
    pair<int, int> sector_pos = where_am_i(i, j);
    for(int ii=0;ii<3;ii++)
        for (int jj = 0; jj < 3; jj++)
        {
            if (arr[sector_pos.first + ii][sector_pos.second + jj] == num)return false;
        }
    return true;
}
bool ans = false;
void dfs(int i,int j,int num)
{
    arr[i][j] = num;
    if (i == 8 && j == 8)
    {
        ans = true;
        return;
    }
    int ii = i;
    int jj = j;
    for (; ii < 9; ii++)
    {
        for (; jj < 9; jj++)
        {
            if (ii == 8 && jj == 8 && arr[ii][jj])
            {
                ans = true; return;
            }
            if (arr[ii][jj])continue;
            for (int q = 1; q <= 9; q++)
            {
                if (can_set(ii, jj, q))
                {
                    dfs(ii, jj, q);
                }
            }
            if (arr[ii][jj] == 0)
            {
                arr[i][j] = 0; return;
            }
        }jj = 0;
    }
    if (ans == false)
        arr[i][j] = 0;
}
int main()
{
    cin.tie(0);
	ios::sync_with_stdio(false);
    pair<int, int> first_pos;
    first_pos.first = -1;
    for(int i=0;i<9;i++)
        for (int j = 0; j < 9; j++)
        {
            char temp;
            cin >> temp;
            arr[i][j] = temp - '0';
            if (first_pos.first == -1 && arr[i][j] == 0)
            {
                first_pos.first = i;
                first_pos.second = j;
            }
        }
    for (int i = 1; i <= 9; i++)
    {
        if(can_set(first_pos.first, first_pos.second, i))
            dfs(first_pos.first, first_pos.second, i);
    }
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << arr[i][j];
        }cout << "\n";
    }
}
