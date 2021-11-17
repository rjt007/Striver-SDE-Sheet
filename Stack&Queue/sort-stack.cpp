//Sort A Stack
#include <bits/stdc++.h>
using namespace std;


/* //Method1: Recursion
//T.C->O(N^2) && S.C->O(1), Auxilary Space->O(1)

void insert(stack<int>&st, int ele)
{
    if(st.empty() || st.top()>=ele)
    {
        st.push(ele);
        return;
    }
    int temp = st.top();
    st.pop();
    insert(st,ele);
    st.push(temp);
}

void sortstack(stack<int>&st)
{
    if(st.size()==1)
    {
        return;
    }
    int ele = st.top();
    st.pop();
    sortstack(st);
    insert(st, ele);
} */

//Method2: Using another stack
//T.C->O(N^2) & S.C->O(N)
stack<int>sortstack(stack<int> st)
{
    stack<int>temp;
    while (!st.empty())
    {
        int ele = st.top();
        st.pop();
        while (!temp.empty() && temp.top()<=ele)
        {
            st.push(temp.top());
            temp.pop();
        }
        temp.push(ele);
    }
    return temp;
}

int main()
{
    int n;
    cin>>n;
    stack<int>st;
    int val;
    for (int i = 0; i < n; i++)
    {
        cin>>val;
        st.push(val);
    }
    stack<int>ans = sortstack(st);
    while (!ans.empty())
    {
        cout<<ans.top()<<" ";
        ans.pop();
    }
    return 0;
}