#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int a,b;
bool p[100][100];
int main()
{
    cin >> a>> b;
    int temp1,temp2;
    while(b--)
    {
        cin >> temp1>>temp2;
        p[temp1-1][temp2-1]=true;
    }

    for(int i=0;i<a;i++)
        for(int j=0;j<a;j++)
            for(int q=0;q<a;q++)
            {
                if(j==q)continue;
                if(p[j][i]&&p[i][q])p[j][q]=true;
            }

    for(int i=0;i<a;i++)
    {
        int cnt=0;
        for(int j=0;j<a;j++)
        {
            if(i==j)continue;
            if(!p[i][j]&&!p[j][i] )cnt++;
        }
        cout << cnt<<'\n';
    }

}

