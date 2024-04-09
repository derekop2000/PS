#include<iostream>
#include<string>
using namespace std;
bool state[100001];
bool state2[100001];
bool goal[100001];
int n;
int main()
{
    cin >> n;
    string str;
    cin >> str;
    int temp;

    for(int i=0;i<str.size();i++)
    {
        temp = str[i]-'0';
        if(temp)
        {
            state[i]=true;
            state2[i]=true;
        }
    }
    cin >> str;
    for(int i=0;i<str.size();i++)
    {
        temp = str[i]-'0';
        if(temp)
            goal[i]=true;
    }

    int cnt=0;
    for(int i=1;i<n;i++)
    {
        if(state[i-1]!=goal[i-1])
        {
            cnt++;
            state[i]=!state[i];
            state[i+1]=!state[i+1];
        }
    }
    if(state[n-1]==goal[n-1])
    {
        cout << cnt;
        return 0;
    }
    cnt=1;
    state2[0]=!state2[0];
    state2[1]=!state2[1];

    for(int i=1;i<n;i++)
    {
        if(state2[i-1]!=goal[i-1])
        {
            cnt++;
            state2[i]=!state2[i];
            state2[i+1]=!state2[i+1];
        }
    }
    if(state2[n-1]==goal[n-1])
    {
        cout << cnt;
        return 0;
    }
    cout << "-1";
    return 0;

}
