#include<iostream>
#include<algorithm>
using namespace std;
int a[51];
int b[51];
int main()
{
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    for(int i=0;i<n;i++)
    {
        cin >> b[i];
    }
    sort(a,a+n);
    sort(b,b+n,greater<int>());
    int sum =0;
    for(int i=0;i<n;i++)
        {
            sum += a[i]*b[i];
        }
    cout << sum;
}
