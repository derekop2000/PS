#include<iostream>
#include<algorithm>
using namespace std;
pair<int,int> arr[100001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t,n;
    cin >>t;
    while(t--)
    {
        cin >> n;
        int sum=1;
        for(int i=0;i<n;i++)
        {
            cin >> arr[i].first >> arr[i].second;
        }
        sort(arr,arr+n);
        int m = arr[0].second;
        for(int i=1;i<n;i++)
        {
            if(arr[i].second < m)
            {
                sum++;
                m = arr[i].second;
            }
        }
        cout << sum <<'\n';
    }

}
