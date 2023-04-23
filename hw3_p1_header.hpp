#include <vector>

template<typename T>
void mm_ijk(T alpha, const std::vector<T>& A, const std::vector<T>& B, T beta, std::vector<T>& C, int m, int p, int n);

template<typename T>
void mm_ikj(T alpha, const std::vector<T>& A, const std::vector<T>& B, T beta, std::vector<T>& C, int m, int p, int n);

template<typename T>
void mm_jik(T alpha, const std::vector<T>& A, const std::vector<T>& B, T beta, std::vector<T>& C, int m, int p, int n);

template<typename T>
void mm_jki(T alpha, const std::vector<T>& A, const std::vector<T>& B, T beta, std::vector<T>& C, int m, int p, int n);

template<typename T>
void mm_kij(T alpha, const std::vector<T>& A, const std::vector<T>& B, T beta, std::vector<T>& C, int m, int p, int n);

template<typename T>
void mm_kji(T alpha, const std::vector<T>& A, const std::vector<T>& B, T beta, std::vector<T>& C, int m, int p, int n);