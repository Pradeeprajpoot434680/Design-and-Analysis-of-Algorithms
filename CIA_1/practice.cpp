#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
// if size is not in the oower of 2^n then convert it into 2^n
void addPadding(vector<vector<int>>&mat,int n)
{
    int max_size = 1;
    while(max_size < n)
    {
        max_size *=2;
    }
    for(int i=n; i<max_size; i++)
    {
        mat.push_back(vector<int>(n,0));
    }
    for(int i=0; i<max_size; i++)
    {
        for(int j=n; j<max_size; j++)
        {
            mat[i].push_back(0);
        }
    }
}

// for space optimization i will store added matrix in A and return A
// because this func call is call my value
vector<vector<int>> subtractMatrix(vector<vector<int>>A,vector<vector<int>>B)
{
    vector<vector<int>>result(A.size(),vector<int>(A[0].size(),0));
    for(int i=0; i<A.size(); i++)
    {
        for(int j=0; j<A[i].size(); j++)
        {
            result[i][j] = A[i][j] - B[i][j];
        }
    }
    
    return result;
}

vector<vector<int>> addMatrix(vector<vector<int>>A,vector<vector<int>>B)
{
    vector<vector<int>>result(A.size(),vector<int>(A[0].size(),0));
    for(int i=0; i<A.size(); i++)
    {
        for(int j=0; j<A[i].size(); j++)
        {
            //A[i][j]=A[i][j] + B[i][j];
            result[i][j] = A[i][j] + B[i][j];
        }
    }
    //return A
    return result;
}
vector<vector<int>> Divide(vector<vector<int>>A,vector<vector<int>> B)
{
    int n = A.size();
    // martix is  size of 2 then multiply
    if(n<=2)
    {
        vector<vector<int>> result(2, vector<int>(2, 0));
        result[0][0] = A[0][0]*B[0][0] + A[0][1]*B[1][0];
        result[0][1] = A[0][0]*B[0][1] + A[0][1]*B[1][1];
        result[1][0] = A[1][0]*B[0][0] + A[1][1]*B[1][0];
        result[1][1] = A[1][0]*B[0][1] + A[1][1]*B[1][1];
        return result;
    }
    int half = n /2;
    // divide a matrix into four parts
    // 1   2 |  3   4
    // 5   6 |  7   8
    //----------------
    // 3   2 |  6   9
    // 5   2 |  8   1
    vector<vector<int>> A11(half,vector<int>(half,0)),A12(half,vector<int>(half,0)),
                        A21(half,vector<int>(half,0)),A22(half,vector<int>(half,0));

    vector<vector<int>> B11(half, vector<int>(half, 0)), B12(half, vector<int>(half, 0)), 
                        B21(half, vector<int>(half, 0)), B22(half, vector<int>(half, 0));

    // 0   0
    // 0   0

    for(int i=0; i<half; i++)
    for(int j=0; j<half; j++)
    {
        A11[i][j] = A[i][j];
        A12[i][j] = A[i][j+half];
        A11[i][j] = A[i+half][j];
        A11[i][j] = A[i+half][j+half];
    }

    for(int i=0; i<half; i++)
    for(int j=0; j<half; j++)
    {
        B11[i][j] = B[i][j];
        B12[i][j] = B[i][j+half];
        B11[i][j] = B[i+half][j];
        B11[i][j] = B[i+half][j+half];
    }
    // make the matrixes using the strassenMultiply 
    vector<vector<int>> P1 = Divide(A11,subtractMatrix(B12,B22));
    vector<vector<int>> P2 = Divide(addMatrix(A11,A12),B22);
    vector<vector<int>> P3 = Divide(addMatrix(A21, A22), B11);
    vector<vector<int>> P4 = Divide(A22, subtractMatrix(B21, B11));
    vector<vector<int>> P5 = Divide(addMatrix(A11, A22), addMatrix(B11, B22));
    vector<vector<int>> P6 = Divide(subtractMatrix(A12, A22), addMatrix(B21, B22));
    vector<vector<int>> P7 = Divide(subtractMatrix(A11, A21), addMatrix(B11, B12));

    vector<vector<int>> C11 = addMatrix(subtractMatrix(addMatrix(P5, P4), P2), P6);
    vector<vector<int>> C12 = addMatrix(P1, P2);
    vector<vector<int>> C21 = addMatrix(P3, P4);
    vector<vector<int>> C22 = addMatrix(subtractMatrix(addMatrix(P5, P1), P3), P7);
    //  
    //  C11   C12
    //  C21   C22
    
    // merge these matrix into the n
    vector<vector<int>> C(n, vector<int>(n, 0));

    for (int i = 0; i < half; ++i) {
        for (int j = 0; j < half; ++j) {
            C[i][j] = C11[i][j];
            C[i][j + half] = C12[i][j];
            C[i + half][j] = C21[i][j];
            C[i + half][j + half] = C22[i][j];
        }
    }
    
    return C;

}
int main()
{
    vector<vector<int>> A = {
        {1, 3, 4},
        {5, 6, 8},
        {1, 8, 4}
    };
    addPadding(A,3);
    for (const auto& row : A) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

}