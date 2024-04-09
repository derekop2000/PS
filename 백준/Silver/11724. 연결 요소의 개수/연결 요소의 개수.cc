#include<iostream>
using namespace std;
int* arr;

void uni(int a,int b);
int findParent(int a);
int isUnion(int a,int b);

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m;
    int a,b;
    cin >> n >> m;
    arr = new int[n+1];
    for(int i=1;i<n+1;i++)
        arr[i]=i;
    for(int i=0;i<m;i++)
    {
        cin >> a >>b;
        uni(a,b);
    }
    for(int i=1;i<n+1;i++)
        findParent(i);
    int count=0;
    int lastNum=0;
    int temp;
    for(int i=1;i<n+1;i++)
    {
        temp = findParent(i);
        if(lastNum < temp )
        {
            count++;
            lastNum = temp;
        }
    }
    cout << count;
}
void uni(int a,int b)
{
    if(findParent(a)==findParent(b))return;
    if(findParent(a)<findParent(b))
    {
        arr[findParent(b)] = findParent(a);
    }
    else arr[findParent(a)] = findParent(b);
}
int findParent(int a)
{
    if(arr[a]==a)
        return a;
    else {arr[a]=findParent(arr[a]);return arr[a];}
}
int isUnion(int a,int b)
{
    if(findParent(a)==findParent(b))return 1;
    else return 0;
}
