#include<stdio.h>
int store[9];
void f(int n,int m,int floor)
{
    if(floor==m)
    {
        for(int i=1;i<=m;i++)
            printf("%d ",store[i]);
        putchar('\n');
    }
    else
    {
        for(int i=store[floor];i<=n;i++)
            {
                store[floor+1]=i;
                f(n,m,floor+1);
            }
    }
}
int main()
{
    store[0]=1;
    int n,m;
    scanf(" %d %d",&n,&m);
    f(n,m,0);
}
