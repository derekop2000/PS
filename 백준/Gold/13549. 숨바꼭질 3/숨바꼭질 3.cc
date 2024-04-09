#include<iostream>
#define F 100001
using namespace std;
int arr[F];
int arrr[F];
int a,b;
int frontIndex=0,backIndex=0;
bool isEmpty()
{
    return frontIndex==backIndex;
}
bool isFull()
{
    return (frontIndex+1)%F==backIndex;
}
void pushBack(int data)
{
    if(!isFull() )
    {
        frontIndex=(frontIndex+1)%F;
        arr[frontIndex]=data;
    }
}
int popFront()
{
    if(!isEmpty() )
    {
        backIndex=(backIndex+1)%F;
        return arr[backIndex];
    }
}
void pushFront(int data)
{
    if(!isFull())
    {
        arr[backIndex]=data;
        backIndex=(backIndex+F-1)%F;
    }
}
int popBack()
{
    if(!isEmpty())
    {
        int temp = frontIndex;
        frontIndex=(frontIndex+F-1)%F;
        return arr[temp];
    }
}
void dfs()
{
    int temp;
    while(!isEmpty())
    {
        temp = popFront();
        if(temp==b)
        {cout<<arrr[b];return;}
        if(temp*2< F&& arrr[temp*2]==-1){arrr[temp*2]=arrr[temp];pushFront(temp*2); }
        if(temp>0 && arrr[temp-1]==-1){arrr[temp-1]=arrr[temp]+1;pushBack(temp-1); }
        if(temp<F-1 && arrr[temp+1]==-1){arrr[temp+1]=arrr[temp]+1;pushBack(temp+1);}
    }
}
int main()
{

    cin >>a>>b;
    if(a==b){cout<<'0';return 0;}
    pushBack(a);
    for(int i=0;i<F;i++)
        arrr[i]=-1;
    arrr[a]=0;
    dfs();
}
