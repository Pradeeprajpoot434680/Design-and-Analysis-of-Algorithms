#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int func(int n,vector<int>&arr,vector<int>&dp)
{
    int left,right=1000000000;
    if(n==0)return 0;
    if(dp[n]!=-1)return dp[n];

    left = func(n-1,arr,dp) + abs(arr[n]-arr[n-1]);
    if(n>1)
    right = func(n-2,arr,dp)  +abs(arr[n] - arr[n-2]);

    return dp[n] = min(left,right);

}
// int main()
// {
//     vector<int>arr={30,10,60,10,60,50};
//     vector<int>dp(arr.size()+1,-1);
//     cout<<"Ans is:"<<func(6,arr,dp);
//     return 0;
// }
// tabulation 
// int main()
// {
//     vector<int>arr={30,10,60,10,60,50};
//     int n = 6;
//     vector<int>dp(arr.size(),0);  
//     dp[0] = 0;
//     for(int i=1; i<n; i++)
//     {
//         int fs = dp[i-1] + abs(arr[i]-arr[i-1]);
//         int ss = INT_MAX;
//         if(i>1)
//         ss = dp[i-2] + abs(arr[i]-arr[i-2]);

//         dp[i] = min(fs,ss);
//     } 
//     cout<<"Ans is:"<<dp[n-1];
// }

// using variables
int main()
{
    vector<int>arr={30,10,60,10,60,50};
    int n = 6;
   int prev1=0,prev2 = 0,curr;
   
    for(int i=1; i<n; i++)
    {
        int fs = prev1 + abs(arr[i]-arr[i-1]);
        int ss = INT_MAX;
        if(i>1)
        ss = prev2 + abs(arr[i]-arr[i-2]);

        curr = min(fs,ss);
        prev2 = prev1;
        prev1 = curr;
    } 
    cout<<"Ans is:"<<prev1;
}