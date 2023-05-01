# Matrix Multiplication Loop Permutations

This project implements matrix multiplication using different loop permutations (ijk, ikj, jik, jki, kij, kji) in C++. It also includes a performance test program to measure the execution time of the kij and jki loop permutations with random input data.

## Files

- hw3_p1_header.hpp: Header file containing the template function declarations for each loop permutation.
- hw3_p1.cpp: Source file containing the template function definitions for each loop permutation.
- main.cpp: Main program to test the performance of kij and jki loop permutations using random input data.

## Compilation

To compile the project with different optimization levels, use the following commands:

1. No optimization:

~~~
g++ -std=c++11 -o main_no_opt main.cpp hw3_p1.cpp
~~~

2. -O3 optimization:

~~~
g++ -std=c++11 -O3 -o main_O3 main.cpp hw3_p1.cpp
~~~

3. -ffast-math optimization:

~~~
g++ -std=c++11 -O3 -ffast-math -o main_ffast_math main.cpp hw3_p1.cpp
~~~

## Execution

After compilation, you can run the compiled programs and observe the results.

1. No optimization:

~~~
./main_no_opt
~~~

2. -O3 optimization:

~~~
./main_O3
~~~

3. -ffast-math optimization:

~~~
./main_ffast_math
~~~

The output will display the average execution time (in seconds) for each matrix size (n) from 2 to 512.

## Problem 3: Strassen Matrix Multiplication

This project implements a C++ template for the recursive Strassen matrix multiplication algorithm.
We will then analyze the performance of our implementation by measuring the 
double precision performance for square matrices of even dimensions, ranging from n = 2 to n = 512.

### Files

- `strassen.hpp`: Header file containing the template function declarations for Strassen algorithm.
- `strassen.cpp`: Source file containing the template function definitions for Strassen algorithm.
- `main_p3.cpp`: Main program to test the performance of Strassen algorithm using random input data.

### Compilation and Execution

~~~
g++ -std=c++11 -Ofast -o test_strassen main_p3.cpp strassen.cpp
./test_strassen
~~~


**Note:** All plot results are in the hw3.pdf file.
