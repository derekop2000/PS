#include<iostream>
#include<string>
using namespace std;
bool isAEIOU(char a)
{
    if(a=='a'||a=='e'||a=='i'||a=='o'||a=='u')
        return true;
    else return false;
}
int main()
{
   string str;

   while(1)
   {
       cin >> str;
       if(str.compare("end")==0)
        break;
       bool isAEIOU_ = false;
       bool isNOT =false;
       if(isAEIOU(str[0]))
            isAEIOU_=true;
       for(int i=1;i<str.size();i++)
       {
            if(isAEIOU(str[i]))
                isAEIOU_=true;
            if( !(str[i]=='e'||str[i]=='o')&&str[i]==str[i-1] )
            {
                isNOT=true;
                break;
            }
            if(i>1&& ((isAEIOU(str[i])&&isAEIOU(str[i-1])&&isAEIOU(str[i-2]))||(!isAEIOU(str[i])&&!isAEIOU(str[i-1])&&!isAEIOU(str[i-2]))) )
            {
                isNOT=true;
                break;
            }
       }
       if(!isNOT&&isAEIOU_)cout << '<'<<str<<'>'<<" is acceptable.\n";
       else cout << '<'<<str<<'>'<<" is not acceptable.\n";
   }
}
