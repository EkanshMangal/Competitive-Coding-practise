#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> vec={1,2,3,4,5};
    priority_queue<int,vector<int>,greater<int>> minh;
    for(int i=0;i<vec.size();i++)
    {
        minh.push(vec[i]);
    }
    int sum=0;
    while(minh.size()>1)
    {
        int a=minh.top();
        minh.pop();
        int b=minh.top();
        minh.pop();
        minh.push(a+b);
        sum=sum+(a+b);
    }
    cout<<sum;
    
}