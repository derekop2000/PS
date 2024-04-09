#include<iostream>
#include<string>
using namespace std;
int stackPoint =-1;
int stack_[10000];

void push(int data)
{
    stackPoint++;
    stack_[stackPoint]=data;
}
int pop()
{
    if(stackPoint==-1)return -1;
    return stack_[stackPoint--];
}
int size_()
{
    return stackPoint+1;
}
int isEmpty()
{
    if(size_()==0)return 1; else return 0;
}
int top()
{
    if(!isEmpty())return stack_[stackPoint];
    else return -1;
}
int main()
{
    string order;
    int t;
    int temp;

    cin >> t;
    while(t--)
    {
        cin >> order;
        if(order=="push") {cin >> temp;push(temp);}
        else if(order=="top"){cout << top()<<'\n';}
        else if(order=="size"){cout << size_() << '\n';}
        else if(order=="empty") {cout << isEmpty() <<'\n';}
        else {cout << pop() <<'\n';}
    }
}
