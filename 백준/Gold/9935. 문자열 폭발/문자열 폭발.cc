#include <iostream>
#include<sstream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<memory>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s;
    cin >> s;
    int total = s.size();
    string boom;
    cin >> boom;
    string ans;
    int boom_size=boom.size();
    for(int i=0;i<total;i++)
    {
        ans.push_back(s[i]);
        if(ans.back()==boom.back()&&ans.size()>=boom_size)
        {
            if(!ans.substr(ans.size()-boom_size,boom_size).compare(boom) )
                for(int j=0;j<boom_size;j++)
                    ans.pop_back();
        }
    }
    if(ans.size()==0)
        cout <<"FRULA";
    else cout << ans;
}
