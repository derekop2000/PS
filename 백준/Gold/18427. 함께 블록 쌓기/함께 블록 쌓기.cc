#include<iostream>
#include<vector>
#include<memory>
#include<string>
#include<sstream>
using namespace std;
int n,m,h;
int dp[51][1001];
int main()
{
    cin >>n>>m>>h;cin.ignore();
    unique_ptr< unique_ptr<vector<int>>[]> teacher = make_unique< unique_ptr<vector<int>>[] >(n);
    for(int i=0;i<n;i++)
        teacher[i] = make_unique<vector<int>>();
    dp[0][0]=1;
    string s;
    string temp;
    for(int i=0;i<n;i++)
    {
        getline(cin,s);
        stringstream ss(s);
        while(getline(ss,temp,' ') ){
        (*(teacher[i].get())).push_back(stoi(temp));}
    }
    for(int i=1;i<=n;i++)
        for(int j=0;j<=h;j++)
        {
            int size_=(*(teacher[i-1])).size();
            for(int q=0;q<size_;q++)
            {
                if( (*teacher[i-1])[q]<=j)
                {
                    dp[i][j]+=dp[i-1][j- (*teacher[i-1])[q] ];
                    dp[i][j]%=10007;
                }
            }
            dp[i][j]+=dp[i-1][j];
            dp[i][j]%=10007;
        }
    cout << dp[n][h];

}
