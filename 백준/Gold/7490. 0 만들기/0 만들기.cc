#include <iostream>
#include<sstream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
using namespace std;
int n;
vector<string> op;
bool judge(string str)
{
    int temp;
    int cnt=n-1;
    while( (temp = str.find(" "))!=string::npos )
        {
            str.erase(temp,1);cnt--;
        }
    stringstream ss;
    ss.str(str);
    char c;
    ss >> temp;
    for(int i=0;i<cnt;i++)
    {
        ss>>c;
        int temp2;
        ss >> temp2;
        if(c=='+')
            temp+=temp2;
        else temp-=temp2;

    }
    return temp==0;
}
string judge_str;
void dfs(int floor)
{
    judge_str.append(to_string(floor) );
    if(floor==n)
    {
        if( judge(judge_str) )cout<<judge_str<<'\n';

        return;
    }
    for(int i=0;i<3;i++)
    {
        judge_str.append( op[i] );
        dfs(floor+1);
        judge_str.erase(judge_str.size()-2,2);
    }
}
int main()
{
    op.push_back(" ");
    op.push_back("+");
    op.push_back("-");
    int t;

    cin >> t;
    while(t--)
    {
        cin >>n;
        judge_str.clear();
        dfs(1);
        cout <<'\n';
    }
}
