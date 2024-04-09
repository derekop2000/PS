#include<iostream>
#include<queue>
using namespace std;
int arr[100001];
queue<int> q;
int a,b,cnt;
void dfs()
{
    int temp;
    while(!q.empty())
    {
        temp = q.front();q.pop();
        if(0<temp && !arr[temp-1]) {arr[temp-1]=arr[temp]+1;q.push(temp-1);}
        if(temp<100000 && !arr[temp+1]){arr[temp+1]=arr[temp]+1;q.push(temp+1);}
        if(temp*2<=100000 && !arr[temp*2]){arr[temp*2]=arr[temp]+1;q.push(temp*2);}
    }
}
void reverse_dfs()
{
    int temp;
    while(!q.empty())
    {
        temp=q.front();q.pop();
        if(temp==a){cnt++;continue;}
        if(0<temp&& arr[temp-1]+1==arr[temp]){q.push(temp-1);}
        if(temp<100000 && arr[temp+1]+1==arr[temp]){q.push(temp+1);}
        if(temp%2==0&&temp>0 && arr[temp/2]+1==arr[temp]){q.push(temp/2);}
    }
}
int main()
{
    cin >> a>>b;
    q.push(a);
    dfs();
    arr[a]=0;
    q.push(b);
    reverse_dfs();
    cout << arr[b]<<'\n'<<cnt;
}
