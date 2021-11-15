//Implementation of Stack using Array/Vector
#include<bits/stdc++.h>
using namespace std;

void push(vector<int>&v, int n,int &top)
{
    cout<<"Enter element to be pushed: ";
    int ele;
    cin>>ele;
    if(top==n-1)
    {
        cout << "Stack Overflow!!\n";
        return;
    }
    top++;
    v[top]=ele;
}

void pop(vector<int>&v, int &top)
{
    if(top==-1)
    {
        cout<<"Stack Underflow!!\n";
        return;
    }
    cout<<"Poped Element is: "<<v[top]<<endl;
    //v.pop_back();
    top--;
}

void display(vector<int>v, int top)
{
    if(top==-1)
    {
        cout << "Stack is Empty!!\n";
        return;
    }
    for (int i = top; i >=0; i--)
    {
        cout<<"|"<<v[i]<<"| ";
    }
    cout<<endl;
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n,0);
    int choice = 1;
    int top = -1;
    while (choice)
    {
        cout<<"Press 1 for push, 2 for pop, 3 for display, 0 for exit: ";
        cin>>choice;
        switch (choice)
        {
        case 1:
            push(v,n,top);
            break;
        case 2: 
            pop(v,top);
            break;
        case 3:
            display(v,top);
            break;
        case 0:
            break; 
        default:
            cout<<"Enter valid no.\n";
            break;
        }
    }
    return 0;
}