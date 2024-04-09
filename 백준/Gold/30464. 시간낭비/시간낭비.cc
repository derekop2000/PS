#include<bits/stdc++.h>
#define N 200001
using namespace std;
 
int n, a[N], dp[N][2][3];
int f(int u, int p, int q)
{
    if (u < 1 || u > n) return -1e9;
    if (u == n) return 0;
    int& t(dp[u][p][q]);
    if (!~t)
    {
        t = -1e9;
        int dis(a[u] * (p ? -1 : 1));
 
        t = f(u + dis, p, q) + 1;
        if (q < 2)
            t = max(t, f(u - dis, p ^ 1, q + 1) + 1);
    }
    return t;
}
int main()
{
    cin >> n;
    for (int i(1); i <= n; scanf("%d", &a[i++]));
 
    memset(dp, -1, sizeof dp);
    int ans(f(1, 0, 0));
    cout << (ans > 0 ? ans : -1);
}
