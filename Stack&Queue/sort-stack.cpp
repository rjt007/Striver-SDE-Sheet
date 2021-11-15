#include <bits/stdc++.h>
using namespace std;

void sortstack(stack<int>&st)
{
    stack<int>temp;
    while (!st.empty())
    {
        if(temp.empty()){
            temp.push(st.top());
            st.pop();
        } 
        else
        {
            int ele = st.top(); st.pop();
            if(ele<=temp.top())
            {
                temp.push(ele);
            }
            else
            {
                while (!temp.empty())
                {
                    if(ele>temp.top())
                    {
                        st.push(temp.top());
                        temp.pop();
                    }
                    else
                    {
                        temp.push(ele);
                        break;
                    }
                }
            }
        }
    }
    while (!temp.empty())
    {
        st.push(temp.top());
        temp.pop();
    }
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
    sortstack(st);
    while (!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
    return 0;
}