#include<iostream>
using namespace std;
#include<vector>
int func(int n,vector<int>&dp)
{
    if(n<=1)return n;
    if(dp[n]!=-1)return dp[n];

    return dp[n]= func(n-1,dp)+func(n-2,dp);
}
int main()
{
    int n=6;
    vector<int>dp(n+1,-1);
    int p =func(n,dp);
    cout<<"Ans is:"<<p;
    return 0;
}