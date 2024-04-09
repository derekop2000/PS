#include<iostream>
#include<vector>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
    int t;
    cin >>t;

    while(t--)
    {
        int n;
        cin >> n;
        vector<int> v;
        v.resize(n);
        for(int i=0;i<n;i++)
            cin >> v[i];
        int big=v[n-1];
        long long int sum=0;
        for(int i=n-2;i>=0;i--)
        {
            if(v[i]<big)
                sum+=(big-v[i]);
            else big=v[i];
        }
        cout << sum<<'\n';
    }
}
