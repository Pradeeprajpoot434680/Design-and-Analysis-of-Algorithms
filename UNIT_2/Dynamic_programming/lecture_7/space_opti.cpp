#include<iostream>
#include<vector>
using namespace std;
int maximumPoints(vector<vector<int>>& arr) 
{
    int n = arr.size();
    vector<int>prev(4,0);
    //base cases
    prev[0] = max(arr[0][1],arr[0][2]);
    prev[1] = max(arr[0][0],arr[0][2]);
    prev[2] = max(arr[0][0],arr[0][1]);
    prev[3] = max(arr[0][1],max(arr[0][0],arr[0][2]));
    // 1->n-1
    for(int day =1; day<n; day++)
    {
        //check posibility for last
        vector<int>curr(4,0);
        for(int last =0; last<4; last++)
        {
            //tasks
            curr[last] = 0;
            int maxi = 0;
            for(int task=0; task<3; task++)
            {
                if(task != last)
                {
                    int point = arr[day][task] + prev[task];
                    curr[last]= max(curr[last],point);
                }
            }
        }
        prev  = curr;
    }
    return prev[3];
}
int main()
{
    int day=10;
    int p=1;
    int q=2;
    int r=3;
    vector<vector<int>>arr(day,vector<int>(3,0));
    for(int i=0; i<day; i++)
    {
       arr[i] = {3*p,q,2*r};
       p*=2;
       q*=4;
    }
    cout<<"Ans is:"<<maximumPoints(arr);
}