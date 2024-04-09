#include<iostream>
#include<string>
using namespace std;
bool f(int i,int j,string s,int len)
{
    for(;i<len;)
    {
        if(s[i]!=s[j])
            return false;
        i++;
        j--;
    }
    return true;
}
int main()
{
    int n;
    cin >> n;
    string str;
    while(n--)
    {
        cin >> str;
        int totalLen = str.length()-1;
        int len = str.length()/2;
        bool isP = true;
        bool oneMoreChance = true;
        for(int i=0;i<len;i++)
        {
            if(str[i]!=str[totalLen-i])
            {
                if(oneMoreChance&&( f(i+1,totalLen-i,str,len+1 )||f(i,totalLen-i-1,str,len )))
                {
                    oneMoreChance =false;
                    break;
                }
                else
                {
                    isP=false;
                    break;
                }
            }

        }
        if(isP&&oneMoreChance)cout<<0<<'\n';
        else if(isP)cout <<1<<'\n';
        else cout <<2<<'\n';

    }
}
