#include <iostream>

using namespace std;

// Function to add two matrices (2x2)
void addMatrix(int A[2][2], int B[2][2], int result[2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}

// Function to subtract two matrices (2x2)
void subtractMatrix(int A[2][2], int B[2][2], int result[2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            result[i][j] = A[i][j] - B[i][j];
        }
    }
}

// Function to multiply two 2x2 matrices
void multiply2x2(int A[2][2], int B[2][2], int result[2][2]) {
    result[0][0] = A[0][0] * B[0][0] + A[0][1] * B[1][0];
    result[0][1] = A[0][0] * B[0][1] + A[0][1] * B[1][1];
    result[1][0] = A[1][0] * B[0][0] + A[1][1] * B[1][0];
    result[1][1] = A[1][0] * B[0][1] + A[1][1] * B[1][1];
}

// Strassen's algorithm to multiply two 4x4 matrices
void strassenMultiply4x4(int A[4][4], int B[4][4], int result[4][4]) {
    // Temporary matrices for Strassen's algorithm
    int A11[2][2], A12[2][2], A21[2][2], A22[2][2];
    int B11[2][2], B12[2][2], B21[2][2], B22[2][2];
    int P1[2][2], P2[2][2], P3[2][2], P4[2][2];
    int P5[2][2], P6[2][2], P7[2][2];
    int temp1[2][2], temp2[2][2];

    // Split matrices A and B into 2x2 submatrices
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + 2];
            A21[i][j] = A[i + 2][j];
            A22[i][j] = A[i + 2][j + 2];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + 2];
            B21[i][j] = B[i + 2][j];
            B22[i][j] = B[i + 2][j + 2];
        }
    }

    // Compute the 7 products using Strassen's method
    // P1 = (A11 + A22) * (B11 + B22)
    addMatrix(A11, A22, temp1);
    addMatrix(B11, B22, temp2);
    multiply2x2(temp1, temp2, P1);

    // P2 = (A21 + A22) * B11
    addMatrix(A21, A22, temp1);
    multiply2x2(temp1, B11, P2);

    // P3 = A11 * (B12 - B22)
    subtractMatrix(B12, B22, temp2);
    multiply2x2(A11, temp2, P3);

    // P4 = A22 * (B21 - B11)
    subtractMatrix(B21, B11, temp2);
    multiply2x2(A22, temp2, P4);

    // P5 = (A11 + A12) * B22
    addMatrix(A11, A12, temp1);
    multiply2x2(temp1, B22, P5);

    // P6 = (A21 - A11) * (B11 + B12)
    subtractMatrix(A21, A11, temp1);
    addMatrix(B11, B12, temp2);
    multiply2x2(temp1, temp2, P6);

    // P7 = (A12 - A22) * (B21 + B22)
    subtractMatrix(A12, A22, temp1);
    addMatrix(B21, B22, temp2);
    multiply2x2(temp1, temp2, P7);

    // Compute the result matrix C (4x4) from the 7 products
    int C11[2][2], C12[2][2], C21[2][2], C22[2][2];

    // C11 = P1 + P4 - P5 + P7
    addMatrix(P1, P4, temp1);
    subtractMatrix(temp1, P5, temp2);
    addMatrix(temp2, P7, C11);

    // C12 = P3 + P5
    addMatrix(P3, P5, C12);

    // C21 = P2 + P4
    addMatrix(P2, P4, C21);

    // C22 = P1 + P3 - P2 + P6
    addMatrix(P1, P3, temp1);
    subtractMatrix(temp1, P2, temp2);
    addMatrix(temp2, P6, C22);

    // Combine the submatrices into the final result matrix
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            result[i][j] = C11[i][j];
            result[i][j + 2] = C12[i][j];
            result[i + 2][j] = C21[i][j];
            result[i + 2][j + 2] = C22[i][j];
        }
    }
}

int main() {
    int A[3][3], B[3][3], A4x4[4][4] = {0}, B4x4[4][4] = {0}, result[4][4];

    // Input elements for the first 3x3 matrix (A)
    cout << "Enter the elements of the first 3x3 matrix (A):\n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << "Enter element [" << i + 1 << "][" << j + 1 << "]: ";
            cin >> A[i][j];
        }
    }

    // Extend the 3x3 matrix A to a 4x4 matrix (A4x4)
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            A4x4[i][j] = A[i][j];
        }
    }

    // Input elements for the second 3x3 matrix (B)
    cout << "\nEnter the elements of the second 3x3 matrix (B):\n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << "Enter element [" << i + 1 << "][" << j + 1 << "]: ";
            cin >> B[i][j];
        }
    }

    // Extend the 3x3 matrix B to a 4x4 matrix (B4x4)
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            B4x4[i][j] = B[i][j];
        }
    }

    // Perform Strassen's matrix multiplication on the extended 4x4 matrices
    strassenMultiply4x4(A4x4, B4x4, result);

    // Display the result matrix
    cout << "\nThe result of matrix multiplication (4x4) is:\n";
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    // Extract the 3x3 result (top-left part of the 4x4 result)
    cout << "\nThe final 3x3 result is:\n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
