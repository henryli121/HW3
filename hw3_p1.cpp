#include "hw3_p1_header.hpp"

template<typename T>
void mm_ijk(T alpha, const std::vector<T>& A, const std::vector<T>& B, T beta, std::vector<T>& C, int m, int p, int n) {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            T c_ij = 0;
            for (int k = 0; k < p; ++k) {
                c_ij += A[i + k * m] * B[k + j * p];
            }
            C[i + j * m] = alpha * c_ij + beta * C[i + j * m];
        }
    }
}

template<typename T>
void mm_ikj(T alpha, const std::vector<T>& A, const std::vector<T>& B, T beta, std::vector<T>& C, int m, int p, int n) {
    for (int i = 0; i < m; ++i) {
        for (int k = 0; k < p; ++k) {
            T a_ik = A[i + k * m];
            for (int j = 0; j < n; ++j) {
                C[i + j * m] += a_ik * B[k + j * p];
            }
        }
        for (int j = 0; j < n; ++j) {
            C[i + j * m] = alpha * C[i + j * m] + beta * C[i + j * m];
        }
    }
}

template<typename T>
void mm_jik(T alpha, const std::vector<T>& A, const std::vector<T>& B, T beta, std::vector<T>& C, int m, int p, int n) {
    for (int j = 0; j < n; ++j) {
        for (int i = 0; i < m; ++i) {
            T c_ij = 0;
            for (int k = 0; k < p; ++k) {
                c_ij += A[i + k * m] * B[k + j * p];
            }
            C[i + j * m] = alpha * c_ij + beta * C[i + j * m];
        }
    }
}

template<typename T>
void mm_jki(T alpha, const std::vector<T>& A, const std::vector<T>& B, T beta, std::vector<T>& C, int m, int p, int n) {
    for (int j = 0; j < n; ++j) {
        for (int k = 0; k < p; ++k) {
            T b_kj = B[k + j * p];
            for (int i = 0; i < m; ++i) {
                C[i + j * m] += A[i + k * m] * b_kj;
            }
        }
        for (int i = 0; i < m; ++i) {
            C[i + j * m] = alpha * C[i + j * m] + beta * C[i + j * m];
        }
    }
}

template<typename T>
void mm_kij(T alpha, const std::vector<T>& A, const std::vector<T>& B, T beta, std::vector<T>& C, int m, int p, int n) {
    for (int k = 0; k < p; ++k) {
        for (int i = 0; i < m; ++i) {
            T a_ik = A[i + k * m];
            for (int j = 0; j < n; ++j) {
                C[i + j * m] += a_ik * B[k + j * p];
            }
        }
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            C[i + j * m] = alpha * C[i + j * m] + beta * C[i + j * m];
        }
    }
}

template<typename T>
void mm_kji(T alpha, const std::vector<T>& A, const std::vector<T>& B, T beta, std::vector<T>& C, int m, int p, int n) {
    for (int k = 0; k < p; ++k) {
        for (int j = 0; j < n; ++j) {
            T b_kj = B[k + j * p];
            for (int i = 0; i < m; ++i) {
                C[i + j * m] += A[i + k * m] * b_kj;
            }
        }
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            C[i + j * m] = alpha * C[i + j * m] + beta * C[i + j * m];
        }
    }
}

// Explicit template instantiation
template void mm_ijk<double>(double, const std::vector<double>&, const std::vector<double>&, double, std::vector<double>&, int, int, int);
template void mm_ikj<double>(double, const std::vector<double>&, const std::vector<double>&, double, std::vector<double>&, int, int, int);
template void mm_jik<double>(double, const std::vector<double>&, const std::vector<double>&, double, std::vector<double>&, int, int, int);
template void mm_jki<double>(double, const std::vector<double>&, const std::vector<double>&, double, std::vector<double>&, int, int, int);
template void mm_kij<double>(double, const std::vector<double>&, const std::vector<double>&, double, std::vector<double>&, int, int, int);
template void mm_kji<double>(double, const std::vector<double>&, const std::vector<double>&, double, std::vector<double>&, int, int, int);

