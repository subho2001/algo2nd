#include <iostream>
#include <climits>

using namespace std;

// Function to compute the optimal order of matrix multiplication
void matrixChainOrder(int p[], int n, int** m, int** s) {
    // Initialize m[i][i] to 0
    for (int i = 1; i <= n; i++) {
        m[i][i] = 0;
    }

    // Calculate the minimum number of multiplications needed
    for (int length = 2; length <= n; length++) {
        for (int i = 1; i <= n - length + 1; i++) {
            int j = i + length - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
}

// Function to print the optimal parenthesization
void printOptimalParens(int** s, int i, int j) {
    if (i == j) {
        cout << "A" << i;
    } else {
        cout << "(";
        printOptimalParens(s, i, s[i][j]);
        printOptimalParens(s, s[i][j] + 1, j);
        cout << ")";
    }
}

int main() {
    int n;

    cout << "Enter the number of matrices: ";
    cin >> n;

    int* p = new int[n + 1];
    cout << "Enter the dimensions of the matrices:\n";
    for (int i = 0; i <= n; i++) {
        cout << "p[" << i << "]: ";
        cin >> p[i];
    }

    // Allocate memory for matrices m and s
    int** m = new int*[n + 1];
    int** s = new int*[n + 1];
    for (int i = 0; i <= n; i++) {
        m[i] = new int[n + 1];
        s[i] = new int[n + 1];
    }

    // Compute optimal order and print results
    matrixChainOrder(p, n, m, s);

    cout << "Minimum number of multiplications is " << m[1][n] << endl;
    cout << "Optimal parenthesization is: ";
    printOptimalParens(s, 1, n);
    cout << endl;

    // Deallocate memory
    for (int i = 0; i <= n; i++) {
        delete[] m[i];
        delete[] s[i];
    }
    delete[] m;
    delete[] s;
    delete[] p;

    return 0;
}
