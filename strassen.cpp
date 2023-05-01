#include "strassen.hpp"
#include <vector>
using namespace std;

template <typename T>
vector<vector<T>> add(const vector<vector<T>> &A, const vector<vector<T>> &B) {
    size_t n = A.size();
    vector<vector<T>> C(n, vector<T>(n, 0));
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    return C;
}

template <typename T>
vector<vector<T>> subtract(const vector<vector<T>> &A, const vector<vector<T>> &B) {
    size_t n = A.size();
    vector<vector<T>> C(n, vector<T>(n, 0));
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
    return C;
}

template <typename T>
vector<vector<T>> strassen_mm(const vector<vector<T>> &A, const vector<vector<T>> &B) {
    size_t n = A.size();
    //basecase:
    if (n == 1) {
        vector<vector<T>> C(n, vector<T>(n, 0));
        C[0][0] = A[0][0] * B[0][0];
        return C;
    }   else {

    size_t sizes = n / 2;
    vector<vector<T>> A11(sizes, vector<T>(sizes, 0)), A12(sizes, vector<T>(sizes, 0)), A21(sizes, vector<T>(sizes, 0)), A22(sizes, vector<T>(sizes, 0));
    vector<vector<T>> B11(sizes, vector<T>(sizes, 0)), B12(sizes, vector<T>(sizes, 0)), B21(sizes, vector<T>(sizes, 0)), B22(sizes, vector<T>(sizes, 0));
    
    for (size_t i = 0; i < sizes; i++) {
        for (size_t j = 0; j < sizes; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + sizes];
            A21[i][j] = A[i + sizes][j];
            A22[i][j] = A[i + sizes][j + sizes];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + sizes];
            B21[i][j] = B[i + sizes][j];
            B22[i][j] = B[i + sizes][j + sizes];
        }
    }
    
    auto M1 = strassen_mm(add(A11, A22), add(B11, B22));
    auto M2 = strassen_mm(add(A21, A22), B11);
    auto M3 = strassen_mm(A11, subtract(B12, B22));
    auto M4 = strassen_mm(A22, subtract(B21, B11));
    auto M5 = strassen_mm(add(A11, A12), B22);
    auto M6 = strassen_mm(subtract(A21, A11), add(B11, B12));
    auto M7 = strassen_mm(subtract(A12, A22), add(B21, B22));

    auto C11 = add(subtract(add(M1,M4), M5), M7);
    auto C12 = add(M3, M5);
    auto C21 = add(M2, M4);
    auto C22 = add(add(subtract(M1,M2), M3), M6);
    
    vector<vector<T>> C(n, vector<T>(n, 0));
    for (size_t i = 0; i < sizes; i++) {
        for (size_t j = 0; j < sizes; j++) {
            C[i][j] = C11[i][j];
            C[i][j + sizes] = C12[i][j];
            C[i+sizes][j] = C21[i][j];
            C[i+sizes][j+sizes] = C22[i][j];
        }
    }

    return C;
    }
}


template vector<vector<double>> add(const vector<vector<double>> &, const vector<vector<double>> &);
template vector<vector<double>> subtract(const vector<vector<double>> &, const vector<vector<double>> &);
template vector<vector<double>> strassen_mm(const vector<vector<double>> &, const vector<vector<double>> &);