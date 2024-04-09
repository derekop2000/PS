#include<iostream>
#include<vector>
using namespace std;
int* arr;
int findParent(int a)
{
    if(arr[a]==a)return a;
    else return arr[a]=findParent(arr[a]);
}
void union_(int a,int b)
{
    int ap = findParent(a);
    int bp = findParent(b);
    if(ap==bp)return;
    else
    {
        if(ap<bp)arr[bp]=ap;
        else arr[ap]=bp;
    }
}

bool isUnion(int a,int b)
{
    if(findParent(a)==findParent(b) )return true;
    else return false;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n,m;
    bool isOk =true;
    vector<int> q;
    cin >> n >> m;
    int temp;
    arr = new int[n];
    for(int i=0;i<n;i++)arr[i]=i;

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            cin >> temp;
            if(i==j)continue;
            if(temp)union_(i,j);
        }
    while(m--)
    {
        cin >> temp;
        q.push_back(temp);
    }


    for(int i=0;i<q.size()-1;i++)
    {

        if( !isUnion(q[i]-1,q[i+1]-1) )
        {
            isOk = false;
            break;
        }
    }
    if(isOk)cout << "YES";
    else cout <<"NO";
    delete[] arr;
}
