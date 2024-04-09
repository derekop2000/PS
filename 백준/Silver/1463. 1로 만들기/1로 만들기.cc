#include<iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int* arr = new int[n+1];
    arr[1]=0;
    for(int i=2;i<=n;i++)
    {
        arr[i] = arr[i-1]+1;
        if(i%2==0) arr[i]= (arr[i/2]+1 < arr[i])? arr[i/2]+1:arr[i];
        if(i%3==0) arr[i]= (arr[i/3]+1 < arr[i])? arr[i/3]+1:arr[i];
    }
    cout << arr[n];
    delete[] arr;
}
