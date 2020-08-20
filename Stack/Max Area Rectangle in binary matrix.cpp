#include<bits/stdc++.h>
using namespace std;
int mah(vector<int> arr, int size)
{
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
    
    for(i=0;i<size;i++)
    {   
        ansvector.push_back((v_right[size-i-1]-v_left[i]-1)*arr[i]);
    }
    return *max_element(ansvector.begin(),ansvector.end());
}
int main()
{
    int arr[4][4],i,j;
    for(int i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            cin>>arr[i][j];
        }
    }
    vector<int> v1;
    int size=4;
    for(int i=0;i<4;i++)
    {
        v1.push_back(arr[0][i]);
    }
    int max1=mah(v1,size);
    for(int i=1;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(arr[i][j]==0)
            {
                v1[j]=0;
            }
            else
            {
                v1[j]+=arr[i][j];
            }
        }
        int val=mah(v1,size);
        max1=max(max1,val);
    }
    
    cout<<max1;
         
}