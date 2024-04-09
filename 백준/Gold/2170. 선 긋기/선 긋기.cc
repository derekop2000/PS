#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

char buf[1 << 17];

inline char read()
{
    static int idx = 1 << 17;
    if (idx == 1 << 17)
    {
        fread(buf, 1, 1 << 17, stdin);
        idx = 0;
    }
    return buf[idx++];
}
inline int readInt()
{
    int sum = 0;
    bool flg = 1;
    char now = read();

    while (now == 10 || now == 32) now = read();
    if (now == '-') flg = 0, now = read();
    while (now >= 48 && now <= 57)
    {
        sum = sum * 10 + now - 48;
        now = read();
    }
    return flg ? sum : -sum;
}

int main() {
    int n, ans = 0;
    pair<int, int> arr[1000005];
    int curs = -1000000000, cure = -1000000000;
    n = readInt();
    for (int i = 0; i < n; i++) {
        arr[i].first = readInt();
        arr[i].second = readInt();
    }
    sort(arr, arr + n);
    for (int i = 0; i < n; i++) {
        int s = arr[i].first, e = arr[i].second;
        if (curs <= s && e <= cure) { continue; }
        else if (s <= cure && cure <= e) {
            ans += e - cure;
            cure = e;
        }
        else if (cure <= s) {
            ans += e - s;
            curs = s; cure = e;
        }
    }
    cout << ans << "\n";
    return 0;
}