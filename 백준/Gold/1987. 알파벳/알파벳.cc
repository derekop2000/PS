#include <iostream>
#include<sstream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<memory>
using namespace std;
bool visit[26];
int directCol[] = {-1,0,1,0};
int directRow[] = {0,1,0,-1};
int ans=1;
int col,row;
unique_ptr<unique_ptr<char[]>[]> arr;
void f(int floor,int col2,int row2)
{
    if(floor>ans)
        ans = floor;
    for(int i=0;i<4;i++)
    {
        int y = col2+directCol[i];
        int x = row2+directRow[i];
        if(0<=y&&y<col&&0<=x&&x<row&& !visit[arr[y][x]-'A'])
        {
            visit[arr[y][x]-'A']=true;
            f(floor+1,y,x);
            visit[arr[y][x]-'A']=false;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
    cin >> col >> row;
    arr = make_unique<unique_ptr<char[]>[]>(col);
    for(int i=0;i<col;i++)
        arr[i] = make_unique<char[]>(row);
    for(int i=0;i<col;i++)
        for(int j=0;j<row;j++)
            cin >> arr[i][j];
    visit[arr[0][0]-'A']=true;
    f(1,0,0);
    cout << ans;
}
