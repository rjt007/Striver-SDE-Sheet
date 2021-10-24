//Four-Sum
//https://leetcode.com/problems/4sum/
#include<bits/stdc++.h>
using namespace std;

/* //Method1: Brute Force
//T.C->O(N^3*log(N)) & S.C->O(N)
void fourSum(vector<int>v, int target)
{
    sort(v.begin(),v.end());
    int n = v.size();
    set<vector<int>>st;
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            for (int k = j+1; k < n; k++)
            {
                int target2 = target-(v[i]+v[j]+v[k]);
                if(binary_search(v.begin()+k+1,v.end(),target2))
                {
                    vector<int>temp(4,0);
                    temp[0] = v[i];
                    temp[1] = v[j];
                    temp[2] = v[k];
                    temp[3] = target2;
                    st.insert(temp);
                }
            }
        }
    }
    for (auto x:st)
    {
        for (int i = 0; i < 4; i++)
        {
            cout<<x[i]<<" ";
        }
        cout<<endl;
    }

} */
//Method1: Using Two Pointers & 2-Sum logic
//T.C->O(N^3) & S.C->O(1)
void fourSum(vector<int>v, int target)
{
    sort(v.begin(),v.end());
    int n = v.size();
    vector<vector<int>>ans;
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            int left = j+1;
            int right = n-1;
            int target2 = target - (v[i]+v[j]);
            while(left<right)
            {
                if(v[left]+v[right]>target2)
                {
                    right--;
                }
                else if (v[left] + v[right] < target2)
                {
                    left++;
                }
                else
                {
                    vector<int> temp(4, 0);
                    temp[0] = v[i];
                    temp[1] = v[j];
                    temp[2] = v[left];
                    temp[3] = v[right];
                    ans.push_back(temp);

                    while (left<right && v[left]==temp[2])
                    {
                        left++;
                    }
                    while (left<right && v[right]==temp[3])
                    {
                        right--;
                    }
                }
            }
            while (j+1<n && v[j]==v[j+1])
            {
                j++;
            }
        }
        while (i + 1 < n && v[i] == v[i + 1])
        {
            i++;
        }
    }
    for (auto x:ans)
    {
        for (int i = 0; i < 4; i++)
        {
            cout<<x[i]<<" ";
        }
        cout<<endl;
    }

}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    int target;
    cin>>target;
    fourSum(v,target);
    return 0;
}