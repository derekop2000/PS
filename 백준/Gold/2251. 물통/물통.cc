#include <iostream>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <queue>
#include <map>
using namespace std;
int a, b, c;
vector<vector<vector<bool>>> arr;
map<int, int> ans;
void f(int a1,int b1,int c1)
{
    if (a1 == 0)
    {
        ans.insert({ c1,c1 });
    }
    arr[a1][b1][c1] = true;
    if (a1)
    {
        int temp = min(b - b1, a1);
        if (arr[a1 - temp][b1 + temp][c1] == false)
            f(a1 - temp, b1 + temp, c1);
        temp = min(c - c1, a1);
        if (arr[a1 - temp][b1][c1+temp] == false)
            f(a1 - temp, b1, c1+temp);
    }
    if (b1)
    {
        int temp = min(a - a1, b1);
        if (arr[a1 + temp][b1 - temp][c1] == false)
            f(a1 + temp, b1 - temp, c1);
        temp = min(c - c1, b1);
        if (arr[a1][b1-temp][c1 + temp] == false)
            f(a1, b1-temp, c1 + temp);
    }
    if (c1)
    {
        int temp = min(a- a1, c1);
        if (arr[a1 + temp][b1][c1-temp] == false)
            f(a1 + temp, b1, c1-temp);
        temp = min(b - b1, c1);
        if (arr[a1][b1 + temp][c1 - temp] == false)
            f(a1, b1 + temp, c1 - temp);
    }
}
int main()
{
    cin >> a >> b >> c;
    arr.resize(201, vector<vector<bool>>(201, vector<bool>(201, false)));
    f(0, 0, c);
    for(auto x : ans)
    {
        cout << x.first<<" ";
    }
}
