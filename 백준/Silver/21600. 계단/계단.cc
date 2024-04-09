#include <bits/stdc++.h>
using namespace std;
int a[100000], dp[100000];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m=1;
    cin >> n;
    dp[0]=1;
    for(int i=0; i<n; i++) {
        cin >> a[i];
        if(i) {
            if(a[i]>dp[i-1]) dp[i]=dp[i-1]+1;
            else dp[i]=a[i];
        }
        m=max(m, dp[i]); //최대 계단 구하기
    }
    cout << m;
}