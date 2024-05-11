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

int arr[19][19];
int dir[4][2] = { {0,1},{1,0},{1,1},{-1,1} };
int whoWin = 0;
bool condition;
vector<pair<int, int>> v;
void check(int y,int x,int d, int floor,int who)
{
    
    int y_ = y - dir[d][0];
    int x_ = x - dir[d][1];
    if (0 <= y_ && y_ < 19 && 0 <= x_ && x_ < 19 && arr[y_][x_] == who&& condition == false)
    {
        return;
    }
    condition = true;
    int yy = y + dir[d][0];
    int xx = x + dir[d][1];
    if (0 <= yy && yy < 19 && 0 <= xx && xx < 19 && arr[yy][xx] == who)
    {
        check(yy, xx, d, floor + 1, who);
        if (whoWin != 0 && v.size() <5)
            v.push_back({ y,x });
    }
    else if (floor == 5)
    {
        v.clear();
        whoWin = who;
        v.push_back({y,x});
    }
}
int main()
{
    for (int i = 0; i < 19; i++)
        for (int j = 0; j < 19; j++)
            cin >> arr[i][j];
        for (int j = 18; j >= 0; j--)
            for (int i = 18; i >=0 ; i--)
            {
                if (arr[i][j] != 0)
                {
                    for (int d = 0; d < 4; d++)
                    {
                        condition = false;
                        check(i, j, d, 1, arr[i][j]);
                    }
                }
            }
    pair<int, int> ans = {18,18};
    if (whoWin != 0)
    {
        for (auto temp : v)
        {
            if (temp.second < ans.second)
                ans = temp;
            else if (temp.second == ans.second && temp.first < ans.first)
                ans = temp;
        }
    }
    if (whoWin == 0)
        cout << "0";
    else
    {
        cout << whoWin << "\n" << ans.first+1 << " " << ans.second+1;
    }

}
