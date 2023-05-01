#include <chrono>
#include<iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <fstream>
#include "hw3_p1_header.hpp"

double rand_double(double min, double max) {
    double random_double = static_cast<double>(std::rand()) / static_cast<double>(RAND_MAX);
    return min + random_double * (max - min);
}

template <typename T>
void testing(void (*func)(T, const std::vector<T>&, const std::vector<T>&, T, std::vector<T>&, int, int, int), const std::string& output_filename) {
    //initialization
    int ntrial = 10;
    std::srand(std::time(0));
    std::ofstream outfile(output_filename);

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
        double MFLOPs = (2.0 * n * n * n + 2.0 * n * n) / (avg_time);
        std::cout << "n = " << n << ", MFLOPs = " << MFLOPs << std::endl;
        outfile << n << ", " << MFLOPs << std::endl;
    }
    outfile.close();
}

int main() {
    std::cout << "Running " << "kij" << std::endl;
    testing<double>(mm_kij<double>, "kij_results_math_double.txt");
    std::cout << "Running " << "jki" << std::endl;
    testing<double>(mm_jki<double>, "jki_results_math_double.txt");

    return 0;
}