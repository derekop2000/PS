#include <stdio.h>
#include <stdlib.h>
int round(double value) // 반올림 함수
{
    if(value<0)
    {
        return (int)(value-0.5);
    }
    else return (int)(value+0.5);
}
void merge(int *list,int s,int e,int mid) // 머지소트
{
    int* temp=(int*)malloc(4*(e-s));
    int left=s,right=mid,temp_point=0;
    while(left<mid&&right<e)
    {
        if(list[left]<list[right])
        {
            temp[temp_point]=list[left];
            temp_point++;
            left++;
        }
        else
        {
            temp[temp_point]=list[right];
            temp_point++;
            right++;
        }
    }
    while(left<mid)
    {
        temp[temp_point]=list[left];
        temp_point++;
        left++;
    }
    while(right<e)
    {
        temp[temp_point]=list[right];
        temp_point++;
        right++;
    }
    temp_point--;
    for(int k=temp_point; k>=0; k--)
    {
        list[s+k]=temp[k];
    }
    free(temp);
}
void merge_sort(int*list,int s,int e)
{
    if(s<e-1)
    {
        int mid= (s+e)/2;
        merge_sort(list,s,mid);
        merge_sort(list,mid,e);
        merge(list,s,e,mid);
    }
}
int main()
{
    int n,temp,sum=0;
    scanf("%d",&n);
    int* list=(int*)malloc(4*n);
    for(int i=0; i<n; i++)
    {
        scanf(" %d",&temp);
        list[i]=temp;
        sum+=temp;
    }
    merge_sort(list,0,n);

    //choi - 루프 두 번 돌려서 두번째 최빈값찾기
    int choi=list[0],count=1,max=1;
    for(int i=1; i<n; i++)
    {
        if(list[i]==list[i-1])
        {
            count++;
            if(count>max)
            {
                choi=list[i];
                max=count;
            }
        }
        else
        {
            count=1;
        }

    }
    count=1;
    for(int i=max;i<n;i++)
    {
        if(list[i]==list[i-1])
        {
            count++;
            if(count==max&&choi!=list[i])
            {
                choi=list[i];
                break;
            }
        }
        else
        {
            count=1;
            if(count==max&&choi!=list[i])
            {
                choi=list[i];
                break;
            }
        }
    }

    if(n==1)
    {
        printf("%d\n%d\n%d\n%d",temp,temp,temp,0);
    }
    else
    {
        printf("%d\n%d\n%d\n%d",round((double)sum/n),list[(n-1)/2],choi,list[n-1]-list[0]);
    }
    free(list);
}
