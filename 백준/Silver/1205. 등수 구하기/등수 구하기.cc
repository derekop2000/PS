#include<iostream>
#include<vector>
using namespace std;

int main()
{
   int n,score,p,cnt=1,temp;
    int same=0;
   cin >> n>> score >>p;
   for(int i=0;i<n;i++)
   {
       cin >> temp;
       if(temp > score)cnt++;
       if(temp==score)same++;
   }
   if(cnt+same > p)cout << "-1";
   else cout << cnt;
}
