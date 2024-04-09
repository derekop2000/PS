#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int a,b,ans=0;
int top=0;
bool directTop=true;
vector<int> v;
int abs_(int a)
{
    if(a<0)return a*-1;
    else return a;
}
int main()
{
    cin >> a >> b;
    vector<int> PlusV,MinusV;
    PlusV.reserve(a);
    MinusV.reserve(a);


    int temp;
    for(int i=0;i<a;i++)
    {
        cin >> temp;
        if(abs_(temp)>abs_(top) )
            {top=temp;}
        if(temp>0)
            PlusV.push_back(temp);
        else MinusV.push_back(temp);
    }

    if(top>0)directTop=true;
    else directTop=false;

    sort(PlusV.begin(),PlusV.end());
    sort(MinusV.begin(),MinusV.end(),greater<int>() );


    if(directTop)
    {
        ans += PlusV.back();
        for(int i=0;i<b;i++)
            PlusV.pop_back();
    }
    else
    {
        ans += abs_(MinusV.back());
        for(int i=0;i<b;i++)
            MinusV.pop_back();
    }

    int i;
    for(i=PlusV.size()-1;i>=0;i-=b)
    {
        ans+=PlusV[i]*2;
    }
    for(i=MinusV.size()-1;i>=0;i-=b)
    {
        ans+=abs_(MinusV[i])*2;
    }

    cout << ans;
}
