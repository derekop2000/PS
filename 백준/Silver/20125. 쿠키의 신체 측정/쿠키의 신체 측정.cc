#include<iostream>
#include<vector>
using namespace std;
char arr[1000][1000];

int main()
{
    int n;
    cin >> n;
    pair<int,int> heart;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            cin >> arr[i][j];
        }
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            if(0<i&&i<n-1&&0<j&&j<n-1&&arr[i-1][j]=='*'&&arr[i][j+1]=='*'&&arr[i+1][j]=='*'&&arr[i][j-1]=='*')
            {heart.first=i;heart.second=j;}
        }
    int a1=0,a2=0,a3=0,a4=0,a5=0;
    int i;
    for(i=heart.second-1;i>=0;i--)
        if(arr[heart.first][i]=='*')a1++;
        else break;
    for(i=heart.second+1;i<n;i++)
        if(arr[heart.first][i]=='*')a2++;
        else break;
    for(i=heart.first+1;i<n;i++)
        if(arr[i][heart.second]=='*')a3++;
        else break;

    for(i=heart.first+a3+1;i<n;i++)
        if(arr[i][heart.second-1]=='*')a4++;
        else break;

    for(i=heart.first+a3+1;i<n;i++)
        if(arr[i][heart.second+1]=='*')a5++;
        else break;
    cout << heart.first+1<<' '<<heart.second+1<<'\n';
    cout <<a1<<' '<<a2<<' '<<a3<<' '<<a4<<' '<<a5;

}
