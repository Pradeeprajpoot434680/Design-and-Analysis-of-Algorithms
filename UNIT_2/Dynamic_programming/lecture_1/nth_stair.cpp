#include<iostream>
using namespace std;
#include<vector>
int main()
{
    int n;
    cout<<"Enter the number of stairs:";
    cin>>n;
    int prev1=2;
    int prev2 = 1;
    if(n<=2)
    {
        cout<<"Ans is:"<<n;
        return 0;
    }
    int curr ;
    for(int i=3; i<=n; i++)
    {
        curr = prev1 + prev2;
        prev2 =prev1;
        prev1 = curr;
    }
    cout<<"Ans is:"<< curr;
}