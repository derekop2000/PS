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

vector<int> parent;
int findParent(int a)
{
    if (a == parent[a])
        return a;
    return parent[a] = findParent(parent[a]);
}
void myUnion(int a, int b)
{
    parent[findParent(b)] = findParent(a);
}
bool isUnion(int a,int b)
{
    return findParent(a) == findParent(b);
}

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> candy(n);
    parent.resize(n);
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        cin >> candy[i];
    }
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        myUnion(a - 1, b - 1);
    }
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
    {
        int temp = findParent(i);
        v[temp].first++;
        v[temp].second += candy[i];
    }
    k--;
    vector<int> dp(k + 1);

    for (int i = 0; i < n; i++)
    {
        if (v[i].first == 0)continue;
        int kidCnt = v[i].first;
        int candyCnt = v[i].second;
        for (int j = k; j >= kidCnt; j--)
        {
            dp[j] = max(dp[j - kidCnt] + candyCnt, dp[j]);
        }
    }
    cout << dp[k];
}
