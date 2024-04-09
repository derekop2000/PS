#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
    int a,b,t;
    cin >> a>>b;
    char* v1 = new char[a+b+1];
    char* v2 = new char[a+b+1];
    for(int i=a-1;i>=0;i--)
        cin >> v1[i];
    for(int i=a;i<a+b;i++)
        cin >> v1[i];
    for(int i=0;i<a+b;i++)
        v2[i]=v1[i];
    cin >> t;
    int temp =t;
    for(int i=a-1;i>=0;i--)
    {
        if(!temp)break;
        v2[min(i+temp,i+b)]=v1[i];
        temp--;

    }

    temp =t;
    for(int i=a;i<a+b;i++)
    {
        if(!temp)break;
        v2[max(i-temp,i-a)]=v1[i];
        temp--;

    }
    for(int i=0;i<a+b;i++)
        cout << v2[i];
    delete[] v1;
    delete[] v2;
}
