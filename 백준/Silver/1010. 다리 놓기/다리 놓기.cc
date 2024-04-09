#include<iostream>
using namespace std;
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--)
    {
    int a,b;
    cin >> a>> b;
    long long int sum=1;
    int temp=1;
    for(int i=0;i<a;i++)
    {
        sum*=b--;
        sum/=temp++;
    }
    cout << sum<<'\n';
    }
}
