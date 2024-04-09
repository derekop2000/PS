#include<iostream>
#include<memory>
#include<vector>
#include<algorithm>
using namespace std;
int cnt=0,cnt2;
vector<int> v;
unique_ptr<unique_ptr<int[]>[]> arr;
int n;
void dfs(int i, int j)
{
    arr[i][j]=0;
    cnt2++;
    if(i>0&&arr[i-1][j])dfs(i-1,j);
    if(j<n-1&&arr[i][j+1])dfs(i,j+1);
    if(i<n-1&&arr[i+1][j])dfs(i+1,j);
    if(j>0&&arr[i][j-1])dfs(i,j-1);
}
int main()
{
    cin >> n;
    arr = make_unique<unique_ptr<int[]>[]>(n);
    for(int i=0;i<n;i++)
        arr[i] = make_unique<int[]>(n);
    char temp_char;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            cin >> temp_char;
            arr[i][j]=temp_char-'0';
        }
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            if(arr[i][j])
            {
                cnt++;
                cnt2=0;
                dfs(i,j);
                v.push_back(cnt2);
            }
        }
    sort(v.begin(),v.end());
    cout <<cnt<<'\n';
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<'\n';
}
