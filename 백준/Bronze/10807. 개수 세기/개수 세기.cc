#include<iostream>
using namespace std;
int arr[100];
int main()
{
    int n,goal;
    cin >> n;
    int cnt=0;
    for(int i=0;i<n;i++)
        cin >> arr[i];
        cin >> goal;
        for(int i=0;i<n;i++)
            if(arr[i]==goal)cnt++;
            cout << cnt;

}
