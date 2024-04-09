#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int n = s.size();
    int ans=n;
    int cnt_a=0;
    for(int i=0;i<n;i++)
        if(s[i]=='a')cnt_a++;
    for(int i=0;i<n;i++)
    {
        int temp =cnt_a;
        int temp2=0;
        int j=i;
        while(temp--)
        {
            if(s[j]=='b')temp2++;
            j = (j+1)%n;
        }
        ans = min(ans,temp2);
    }
    cout << ans;
}
