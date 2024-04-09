#include <iostream>
#include<sstream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<memory>
using namespace std;
int dir1[] = {-1,-1,-1,0};
int dir2[] = {-1,0,1,1};
int dir3[] = {1,1,1,0};
int dir4[] = {1,0,-1,-1};


int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,m;
    cin >>n>>m;
    vector<int> v(n);
    for(int i=0;i<n;i++)
        cin >> v[i];
    int temp=0;
    for(int i=0;i<m;i++)
    {
        temp += v[i];
    }
    int ma = temp;
    int cnt=1;
    int frontIndex =0;
    for(int i=m;i<n;i++)
    {
        temp -= v[frontIndex++];
        temp += v[i];
        if(temp > ma)
        {
            ma = temp;
            cnt =1;
        }
        else if( temp == ma )
        {
            cnt++;
        }
    }




    if(ma==0)
        cout << "SAD";
    else
    {

        cout << ma<<'\n'<<cnt;
    }

}

