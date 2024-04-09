#include <iostream>
#include<vector>
#include<queue>
#include<tuple>
using namespace std;

int n, k;
vector<vector<int>> arr;
vector<int> v;
int ans = 2147483647;

int main()
{
    cin >> n >> k;
    arr.resize(n, vector<int>(3));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 3; j++)
            cin >> arr[i][j];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            for (int q = 0; q < n; q++)
            {
                int cnt = 0;
                for (int p = 0; p < n; p++)
                {
                    if (arr[i][0] >= arr[p][0] && arr[j][1] >= arr[p][1] && arr[q][2] >= arr[p][2])
                        cnt++;
                }
                if (cnt >= k)
                {
                    ans = min(ans, arr[i][0] + arr[j][1] + arr[q][2]);
                }
            }
    cout << ans;
}