#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int a,b;
vector<int> v;
int main()
{
    cin >> a >>b;
    int sum=0;
    int cnt=0;
    v.resize(a);
    for(int i=0;i<a;i++)
        cin >> v[i];
    int index =-1;

    while(index<a-1)
    {
        if(sum+v[index+1]>b)
            break;
        index++;
        sum+=v[index];
    }
    if(sum==b)cnt++;

    for(int i=1;i<a;i++)
    {
        sum-=v[i-1];
        while(index<a-1)
        {
            if(sum+v[index+1]>b)
                break;
            index++;
            sum+=v[index];
        }
        if(sum==b)cnt++;
    }
    cout << cnt;
}
