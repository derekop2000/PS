#include <iostream>
#include<string.h>
#include<sstream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int n;
int ans=500000;
int red,blue;
vector<char> v;
void f(bool FirstRed,bool MoveRed)
{
    int v_size = v.size();
    int temp;
    int ballCnt;
    bool allPass = true;
    if(MoveRed){ballCnt=red;temp=red;}else {temp=blue;ballCnt=blue;}
    if(FirstRed)
    {
        if(MoveRed)
        {
            for(int i=0;i<ballCnt;i++)
            {
                if(v[i]=='B')
                {
                    temp-=i;
                    allPass=false;
                    break;
                }
            }
        }
        else
        {
            for(int i=v_size-1;i>=v_size-ballCnt;i--)
            {
                if(v[i]=='R')
                {
                    temp-=(v_size-(i+1));
                    allPass=false;
                    break;
                }
            }
        }
    }
    else
    {
        if(MoveRed)
        {
            for(int i=v_size-1;i>=v_size-ballCnt;i--)
            {
                if(v[i]=='B')
                {
                    temp-=(v_size-(i+1));
                    allPass=false;
                    break;
                }
            }
        }
        else
        {
            for(int i=0;i<ballCnt;i++)
            {
                if(v[i]=='R')
                {
                    temp-=i;
                    allPass=false;
                    break;
                }
            }
        }
    }
    if(allPass)temp=0;
    if(temp<ans)ans=temp;
}
int main()
{
    cin >>n;
    v.resize(n);
    for(int i=0;i<n;i++)
    {
        cin >> v[i];
        if(v[i]=='R')red++;
        else blue++;
    }
    f(true,true);
    f(true,false);
    f(false,false);
    f(false,true);
    cout << ans;
}
