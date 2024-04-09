#include <stdio.h>
int n,m;
char list[9];
char visited[9];
void dfs(int level)
{
    if(level==m)
    {
        for(int i=1;i<=m;i++)
            printf("%d ",list[i]);
        putchar('\n');
    }
    else
    {
        for(int j=list[level]+1;j<=n;j++)
        {
            if(visited[j]==0)
            {
                visited[j]=1;
                list[level+1]=j;
                dfs(level+1);
                visited[j]=0;
            }
        }
    }
}
int main()
{
    scanf(" %d %d",&n,&m);
    dfs(0);
}
