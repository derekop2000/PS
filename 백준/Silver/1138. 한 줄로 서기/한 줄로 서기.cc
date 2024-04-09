#include<iostream>
#include<string>
using namespace std;
int a[11];
int main()
{
    int n;
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        int temp;
        cin >> temp;
        int cnt=temp;

        for(int j=1;j<=n;j++)
        {
            if(a[j])continue;
            if(cnt)
            {
                cnt--;
                continue;
            }
            else
            {
                a[j]=i;break;
            }
        }
    }
    for(int i=1;i<=n;i++)
        cout<<a[i]<<' ';
}
