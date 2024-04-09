#include<iostream>
#include<memory>
#include<queue>
#include<vector>
using namespace std;
int ans;
int main()
{
    int n,m;
    cin >> n>> m;
    int** arr;
    arr = new int*[n];
    for(int i=0;i<n;i++)
        arr[i] = new int[m];
    for(int i=0;i<n;i++)
        for(int j=0; j<m;j++)
        {
            arr[i][j]=0;
        }

    for(int i=0;i<m;i++)
    {
        int temp;
        cin >> temp;
        for(int j=0;j<temp;j++)
            arr[n-1-j][i]=1;
    }
    for(int i=0;i<n;i++)
    {
        int s=-1;
        int e=-1;
        for(int j=0;j<m;j++)
        if(arr[i][j]==1){s=j;break;}
        for(int j=m-1;j>=0;j--)
        if(arr[i][j]==1){e=j;break;}

        if(s!=-1&&s!=e)
        {
            for(int q=s+1;q<e;q++)
                if(!arr[i][q])ans++;
        }
    }
    cout << ans;
    for(int i=0;i<n;i++)
        delete[] arr[i];
    delete[] arr;
}
