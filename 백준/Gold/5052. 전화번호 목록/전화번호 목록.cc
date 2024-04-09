#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
int main()
{
    int t;
    cin >> t;
    vector<string> arr;
    while(t--)
    {
        bool isNO =false;
        int n;
        cin >> n;
        arr.clear();
        for(int i=0;i<n;i++)
        {
            string str;
            cin >> str;
            arr.push_back(str);
        }
        sort(arr.begin(),arr.end());
        for(int i=0;i<n-1;i++)
        {
            int a,b;
            a=arr[i].size();
            b=arr[i+1].size();
            if(a>b)
                continue;
            if(arr[i+1].substr(0,a)==arr[i])
            {
                isNO =true;
                break;
            }
        }
        if(isNO)
            cout<< "NO\n";
        else cout <<"YES\n";

    }
}
