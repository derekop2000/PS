#include<iostream>
using namespace std;
int main()
{
    int n,t;
    cin >> t;
    int* arr = new int[11];
    arr[0]=0;
    arr[1]=1;
    arr[2]=2;
    arr[3]=4;
    for(int i=4;i<=11;i++)
    {
        arr[i] = arr[i-1]+arr[i-2]+arr[i-3];
    }
    for(int i=0;i<t;i++)
    {
        cin >> n;
        cout << arr[n]<<'\n';
    }
    delete[] arr;
}
