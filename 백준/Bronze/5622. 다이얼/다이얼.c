#include<stdio.h>
int main()
{
    char str[16];
    scanf("%s", str);
    int i = -1,count=0;
    while (str[++i] != '\0')
    {
        if (str[i] - 'A' < 3)
            count += 3;
        else if (str[i] - 'A' < 6)
            count += 4;
        else if (str[i] - 'A' < 9)
            count += 5;
        else if (str[i] - 'A' < 12)
            count += 6;
        else if (str[i] - 'A' < 15)
            count += 7;
        else if (str[i] - 'A' < 19)
            count += 8;
        else if (str[i] - 'A' < 22)
            count += 9;
        else if (str[i] - 'A' < 26)
            count += 10;
    }
    printf("%d", count);
}