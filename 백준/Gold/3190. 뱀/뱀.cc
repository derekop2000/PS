#include<iostream>
using namespace std;
int circleQueue[10001][2];
int queueSize=10001;
int first=0;
int last=0;
int IsFull()
{
    if(  (first+1)%queueSize ==last)
        return 1;
    else return 0;
}
int IsEmpty()
{
    if(first==last)
        return 1;
    else return 0;
}
void insertQueue(int row,int column)
{
    if(IsFull() )
        return;
    else
    {
        first = (first+1)%queueSize;
        circleQueue[first][0]=row;
        circleQueue[first][1]=column;
    }
}
void deQueue()
{
    if(IsEmpty())
        return;
    else last = (last+1)%queueSize;
}
int arr[100][100];
int direct[100][2]; // 시간과 방향 0-왼   1-오.
int currentDirection=1; // 0 1 2 3 위 오른 아래 왼
int main()
{
    int n;
    cin >> n;
    insertQueue(0,0);

    arr[circleQueue[first][0] ][circleQueue[first][1] ]=1;
    int cnt;
    int a,b;
    char c;
    cin >> cnt;
    while(cnt--)
    {
       cin >> a >> b;
       arr[a-1][b-1] = 4;
    }
    cin >> cnt;
    for(int i=0;i<cnt;i++)
    {
        cin >> a >> c;
        if(c=='L')b=0;else b=1;
        direct[i][0]=a;direct[i][1]=b;
    }

    int headRow = circleQueue[first][0];
    int headColumn = circleQueue[first][1];
    cnt=0; // timer
    int directidx=0; //
    while(1)
    {
        cnt++;
        if(currentDirection==0)
            headRow--;
        else if(currentDirection==1)
            headColumn++;
        else if(currentDirection==2)
            headRow++;
        else if(currentDirection==3)
            headColumn--;
        if(headRow<0 || headRow>=n || headColumn<0 || headColumn>=n)
            break;
        if(arr[headRow][headColumn]==1)
            break;
        if(arr[headRow][headColumn]==4)
        {
            arr[headRow][headColumn]=1;
            insertQueue(headRow,headColumn);
        }
        else
        {
            arr[headRow][headColumn]=1;
            insertQueue(headRow,headColumn);
            deQueue();
            arr[circleQueue[last][0]][circleQueue[last][1]]=0;
        }
        if(direct[directidx][0]==cnt)
        {
            if(direct[directidx][1]==0)
                currentDirection = (currentDirection+3)%4;
            else
                currentDirection = (currentDirection+1)%4;
            directidx++;
        }
        /*
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                cout << arr[i][j] <<' ';
            cout <<'\n';
        }
        cout <<'\n';*/

    }
    cout << cnt;
}
