#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

vector<vector<int>> addZerosInLast(vector<vector<int>> mat, int n) {
    int max_size = 1;
    while (max_size < n) {
        max_size *= 2; // Increase size to next power of 2
    }

  
    while (mat.size() < max_size) {
        mat.push_back(vector<int>(n, 0));
    }

   
    for (int i = 0; i < max_size; ++i) {
        while (mat[i].size() < max_size) {
            mat[i].push_back(0);
        }
    }

    return mat;
}

vector<vector<int>> addMatrix(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> result(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
    return result;
}

vector<vector<int>> subtractMatrix(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> result(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            result[i][j] = A[i][j] - B[i][j];
        }
    }
    return result;
}

vector<vector<int>> strassenMultiply(vector<vector<int>> A, vector<vector<int>> B) {
    int n = A.size();
    
   
    if (n == 2) {
        vector<vector<int>> result(2, vector<int>(2, 0));
        result[0][0] = A[0][0] * B[0][0] + A[0][1] * B[1][0];
        result[0][1] = A[0][0] * B[0][1] + A[0][1] * B[1][1];
        result[1][0] = A[1][0] * B[0][0] + A[1][1] * B[1][0];
        result[1][1] = A[1][0] * B[0][1] + A[1][1] * B[1][1];
        return result;
    }

    int half = n / 2;

    // Divide A and B into submatrices
    vector<vector<int>> A11(half, vector<int>(half, 0)), A12(half, vector<int>(half, 0)),
                        A21(half, vector<int>(half, 0)), A22(half, vector<int>(half, 0));
    vector<vector<int>> B11(half, vector<int>(half, 0)), B12(half, vector<int>(half, 0)),
                        B21(half, vector<int>(half, 0)), B22(half, vector<int>(half, 0));

    for (int i = 0; i < half; ++i) {
        for (int j = 0; j < half; ++j) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + half];
            A21[i][j] = A[i + half][j];
            A22[i][j] = A[i + half][j + half];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + half];
            B21[i][j] = B[i + half][j];
            B22[i][j] = B[i + half][j + half];
        }
    }

    // Compute the 7 products using Strassen's algorithm
    vector<vector<int>> P1 = strassenMultiply(A11, subtractMatrix(B12, B22));
    vector<vector<int>> P2 = strassenMultiply(addMatrix(A11, A12), B22);
    vector<vector<int>> P3 = strassenMultiply(addMatrix(A21, A22), B11);
    vector<vector<int>> P4 = strassenMultiply(A22, subtractMatrix(B21, B11));
    vector<vector<int>> P5 = strassenMultiply(addMatrix(A11, A22), addMatrix(B11, B22));
    vector<vector<int>> P6 = strassenMultiply(subtractMatrix(A12, A22), addMatrix(B21, B22));
    vector<vector<int>> P7 = strassenMultiply(subtractMatrix(A11, A21), addMatrix(B11, B12));

    // Compute the submatrices of the result
    vector<vector<int>> C11 = addMatrix(subtractMatrix(addMatrix(P5, P4), P2), P6);
    vector<vector<int>> C12 = addMatrix(P1, P2);
    vector<vector<int>> C21 = addMatrix(P3, P4);
    vector<vector<int>> C22 = addMatrix(subtractMatrix(addMatrix(P5, P1), P3), P7);

    // Combine the submatrices into one final result matrix
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

int main() {
    vector<vector<int>> A = {
        {1, 3, 4},
        {5, 6, 8},
        {1, 8, 4}
    };
    
    vector<vector<int>> B = {
        {1, 2, 1},
        {2, 2, 4},
        {3, 3, 8}
    };
    
    A = addZerosInLast(A, 3); // Ensure matrix size is a power of 2
    B = addZerosInLast(B, 3); // Ensure matrix size is a power of 2
    
    vector<vector<int>> result = strassenMultiply(A, B);

    // Print the result
    for (const auto& row : result) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
