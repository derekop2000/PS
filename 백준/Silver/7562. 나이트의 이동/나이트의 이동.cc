#include<iostream>
#include<queue>
#include<memory>
using namespace std;
int t,l,x1,y1,x2,y2;

int dx[]={1,2,2,1,-2,-1,-1,-2};
int dy[]={2,1,-1,-2,-1,-2,2,1};
void bfs()
{
    pair<int,int> temp_pair;
    unique_ptr<unique_ptr<int[]>[]> arr=make_unique<unique_ptr<int[]>[]>(l);
    for(int i=0;i<l;i++)
        arr[i] = make_unique< int[] >(l);
    queue<pair<int,int>> q;
    q.push(make_pair(x1,y1));
    while(!q.empty())
    {
        temp_pair = q.front();q.pop();
        if(temp_pair.first==x2&&temp_pair.second==y2)
            break;
        for(int i=0;i<8;i++)
        {
            if(0<=temp_pair.first+dx[i]&&temp_pair.first+dx[i]<=l-1&&0<=temp_pair.second+dy[i]&&temp_pair.second+dy[i]<=l-1&&!arr[ (l-1)-(temp_pair.second+dy[i]) ][ temp_pair.first+dx[i] ])
                {
                    arr[ (l-1)-(temp_pair.second+dy[i]) ][ temp_pair.first+dx[i] ]=arr[ (l-1)-temp_pair.second ][ temp_pair.first ]+1;
                    q.push(make_pair(temp_pair.first+dx[i],temp_pair.second+dy[i]) );
                }

        }
    }
    
    cout << arr[(l-1)-y2][x2]<<'\n';
}
int main()
{
    cin >>t;
    while(t--)
    {
        cin >> l >>x1>>y1>>x2>>y2;
        bfs();
    }
}
