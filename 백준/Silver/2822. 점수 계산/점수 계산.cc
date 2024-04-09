#include<iostream>
#include<algorithm>
using namespace std;
int arr[100000];
bool compare(pair<int,int> &a,pair<int,int> &b)
{
    return a.second < b.second;
}
int main()
{
    pair<int,int> arr[9];
    for(int i=1;i<9;i++)
    {
        cin >> arr[i].first;
        arr[i].second = i;
    }
    sort(arr+1,arr+9);
    sort(arr+4,arr+9,compare);
    int sum=0;
    for(int i=4;i<9;i++)
        sum+=arr[i].first;
    cout << sum<<'\n';
    for(int i=4;i<9;i++)
        cout << arr[i].second<<' ';
}
