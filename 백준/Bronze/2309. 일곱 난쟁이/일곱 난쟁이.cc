#include<iostream>
#include<algorithm>
using namespace std;
int* arr;
int main()
{
    arr = new int[9];
    for(int i=0;i<9;i++)
        cin >> arr[i];
    int temp=0;
    for(int i=0;i<9;i++)
        temp+=arr[i];
    temp-=100;
    sort(arr,arr+9);

    int a,b;
    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++)
            if((arr[i]+arr[j])==temp)
            {
                a=i;b=j;
            }
    for(int i=0;i<9;i++)
        if(i!=a&&i!=b)
        cout << arr[i] <<'\n';
    delete[] arr;
}
