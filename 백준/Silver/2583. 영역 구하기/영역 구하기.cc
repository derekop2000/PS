#include<iostream>
#include<algorithm>
using namespace std;
int **arr;
int m,n,cnt;
void dfs(int row,int column,int* area);
int main()
{
    int k;
    cin >> m >> n >> k;

    int area[100];
    for(int i=0;i<100;i++)
        area[i]=0;

    arr = new int*[m];
    for(int i=0;i<m;i++)
        arr[i] = new int[n];

    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            arr[i][j]=0;
    int a,b,c,d,row1,row2,column1,column2;
    for(int i=0;i<k;i++)
    {
        cin >> a>> b >>c >>d;
        row1 =m-d;
        row2 =m-b;
        column1 = a;
        column2 = c;
        for(int j=row1;j<row2;j++)
            for(int q=column1;q<column2;q++)
                arr[j][q]=1;
    }
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
        {
            if(arr[i][j]==0)
            {
                cnt++;
                dfs(i,j,area);
            }
        }
    sort(area,area+cnt);
    cout <<cnt<<'\n';
    for(int i=0;i<cnt;i++)
        cout << area[i]<<' ';
    for(int i=0;i<m;i++)
        delete[] arr[i];
    delete[] arr;
}
void dfs(int row,int column,int* area)
{
    arr[row][column]=1;
    area[cnt-1]++;
    if(row>0 && !arr[row-1][column])dfs(row-1,column,area);
    if(column+1<n && !arr[row][column+1])dfs(row,column+1,area);
    if(row+1<m && !arr[row+1][column])dfs(row+1,column,area);
    if(column>0 && !arr[row][column-1])dfs(row,column-1,area);
}
