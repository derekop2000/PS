#include<iostream>
using namespace std;
int arr[600][600];
int main()
{
    int h,w,x,y;
    cin >>h>>w>>x>>y;
    for(int i=0;i<h+x;i++)
        for(int j=0;j<w+y;j++)
            cin >> arr[i][j];

    for(int i=x;i<h;i++)
        for(int j=y;j<w;j++)
        {
            arr[i][j]-=arr[i-x][j-y];
        }

    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        cout << arr[i][j]<<' ';cout <<'\n';}
}
