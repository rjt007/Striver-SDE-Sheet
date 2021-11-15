//Implementation of Stack using Queue
#include <bits/stdc++.h>
using namespace std;

/* //Method1: Using 2 queues
// T.C->O(N) && S.C->O(2*N)

queue<int> q1;
queue<int> q2;

void push(int x)
{
    q2.push(x);
    while (!q1.empty())
    {
        q2.push(q1.front());
        q1.pop();
    }
    swap(q1,q2);
}

void pop()
{
    int res = q1.front();
    q1.pop();
    cout << "Poped Element is: " << res << endl;
}

void top()
{
    cout << q1.front() << endl;
}

void isempty()
{
    if (q1.empty())
        cout << "Stack is empty!!\n";
    else
        cout << "Stack is Not empty!!\n";
} */

//Method2: Using Only 1 queue
// T.C->O(N) && S.C->O(N)

queue<int> q;

void push(int x)
{
    q.push(x);
    for (int i = 0; i < q.size() - 1; i++)
    {
        int temp = q.front();
        q.pop();
        q.push(temp);
    }
}

void pop()
{
    int res = q.front();
    q.pop();
    cout<<"Poped Element is: "<<res<<endl;
}

void top()
{
    cout<<q.front()<<endl;
}

void isempty()
{
    if (q.empty()) cout<<"Stack is empty!!\n";
    else
        cout << "Stack is Not empty!!\n";
}

int main()
{
    int choice = 1;
    while (choice)
    {
        cout << "Press 1 for push, 2 for pop, 3 for top, 4 for empty check, 0 for exit: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        cout<<"Enter element to be pushed: ";
        int x;
        cin>>x;
            push(x);
            break;
        case 2:
            pop();
            break;
        case 3:
            top();
            break;
        case 4: 
            isempty();
            break;
        case 0:
            break;
        default:
            cout << "Enter valid no.\n";
            break;
        }
    }
    return 0;
}