#include <iostream>
#include <vector>
#include <random>
#include <fstream>
#include "strassen.hpp"

using namespace std;
random_device rd;
mt19937 gen(rd());

template <typename T>
vector<vector<T>> rand_matrix(int m, int n) {
    vector<vector<T>> A(m, vector<T>(n));
    uniform_real_distribution<double> dist(0.0, 1.0);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = dist(gen);
        }
    }
    return A;
}

int main() {
    int n_min = 2;
    int n_max = 512;
    int ntrial = 5;
    ofstream outfile("p3_results.txt");
    
    for (int n = n_min; n <= n_max; n *= 2) {
        auto A = rand_matrix<double>(n, n);
        auto B = rand_matrix<double>(n, n);

        auto start = chrono::high_resolution_clock::now();
        for (int trial = 0; trial < ntrial; trial++) {
        auto C = strassen_mm(A, B);
        }
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(end - start).count();
        double avg_time = duration / static_cast<double>(ntrial);
        double MFLOPs = (7.0 * n * n * n / 4.0 + 9.0 * n * n / 2.0) / (avg_time);
        std::cout << "n = " << n << ", MFLOPs = " << MFLOPs << std::endl;
        outfile << n << ", " << MFLOPs << std::endl;

    }
    outfile.close();
    return 0;
}

