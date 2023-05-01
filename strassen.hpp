#ifndef STRASSEN_HPP
#define STRASSEN_HPP

#include <vector>
using namespace std;

template <typename T>
vector<vector<T>> add(const vector<vector<T>> &A, const vector<vector<T>> &B);

template <typename T>
vector<vector<T>> subtract(const vector<vector<T>> &A, const vector<vector<T>> &B);

template <typename T>
vector<vector<T>> strassen_mm(const vector<vector<T>> &A, const vector<vector<T>> &B);

#endif // STRASSEN_HPP
