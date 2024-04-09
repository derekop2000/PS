#include<stdio.h>
int check(char* p, char* str);
int main()
{
    char str[101];
    scanf("%s", str);
    int count = 0;
    for (int i = 0; str[i]; i++)
    {
        if (str[i] == 'd' && str[i + 1] == 'z' && str[i + 2] == '=')
        {
            count++;
            i += 2;
        }
        else if (check(str + i, "c=") || check(str + i, "c-") || \
            check(str + i, "d-") || check(str + i, "lj") || \
            check(str + i, "nj") || check(str + i, "s=") || \
            check(str + i, "z=") )
        {
            count++;
            i++;
        }
        else count++;
    }
    printf("%d", count);
}
int check(char* p, char* str)
{
    if (*p == str[0] && *(p + 1) == str[1])
        return 1;
    else return 0;
}