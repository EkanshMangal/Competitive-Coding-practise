#include<bits/stdc++.h>
using namespace std;
int main()
{
	int k=3;
    vector<int> vec={5,6,7,8,9};
    priority_queue<pair<int,int>> maxh;
    for(int i=0;i<vec.size();i++)
    {
        maxh.push({(abs(vec[i]-7)),vec[i]});
        if(maxh.size()>k)
        {
            maxh.pop();
        }
    }
    while(maxh.size()>0)
    {
        cout<<maxh.top().second<<" ";
        maxh.pop();
    }
    
}