#include<iostream>
#include<math.h>
#include<string>

using namespace std;
int main()
{
    string s;
    cout<<"Enter the question without space:";
    cin>>s;
    int a,b,p;
    
    int i=0;
    while(s[i] != 'T')
    {
        i++;
    }
    string A = s.substr(0,i);
    a = stoi(A);
    while(s[i] != '/')
    {
        i++;
    }
    int I=i+1;
    while(s[i] != ')')
    {
        i++;
    }
    string B = s.substr(I,i);
    b=stoi(B);
    while(s[i]!='^')
    {
        i++;
    }
    I = i+1;
    // while( i< s[i] != )
    //formula for calculating the 
    float k;
    k = log10(a)/log10(b);
    string fn = s.substr(8,s.size()-1);
    if(fn.find("logn"))
    {
        cout<<"Can not applied Masters method\n";
        return 0;
    }

    float c = a / pow(b,p);
    if(c>1)
    {
        cout<<"Regularity contidion break.Can n't apply Master's method";
    }
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