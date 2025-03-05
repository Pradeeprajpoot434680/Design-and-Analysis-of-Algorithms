#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int a,b;
    cout<<"Enter the value of a:";
    cin>>a;
    cout<<"Enter the value of b:";
    cin>>b;
    int p;
    cout<<"Enter the value of p:";
    cin>>p;
    //formula for calculating the 
    float k;
    k = log10(a)/log10(b);
    // cout<<" value of k is:"
    // now compare with the p
    if(k>p)
    {
        cout<<"Dominating complexity of the program is  O(N^"<<k<<")";
    }
    else if(p==k)
    {
        cout<<"Dominating complexity of the program is  O(N^"<<k<<".logN)";
    }
    else
    {
        cout<<"Dominating complexity of the program is  O(N^"<<p<<")";
    }
    return 0;
}