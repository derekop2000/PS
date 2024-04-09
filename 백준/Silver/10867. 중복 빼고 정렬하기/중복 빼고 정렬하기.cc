#include<iostream>
#include<algorithm>
using namespace std;
int arr[100000];
int main()
{
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> arr[i];
    sort(arr,arr+n,less<int>());
    int q=-1;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==q)continue;
        cout << arr[i]<<' ';
        q=arr[i];
    }
}
