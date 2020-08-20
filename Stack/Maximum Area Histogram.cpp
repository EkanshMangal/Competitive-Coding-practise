#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> arr={6,2,5,4,5,1,6};
    int size=7;
    int n=size;
    vector<int>v_left;
    stack<pair<int,int>> s_left;
    vector<int>v_right;
    stack<pair<int,int>> s_right;
    vector<int> ansvector;
    int i;
    int index_left=-1;
    int index_right=size;
    for(i=0;i<size;i++)
    {
        if(s_left.size()==0)
        {
            v_left.push_back(index_left);
        }
        else if(s_left.size()!=0 && s_left.top().first <arr[i])
        {
            v_left.push_back(s_left.top().second);
        }
        else if(s_left.size()!=0 && s_left.top().first >=arr[i])
        {
            while(s_left.size()!=0 && s_left.top().first >=arr[i])
            {
                s_left.pop();
            }
            if(s_left.size()==0)
            {
                v_left.push_back(index_left);
            }
            else
            {
                v_left.push_back(s_left.top().second);
            }
        }
        s_left.push({arr[i],i});
    }
    
    for(i=size-1;i>=0;i--)
    {
        if(s_right.size()==0)
        {
            v_right.push_back(index_right);
        }
        else if(s_right.size()!=0 && s_right.top().first <arr[i])
        {
            v_right.push_back(s_right.top().second);
        }
        else if(s_right.size()!=0 && s_right.top().first >=arr[i])
        {
            while(s_right.size()!=0 && s_right.top().first >=arr[i])
            {
                s_right.pop();
            }
            if(s_right.size()==0)
            {
                v_right.push_back(index_right);
            }
            else
            {
                v_right.push_back(s_right.top().second);
            }
        }
        s_right.push({arr[i],i});
    }    
    
    for(i=0;i<n;i++)
    {   
        ansvector.push_back((v_right[n-i-1]-v_left[i]-1)*arr[i]);
    }
    cout<<*max_element(ansvector.begin(),ansvector.end());     
}