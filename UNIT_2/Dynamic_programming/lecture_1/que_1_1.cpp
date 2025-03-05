#include<iostream>
using namespace std;
#include<vector>

// int main()
// {
//     int n;
//     cout<<"Enter the value of n:";
//     cin>>n;
//     vector<int>dp(n+1,-1);
//     dp[0]=0;
//     dp[1]=1;
//     for(int i=2; i<=n; i++)
//     {
//         dp[i] = dp[i-1] + dp[i-2];
//     }
//     cout<<"Ans is:"<<dp[n];
//     return 0;
// }
// instead of dp[i-1] + dp[i-2] => prev1+ prec2

int main()
{
    int n;
    cout<<"Enter the value of n:";
    cin>>n;
    vector<int>dp(n+1,-1);
   int prev1 = 0;
   int prev2 = 1;
   int curr;
    for(int i=2; i<=n; i++)
    {
        curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
        cout<<curr<<" ";
    }
    return 0;
}