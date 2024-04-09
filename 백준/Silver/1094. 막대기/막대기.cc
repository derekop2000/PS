#include<iostream>
using namespace std;
int main()
{
    int total = 64;
    int smallest = 64;
    int cnt =1;
    int goal;
    cin >> goal;
    while(total!=goal)
    {
        if(total - smallest/2 >= goal)
        {
            total -= smallest/2;
            smallest/=2;
        }
        else
        {
            smallest/=2;
            cnt++;
        }
    }
    cout << cnt;
}
