#include<iostream>
#include<vector>
using namespace std;
int f(int day,int last,vector<vector<int>>& arr,vector<vector<int>>&dp)
{
    // base case
    if(day==0)
    {
        int maxi =0;
        for(int task=0; task<3; task++)
        {
            if(task !=last)
            {
                maxi = max(maxi,arr[day][task]);
            }
        }
        return maxi;
    }
    int maxi =0;
    int point =0;
    if(dp[day][last] != -1)return dp[day][last];
    for(int task=0; task<3; task++)
    {
        if(task != last)
        {
             point= arr[day][task] + f(day-1,task,arr,dp);

        }
        maxi = max(maxi,point);
    }

    return dp[day][last]=maxi;
}
int maximumPoints(vector<vector<int>>& arr) 
{
    int n = arr.size();
    vector<vector<int>>dp(n,vector<int>(4,-1));
    return f(n-1,3,arr,dp);    
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