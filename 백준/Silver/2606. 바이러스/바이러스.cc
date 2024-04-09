#include<iostream>
using namespace std;
int* parent;
void uni(int a,int b);
int findParent(int i);
int isUni(int a,int b);
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin >> n >> m;
    parent = new int[n+1];
    for(int i=0;i<=n;i++)parent[i]=i;
    int a,b;
    for(int i=0;i<m;i++)
    {
        cin >> a >> b;
        uni(a,b);
    }
    int count=0;
    for(int i=2;i<=n;i++)
        if(isUni(1,i))count++;
    cout << count;
    delete[] parent;
}
void uni(int a,int b)
{
    int aa,bb;
    aa = findParent(a);
    bb = findParent(b);
    if(aa==bb)return;
    if(aa<bb)parent[bb] = aa;else parent[aa] = bb;
}
int findParent(int i)
{
    if(parent[i]==i)
        return i;
    else {parent[i]=findParent(parent[i]);return parent[i];}
}
int isUni(int a,int b)
{
    if(findParent(a)==findParent(b))return 1;
    else return 0;
}
