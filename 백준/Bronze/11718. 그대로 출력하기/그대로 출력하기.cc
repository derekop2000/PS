#include <iostream>
#include<string.h>
#include<sstream>
#include<vector>
using namespace std;

int main()
{
    string s;
    while(getline(cin,s,' ') )
    {
        cout << s<<' ';
    }
}
