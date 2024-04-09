#include <iostream>
using namespace std;
int n;
int* maxHip;
int maxHipSize=0; // 마지막 요소를 가리킴
int* minHip;
int minHipSize=0; // 마지막 요소를 가리킴
int minHipSub();
int maxHipSub();
void minHipAdd(int num);
void maxHipAdd(int num);
int main()
{
    cin.tie(nullptr); ios::sync_with_stdio(false);
    cin >> n;
    int turn=0 ; // 0 이면 minHip 에 1 이면 maxHip 에 들어갈 차례
    maxHip = new int[n/2+1];
    minHip = new int[n/2+2];
    int callNum;
    int temp;

    for(int i=0;i<n;i++)
    {
        cin >> callNum;
        if(turn ==0)
        {
            if(maxHipSize==0)
                minHipAdd(callNum);
            else
            {
                if(maxHip[1]>callNum)
                {
                    temp = maxHipSub();
                    maxHipAdd(callNum);
                    minHipAdd(temp);
                }
                else minHipAdd(callNum);
            }
            turn++;
        }
        else
        {
            if(minHip[1]<callNum)
                {
                    temp = minHipSub();
                    minHipAdd(callNum);
                    maxHipAdd(temp);
                }
            else maxHipAdd(callNum);
            turn--;
        }
        if(turn==0)
            cout << maxHip[1]<<'\n';
        else cout << minHip[1]<<'\n';

    }
    delete maxHip;
    delete minHip;
}
void maxHipAdd(int num)
{
    maxHipSize++;
    int numPosition = maxHipSize;
    int compare = numPosition/2;
    while(compare)
    {
        if(maxHip[compare]<num)
        {
            maxHip[numPosition] = maxHip[compare];
            numPosition/=2;
            compare = numPosition/2;
        }
        else break;
    }
    maxHip[numPosition] = num;
}
int maxHipSub()
{
    int returnValue = maxHip[1];
    if(maxHipSize==1){maxHipSize--; return returnValue;}
    int lastNum =maxHip[maxHipSize--];
    int tempPosition =1;
    int child=tempPosition*2;
    while(child<=maxHipSize)
    {
        if(child+1<=maxHipSize&&maxHip[child+1]>maxHip[child])child++;
        if(maxHip[child]>lastNum)
        {
            maxHip[tempPosition] = maxHip[child];
            tempPosition = child;
            child = tempPosition*2;
        }
        else break;
    }
    maxHip[tempPosition] = lastNum;
    return returnValue;
}
void minHipAdd(int num)
{
    minHipSize++;
    int numPosition = minHipSize;
    int compare = numPosition/2;
    while(compare!=0)
    {
        if(minHip[compare]>num)
        {
            minHip[numPosition] = minHip[compare];
            numPosition/=2;
            compare = numPosition/2;
        }
        else break;
    }
    minHip[numPosition] = num;
}
int minHipSub()
{
    int returnValue = minHip[1];
    if(minHipSize==1){minHipSize--; return returnValue;}
    int lastNum =minHip[minHipSize--];
    int tempPosition =1;
    int child=tempPosition*2;
    while(child<=minHipSize)
    {
        if(child+1<=minHipSize&&minHip[child+1]<minHip[child])child++;
        if(minHip[child]<lastNum)
        {
            minHip[tempPosition] = minHip[child];
            tempPosition = child;
            child = tempPosition*2;
        }
        else break;
    }
    minHip[tempPosition] = lastNum;
    return returnValue;
}
