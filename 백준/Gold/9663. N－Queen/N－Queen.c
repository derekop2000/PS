#include<stdio.h>
#include<stdlib.h>
int n;
int count;
int visit[15];
int store[15];

int is_ok(int floor,int column)
{
    int left,right;
    for(int i=0;i<floor;i++)
    {
        left = store[i]-(floor-i);
        right= store[i]+(floor-i);
        if(left==column || right==column)
            return 0;
    }
    return 1;

}
void f(int floor)
{
    if(floor==n-1)
    {
        count++;
    }
    else
    {
        for(int i=0;i<n;i++)
        {
            if( visit[i]==0&& is_ok(floor+1,i) )
            {
                visit[i]=1;
                store[floor+1]=i;
                f(floor+1);
                visit[i]=0;
            }
        }
    }

}
int main()
{
    scanf("%d",&n);
    f(-1);
    printf("%d",count);
}
