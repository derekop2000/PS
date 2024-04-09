#include<iostream>
using namespace std;
int* arr;
int n;
bool isFinish;
void dfs(int floor);
int isBad(int floor);
int isSame(int q,int j,int floor);
int main()
{
    cin >> n;
    arr = new int[n+1];
    arr[1]=1;
    dfs(1);
    for(int i=1;i<=n;i++)
        cout<<arr[i];
    delete[] arr;
}
void dfs(int floor)
{
    // 지금이 끝이면 나가야함
    if(floor==n){isFinish=true;return;}
    int last = arr[floor];
    for(int i=1;i<4;i++)
    {
        if(isFinish)break;
        if(i!=last)
        {
            arr[floor+1]=i;
            if(isBad(floor+1))continue;
            dfs(floor+1);
        }
    }
}
int isBad(int floor)
{
    if(floor <4)return 0;
    for(int i=4;i<=floor;i+=2)
    {
        int half = i/2;
        int j =floor-half+1;
        int q = j-half;
        if(isSame(q,j,floor))return 1;
    }
    return 0;
}
int isSame(int q,int j,int floor)
{
    for(;j<=floor;)
        if(arr[q++]!=arr[j++])return 0;
    return 1;
}
