#include <iostream>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <queue>
using namespace std;

vector<int> arr;
vector<int> visit;
int _ans=100;
void f(int num,int cnt)
{
    if (num == 100)
    {
        _ans = min(_ans,cnt);
        return;
    }
    if (arr[num])num = arr[num];
    for (int i = 1; i <= 6; i++)
    {
        if (num + i > 100)break;
        if (visit[num + i] > cnt + 1)
        {
            visit[num + i] = cnt + 1;
            f(num + i, cnt + 1);
        }

    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    arr.resize(101,0);
    visit.resize(101, 100);
    for (int i = 0; i < n + m; i++)
    {
        int a, b;
        cin >> a >> b;
        arr[a] = b;
    }
    visit[1] = 0;
    f(1, 0);
    cout << _ans;
}
