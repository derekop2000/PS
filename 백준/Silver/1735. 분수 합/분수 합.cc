#include<iostream>
#include<vector>
using namespace std;
int f(int a,int b)
{
    if(b>a){a+=b;b=a-b;a=a-b;}
    if(!b)return a;
    return f(a-(a/b)*b,b);
}
int main()
{

    int a,b,c,d;
    cin >> a>> b>>c>>d;
    a=a*d+b*c;
    b=b*d;
    c=f(a,b);
    cout << a/c<<' '<<b/c;
}
