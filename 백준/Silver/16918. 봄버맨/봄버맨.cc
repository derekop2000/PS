#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int dir1[] = {-1,0,1,0};
int dir2[] = {0,1,0,-1};
vector<vector<int>> arr;
int a,b,n;
void show_ans()
{
    for(int i=0;i<a;i++)
    {
        for(int j=0;j<b;j++)
            if(arr[i][j])cout << "O";else cout<<'.';cout<<'\n';
    }
}
void explosion()
{
    for(int i=0;i<a;i++)
        for(int j=0;j<b;j++)
        {
            if(arr[i][j]==4)
            {
                for(int q=0;q<4;q++)
                {
                    int y=i+dir1[q];
                    int x=j+dir2[q];
                    if(0<=y&&y<a&&0<=x&&x<b&&arr[y][x]!=4)
                        arr[y][x]=0;
                }
                arr[i][j]=0;
            }

        }
}
void f()
{
    int t=2;
    while(t<=n)
    {
        for(int i=0;i<a;i++)
            for(int j=0;j<b;j++)
                arr[i][j]++;
        if(t%2)
        {
            explosion();
        }
        t++;
    }

}
int main()
{
    cin >>a>>b>>n;
    arr.resize(a);
    for(int i=0;i<a;i++)
        arr[i].resize(b);

    for(int i=0;i<a;i++)
        for(int j=0;j<b;j++)
        {
            char temp;
            cin >>temp;
            if(temp =='.')
                arr[i][j]=0;
            else arr[i][j]=2;
        }
    if(n==1)
        {show_ans();return 0;}
    f();
    show_ans();
}
