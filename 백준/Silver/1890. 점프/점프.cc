#include<iostream>
using namespace std;
int arr[100][100];
long long int arr2[100][100];
int main()
{
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin >> arr[i][j];
    arr2[0][0]=1;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(arr2[i][j])
            {
                if(arr[i][j]==0)continue;
                if(i+arr[i][j]<n)
                    arr2[i+arr[i][j]][j]+=arr2[i][j];
                if(j+arr[i][j]<n)
                    arr2[i][j+arr[i][j]]+=arr2[i][j];
            }

    


    cout << arr2[n-1][n-1];
}
