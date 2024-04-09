#include<iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,temp;
    cin >> n;
    int* arr= new int[n];
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }
    int b,c;
    long long int cnt=0;
    cin >> b >> c;
    for(int i=0;i<n;i++)
    {
        cnt++;
        arr[i]-=b;
        if(arr[i]>0)
        {
            cnt+=(arr[i]/c);
            if(arr[i]%c!=0)
                cnt++;
        }
    }
    cout<< cnt;
    delete[] arr;
}
