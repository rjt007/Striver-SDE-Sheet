//Implementation of Simple Queue using Array/Vector
#include <bits/stdc++.h>
using namespace std;

void push(vector<int> &v, int n, int &front, int &rear)
{
    cout << "Enter element to be pushed: ";
    int ele;
    cin >> ele;
    if (rear == n - 1)
    {
        cout << "Queue is full!!\n";
        return;
    }
    if(rear==-1 && front==-1)
    {
        rear++;front++;
        v[rear]=ele;
        return;
    }
    rear++;
    v[rear]=ele;
}

void pop(vector<int> &v, int &front, int &rear)
{
    if (front == -1 && rear==-1)
    {
        cout << "Queue is Empty!!\n";
        return;
    }
    if (front==rear)
    {
        cout<<"Poped Element is: "<<v[front]<<endl;
        front=rear=-1;
        return;
    }
    cout << "Poped Element is: " << v[front] << endl;
    front++;
}

void display(vector<int> v, int front, int rear)
{
    if (front == -1 && rear == -1)
    {
        cout << "Queue is Empty!!\n";
        return;
    }
    for (int i = front; i<=rear; i++)
    {
        cout << "|" << v[i] << "| ";
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n, 0);
    int choice = 1;
    int rear = -1, front = -1;
    while (choice)
    {
        cout << "Press 1 for push, 2 for pop, 3 for display, 0 for exit: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            push(v, n, front, rear);
            break;
        case 2:
            pop(v, front, rear);
            break;
        case 3:
            display(v, front, rear);
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