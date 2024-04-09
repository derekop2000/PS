#include <iostream>
#include<sstream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<memory>
using namespace std;
int a,b,n,m;
int **arr;
struct box
{
    int x,y;
    char direct;
};
struct orderBox
{
    int who;
    char order;
    int loop;
};
char directChange(char c,int isRight)
{
    int temp;
    char list_[]={ 'N', 'E', 'S', 'W' };
    for(int i=0;i<4;i++)
        if(list_[i]==c)
        {
            temp=i;
            break;
        }
    if(isRight) temp= (temp+1)%4;
    else temp = (temp+3)%4;
    return list_[temp];
}
int main()
{
    cin >>a>>b>>n>>m;
    vector<box> v(n);
    vector<orderBox> v2(m);
    arr = new int*[b];
    for(int i=0;i<b;i++)
        arr[i] = new int[a];

    for(int i=0;i<n;i++)
    {
        int x,y;
        cin >>x>>y;
        x =x-1;
        y=b-y;
        v[i].x=x;
        v[i].y=y;
        cin >> v[i].direct;
    }
    for(int i=0;i<m;i++)
        cin >> v2[i].who >> v2[i].order >> v2[i].loop;


    for(int i=0;i<b;i++)
        for(int j=0;j<a;j++)
            arr[i][j]=0;

    for(int i=0;i<n;i++)
        arr[ v[i].y ][ v[i].x ]=i+1;

    for(int i=0;i<m;i++)
    {
        if(v2[i].order=='F')
        {
            pair<int,int> directXY;
            pair<int,int> tempXY;
            tempXY.first = v[v2[i].who-1].x;
            tempXY.second = v[v2[i].who-1].y;
            if(v[v2[i].who-1].direct=='N'){directXY.first =0,directXY.second=-1;}
            else if(v[v2[i].who-1].direct=='E'){directXY.first =1,directXY.second=0;}
            else if(v[v2[i].who-1].direct=='S'){directXY.first =0,directXY.second=1;}
            else if(v[v2[i].who-1].direct=='W'){directXY.first =-1,directXY.second=0;}
            for(int q=0;q<v2[i].loop;q++)
            {
                tempXY.first += directXY.first;
                tempXY.second += directXY.second;
                if( !(0<=tempXY.first&&tempXY.first<a&&0<=tempXY.second&&tempXY.second<b) )
                {
                    cout <<"Robot "<<v2[i].who<<" crashes into the wall";return 0;
                }
                else if(arr[tempXY.second][tempXY.first])
                {
                    cout << "Robot "<<v2[i].who<<" crashes into robot "<<arr[tempXY.second][tempXY.first];return 0;
                }
            }
            arr[v[v2[i].who-1].y][v[v2[i].who-1].x]=0;
            v[v2[i].who-1].x = tempXY.first;
            v[v2[i].who-1].y = tempXY.second;
            arr[tempXY.second][tempXY.first]=v2[i].who;

        }
        else
        {
            for(int j=0;j<v2[i].loop;j++)
            {

                if(v2[i].order=='L')
                {
                    v[ v2[i].who-1 ].direct = directChange( v[v2[i].who-1].direct,0 );
                }
                else
                {
                    v[v2[i].who-1].direct = directChange( v[v2[i].who-1].direct,1 );
                }
            }

        }
    }
    for(int i=0;i<b;i++)
        delete[] arr[i];
    delete[] arr;
    cout <<"OK";
}
