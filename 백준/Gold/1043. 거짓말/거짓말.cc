#include<iostream>
#include<vector>
using namespace std;
int n,m;
int parent[51];
int findParent(int a)
{
    if(parent[a]==a)
        return a;
    return parent[a]=findParent(parent[a]);
}
void uni(int a,int b)
{
    int ap = findParent(a);
    int bp = findParent(b);
    if(ap==bp)return;
    if(ap<bp)parent[bp]=ap;
    else parent[ap]=bp;
}
bool isUni(int a,int b)
{
    return findParent(a)==findParent(b);
}
int main()
{
    int temp,temp2;
    vector<vector<int>> tempV;
    cin >> n >>m;
    tempV.resize(m);
    int ans = m;
    for(int i=0;i<=n;i++)
        parent[i]=i;

    cin >> temp;
    for(int i=0;i<temp;i++)
    {
        cin >>temp2;
        uni(0,temp2);
    }

    for(int i=0;i<m;i++)
    {
        cin >> temp;
        tempV[i].resize(temp);
        cin >> tempV[i][0];
        for(int j=1;j<temp;j++)
        {
            cin >> tempV[i][j];
            uni(tempV[i][j-1],tempV[i][j]);
        }
    }
    for(int i=0;i<m;i++)
        for(int j=0;j<tempV[i].size();j++)
        {
            if( findParent(tempV[i][j]) ==0)
            {
                ans--;break;
            }
        }
    cout << ans;
}
