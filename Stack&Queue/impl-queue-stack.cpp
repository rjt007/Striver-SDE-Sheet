//Implementation of Queue using Stack
#include <bits/stdc++.h>
using namespace std;

/* //Method1: Using 2 Stacks
// T.C->O(N) && S.C->O(2*N)

stack<int>s1;
stack<int>s2;

void push(int x) //T.C->O(N)
{
    while (!s1.empty())
    {
        s2.push(s1.top());
        s1.pop();
    }
    s1.push(x);
    while (!s2.empty())
    {
        s1.push(s2.top());
        s2.pop();
    }
}

void pop() //T.C->O(1)
{
    int res = s1.top();
    s1.pop();
    cout << "Poped Element is: " << res << endl;
}

void peek() //T.C->O(1)
{
    cout << s1.top() << endl;
}

void isempty() //T.C->O(1)
{
    if (s1.empty())
        cout << "Queue is empty!!\n";
    else
        cout << "Queue is Not empty!!\n";
} */

//Method2: Using Amortized Stack Method
// T.C->O(1) for push operation && S.C->O(2*N)

stack<int>input;
stack<int>output;

void push(int x) // T.C->O(1)
{
    input.push(x);
}

void pop() // T.C->Amortised O(1)
{
    if(!output.empty())
    {
        cout << "Poped Element is: " << output.top() << endl;
        output.pop();
        return;
    }
    while (!input.empty())
    {
        output.push(input.top());
        input.pop();
    }
    cout << "Poped Element is: " << output.top() << endl;
}

void peek() // T.C->Amortised O(1)
{
    if (!output.empty())
    {
        cout << "Peek Element is: " << output.top() << endl;
        return;
    }
    while (!input.empty())
    {
        output.push(input.top());
        input.pop();
    }
    cout << "Peek Element is: " << output.top() << endl;
}

void isempty() // T.C->O(1)
{
    if (output.empty() && input.empty())
        cout << "Queue is empty!!\n";
    else
        cout << "Queue is Not empty!!\n";
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
            cout << "Enter element to be pushed: ";
            int x;
            cin >> x;
            push(x);
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
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