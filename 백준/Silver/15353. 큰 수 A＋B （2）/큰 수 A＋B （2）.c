#include<stdio.h>
#include<string.h>
int main()
{
	char a[10002];
	char b[10002];
	char res[10002];
	scanf("%s %s",&a, &b);
	int carry=0, order = 0, lena=strlen(a)-1,lenb=strlen(b)-1,temp;
	if(lena>=lenb)
			while (1)
			{
				temp = a[lena--] - '0' + b[lenb--] - '0' + carry;
				if (temp > 9)
				{
					carry = 1;
					temp -= 10;
					res[order++] = temp + '0';
				}
				else
				{
					carry = 0;
					res[order++] = temp + '0';
				}
				if (lenb == -1)
				{
					while (1)
					{
						if (lena == -1)
							break;
						temp = a[lena--] - '0' + carry;
						if (temp > 9)
						{
							carry = 1;
							temp -= 10;
							res[order++] = temp + '0';
						}
						else
						{
							carry = 0;
							res[order++] = temp + '0';
						}
					}
					break;
				}
			}
	else
			while (1)
			{
				temp = a[lena--] - '0' + b[lenb--] - '0' + carry;
				if (temp > 9)
				{
					carry = 1;
					temp -= 10;
					res[order++] = temp + '0';
				}
				else
				{
					carry = 0;
					res[order++] = temp + '0';
				}
				if (lena == -1)
				{
					while (1)
					{
						if (lenb == -1)
							break;
						temp = b[lenb--] - '0' + carry;
						if (temp > 9)
						{
							carry = 1;
							temp -= 10;
							res[order++] = temp + '0';
						}
						else
						{
							carry = 0;
							res[order++] = temp + '0';
						}
					}
					break;
				}
			}
	if (carry == 1)
		res[order++] = '1';
	order--;
	for (order; order > -1; order--)
		putchar(res[order]);

}