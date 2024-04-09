#include<iostream>
#include<algorithm>
#include<memory>
#include<vector>
using namespace std;
bool f(int &a,int &b)
{
    return a>b;
}
int main()
{
    int n,k;
    cin >> n>>k;
    unique_ptr<int[]> arr = make_unique<int[]>(n);
    for(int i=0;i<n;i++)
        cin >> arr[i];
    sort(arr.get(),arr.get()+n);
    int ans = arr[n-1]-arr[0];
    vector<int> v;
    for(int i=1;i<n;i++)
        v.push_back(arr[i]-arr[i-1]);
    sort(v.begin(),v.end(),f);
    for(int i=0;i<k-1&&i<v.size();i++)
    {
        ans-=v[i];
    }
    cout << ans;
}
