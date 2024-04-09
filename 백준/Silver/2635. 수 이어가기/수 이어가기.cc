#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> v,v2;
int num;
void f(int data)
{
    v.resize(1);
    v.push_back(data);
    while(1)
    {
        int temp,index;
        index=v.size();
        temp = v[index-2]-v[index-1];
        if(temp<0)
            break;
        v.push_back(temp);
    }
    if(v.size() > v2.size() )
        v2=v;
}
int main()
{

    cin >> num;
    v.push_back(num);
    v2.push_back(num);
    v2.push_back(num);
    v2.push_back(0);
    v2.push_back(num);

    for(int i=num-1;i>0;i--)
        f(i);
    cout << v2.size()<<'\n';
    for(int i=0;i<v2.size();i++ )
        cout << v2[i] << ' ';

}

