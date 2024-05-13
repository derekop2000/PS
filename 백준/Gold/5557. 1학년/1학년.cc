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

int main()
{
    int n;
    cin >> n;
    vector<vector<unsigned long long int>> v(n-1,vector<unsigned long long int>(21,0));
    int temp;
    cin >> temp;
    v[0][temp] = 1;
    for (int i = 0; i < n - 2; i++)
    {
        int index = i + 1;
        cin >> temp;
        for (int j = 0; j < 21; j++)
        {
            if (v[index - 1][j])
            {
                if (0 <= j + temp && j + temp <= 20)
                {
                    v[index][j + temp] += v[index - 1][j];
                }
                if (0 <= j - temp && j - temp <= 20)
                {
                    v[index][j - temp] += v[index - 1][j];
                }

            }
        }
    }
    int last;
    cin >> last;
    cout << v[n - 2][last];
}
