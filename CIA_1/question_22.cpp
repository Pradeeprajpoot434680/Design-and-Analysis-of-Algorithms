#include<iostream>
#include<vector>
using namespace std;
vector<int> makeSortedList(vector<int>l1,vector<int>l2)
{
    int first=0;
    int second=0;
    vector<int>ans(l1.size()+l2.size());
    int index =0;
    while(first<l1.size() && second<l2.size())
    {
        if(l1[first]<= l2[second])
        {
            ans[index]=l1[first];
            index++;
            first++;
        }
        else
        {
            ans[index]=l2[second];
            index++;
            second++;
        }
    }
    while(first<l1.size())
    {
        ans[index]=l1[first];
        first++;
        index++;
    }
    while(second<l2.size())
    {
        ans[index]= l2[second];
        index++;
        second++;
    }
    return ans;
}
int main()
{
    int m;
    cout<<"Enter the number of lists:";
    cin>>m;
    int n;
    cout<<"Enter the value of tatal elements:";
    cin>>n;
    if(m>n)
    {
        cout<<"Number of lists are greater than total element";
        return 0;
    }
   
    vector<int>arr(n);
    for(int i=0; i<n; i++)
    {
        cout<<"enter the :"<<i+1<<"th emelent:";
        cin>>arr[i];
    }
    vector<vector<int>>lists;
    for(int i=0; i<m; i++)
    {
        vector<int>list;
        lists.push_back(list);
    }

    
    int p =0;
    while(p<arr.size())
    {
        for(int i=0; i<m; i++)
        {
            if(p<arr.size())
            lists[i].push_back(arr[p]);
            p++;
        }
    }
    int i=0;
    vector<int>sorted;
    sorted = lists[0];
    while(i<m-1)
    {
        vector<int>ans = makeSortedList(sorted,lists[i+1]);
        sorted = ans;
        i++;
    }
    for(int i=0; i<sorted.size(); i++)
    {
        cout<<sorted[i]<<" ";
    }
    return 0;
    
}