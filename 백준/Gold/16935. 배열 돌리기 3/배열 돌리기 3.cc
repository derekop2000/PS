#include <iostream>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <queue>
using namespace std;

int n, m, r;
vector<vector<int>> arr;
void f(int case_num)
{
    switch (case_num)
    {
        case 1:
        {
            int t = n / 2;
            for (int i = 0; i < t; i++)
                for (int j = 0; j < m; j++)
                {
                    swap(arr[i][j], arr[n - 1 - i][j]);
                }
            break;
        }
        case 2:
        {
            int t = m / 2;
            for (int i = 0; i < n; i++)
                for (int j = 0; j < t; j++)
                {
                    swap(arr[i][j], arr[i][m-1-j]);
                }
            break;
        }
        case 3:
        {
            vector<vector<int>> temp(m, vector<int>(n));
            int temp_index = 0;
            for(int j = 0; j < m; j++)
                for (int i = n - 1; i >= 0; i--)
                {
                    temp[temp_index / n][temp_index % n] = arr[i][j];
                    temp_index++;
                }
            arr = temp;
            swap(n, m);
            break;
        }
        case 4:
        {
            vector<vector<int>> temp(m, vector<int>(n));
            int temp_index = 0;
            for (int j = m-1; j >=0; j--)
                for (int i = 0; i <n; i++)
                {
                    temp[temp_index / n][temp_index % n] = arr[i][j];
                    temp_index++;
                }
            arr = temp;
            swap(n, m);
            break;
        }
        case 5:
        {
            vector<vector<int>> temp(n, vector<int>(m));
            
            for(int i=0;i<n/2;i++)
                for (int j = 0; j < m/2; j++)
                {
                    temp[i][j+m/2] = arr[i][j];
                }
            for (int i = 0; i < n / 2; i++)
                for (int j = m/2; j < m; j++)
                {
                    temp[i+n/2][j] = arr[i][j];
                }
            for (int i = n/2; i < n; i++)
                for (int j = m/2; j < m; j++)
                {
                    temp[i][j-m/2] = arr[i][j];
                }
            for (int i = n/2; i < n; i++)
                for (int j = 0; j < m / 2; j++)
                {
                    temp[i-n/2][j] = arr[i][j];
                }
            arr = temp;
            break;
        }
        case 6:
        {
            vector<vector<int>> temp(n, vector<int>(m));

            for (int i = 0; i < n / 2; i++)
                for (int j = 0; j < m / 2; j++)
                {
                    temp[i+n/2][j] = arr[i][j];
                }
            for (int i = 0; i < n / 2; i++)
                for (int j = m / 2; j < m; j++)
                {
                    temp[i][j-m/2] = arr[i][j];
                }
            for (int i = n / 2; i < n; i++)
                for (int j = m / 2; j < m; j++)
                {
                    temp[i-n/2][j] = arr[i][j];
                }
            for (int i = n / 2; i < n; i++)
                for (int j = 0; j < m / 2; j++)
                {
                    temp[i][j+m/2] = arr[i][j];
                }
            arr = temp;
            break;
        }
    }
    
}
int main()
{
    cin >> n >> m >> r;
    arr.resize(n, vector<int>(m));
    for(int i=0;i<n;i++)
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    for (int i = 0; i < r; i++)
    {
        int temp;
        cin >> temp;
        f(temp);
    }
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            cout << arr[i][j] << " ";
        }cout << "\n";
    }
}
