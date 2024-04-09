#include <iostream>
#include <algorithm>
#include <cmath>
#include <sstream>
using namespace std;


int main()
{
    long n, k;
    cin >> n >> k;
    long a = 1, b = 1;
    int ans;
    bool fail = true;
    while (true)
    {
        long temp = a * 9 * b;
        if (k <= temp)
        {
            long temp2 = k / b;
            long temp3 = k % b;
            long temp4 = temp2 + a;
            temp2 += a;
            if (temp3 > 0)
            {
                temp3--;
            }
            else
            {
                temp2--;
                temp3 = to_string(temp2).size()-1;
            }
            stringstream ss;
            ss << temp2;
            string str;
            ss >> str;
            ans = str[temp3];
            if (n < temp2)fail = false;
            break;
        }
        else
        {
            //n -= temp;
            k -= temp;
            a *= 10;
            b++;
        }
    }
    if (fail)
        cout << (char)ans;
    else cout << "-1";
    return 0;
}
