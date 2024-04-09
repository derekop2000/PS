#include <stdio.h>
int main()
{
    int a;
    scanf("%d",&a);
    char list[10];
    int count,i=0;
    while(a>9)
    {
        list[i]=a%10;
        a/=10;
        i++;
    }
    list[i]=a;
    for(int j=0;j<i;j++)
        for(int jj=j+1;jj<=i;jj++)
        {
            if(list[j]<list[jj])
            {
                list[j]=list[j]^list[jj];
                list[jj]=list[j]^list[jj];
                list[j]=list[j]^list[jj];
            }
        }
    for(int q=0;q<=i;q++)
        printf("%d",list[q]);
}