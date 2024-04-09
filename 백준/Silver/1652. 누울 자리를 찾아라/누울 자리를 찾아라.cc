#include<iostream>
using namespace std;
char** arr;
int main()
{
    int n;
    char c;
    cin >> n;
    arr = new char*[n];
    for(int i=0;i<n;i++)
    {
        arr[i] = new char[n];
        for(int j=0;j<n;j++)
        {
            cin >> c;
            if(c=='.')arr[i][j]=1;else arr[i][j]=0;
        }
    }
    if(n==1){cout <<"0 0";return 0;}
    int rowCount=0;
    int columnCount =0;
    for(int i=0;i<n;i++)
        for(int j=0;j<n-1;j++)
        {
            if(arr[i][j]&&arr[i][j+1])
            {
                rowCount++;
                while(arr[i][j])
                {
                    j++;
                    if(j==n-1)break;
                }
            }
        }
    for(int i=0;i<n;i++)
        for(int j=0;j<n-1;j++)
        {
            if(arr[j][i]&&arr[j+1][i])
            {
                columnCount++;
                while(arr[j][i])
                {
                    j++;
                    if(j==n-1)break;
                }
            }
        }
    cout << rowCount<<' '<<columnCount;

    for(int i=0;i<n;i++)
        delete[] arr[i];
    delete[] arr;
}
