#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int> v2;
int v2_size;
bool f(int find_data,int s_index)
{
    int s=s_index;int e=v2_size-1;
    int mid;
    while(s<=e)
    {
        mid = (s+e)/2;
        if(v2[mid]==find_data)return true;
        if(v2[mid]<find_data)s=mid+1;
        else e=mid-1;
    }
    return false;
}
int main()
{
    vector<bool> v(1000000,true);
    for(int i=2;i<1000000;i++)
    {
        if(v[i])
        for(int j=i+i;j<1000000;j+=i)
        {
            v[j]=false;
        }
    }
    v[0]=false;
    v[1]=false;

    for(int i=2;i<1000000;i++)
        if(v[i])v2.push_back(i);
    v2_size=v2.size();
    int t;
    cin >> t;
    while(t--)
    {
        int goal;
        cin >> goal;

        int ans=0;
        for(int i=0;i<v2_size;i++)
        {
            if( f(goal-v2[i],i) ){ans++;}
        }
        cout <<ans<<'\n';
    }
}
