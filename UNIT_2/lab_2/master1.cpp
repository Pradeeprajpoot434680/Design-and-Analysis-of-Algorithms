#include <iostream>
#include <cmath>

using namespace std;

// Function to calculate log base b of a
double logBase(double a, double b) {
    return log(a) / log(b);
}

// Function to analyze the recurrence relation
void analyzeRecurrence(int a, int b, int n, int f_n) {
    double logValue = logBase(a, b);
    double n_log = pow(n, logValue);

    cout << "Analyzing T(n) = " << a << "T(n/" << b << ") + f(n)" << endl;
    cout << "n^log_b(a) = n^" << logValue << " = " << n_log << endl;
    cout << "f(n) = " << f_n << endl;

    if (f_n < n_log) {
        cout << "Case 1: T(n) = Θ(n^log_b(a))" << endl;
    } else if (f_n == n_log) {
        cout << "Case 2: T(n) = Θ(n^log_b(a) * log(n))" << endl;
    } else {
        cout << "Case 3: T(n) = Θ(f(n))" << endl;
    }
}

int main() {
    int a = 2; // Number of subproblems
    int b = 2; // Factor by which the problem size is reduced
    int n = 8; // Size of the problem
    int f_n = n; // Example f(n) = n

    analyzeRecurrence(a, b, n, f_n);

    return 0;
}