#include <chrono>
#include<iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
#include "hw3_p1_header.hpp"

double rand_double(double min, double max) {
    double random_double = static_cast<double>(std::rand()) / static_cast<double>(RAND_MAX);
    return min + random_double * (max - min);
}

template <typename T>
void testing(void (*func)(T, const std::vector<T>&, const std::vector<T>&, T, std::vector<T>&, int, int, int)) {
    //initialization
    int ntrial = 3;
    std::srand(std::time(0));

    for (int n = 2; n <= 512; n++) {
        //allocate memories
        std::vector<T> A(n*n);
        std::vector<T> B(n*n);
        std::vector<T> C(n*n);
        T alpha = rand_double(0.0, 1.0);
        T beta = rand_double(0.0, 1.0);

        for (int i = 0; i < n*n; i++) {
            A[i] = rand_double(0.0, 1.0);
            B[i] = rand_double(0.0, 1.0);
            C[i] = rand_double(0.0, 1.0);
        }
    
        auto start = std::chrono::high_resolution_clock::now();
        for (int trial = 0; trial < ntrial; trial++) {
            func(alpha, A, B, beta, C, n, n, n);
        }
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
        double avg_time = duration / static_cast<double>(ntrial);

        std::cout << "n = " << n << ", avg_time (s) = " << avg_time * 1e-6 << std::endl;
    }
}

int main() {
    std::cout << "Running " << "kij" << std::endl;
    testing<float>(mm_kij<float>);
    std::cout << "Running " << "jki" << std::endl;
    testing<float>(mm_jki<float>);

    return 0;
}