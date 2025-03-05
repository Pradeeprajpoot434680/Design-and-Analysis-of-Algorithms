#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int> makeSortedList(vector<vector<int>>&lists)
{
    priority_queue<int,vector<int>,greater<int> >pq;
    for(int i=0; i<lists.size(); i++)
    {
        for(int j=0; j<lists[i].size(); j++)
        {
            pq.push(lists[i][j]);
        }
    }
    vector<int>ans;
    while (!pq.empty())
    {
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}
int main()
{   
    // i have m sorted line
    vector<int>list1={1,4,7,9,12};
    vector<int>list2={23,34};
    vector<int>list3={2,4,5,6,10,15,19};
    vector<int>list4={12,13,18,22};
    vector<int>list5={56};
    vector<vector<int>>lists;
    lists.push_back(list1);
    lists.push_back(list2);
    lists.push_back(list3);
    lists.push_back(list4);
    lists.push_back(list5);
    vector<int>ans = makeSortedList(lists);
    //make a function to do this task
    for(int i=0; i<ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}