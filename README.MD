<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Matrix Multiplication Loop Permutations</title>
</head>

<body>
    <h1>Matrix Multiplication Loop Permutations</h1>
    <p>This project implements matrix multiplication using different loop permutations (ijk, ikj, jik, jki, kij, kji) in
        C++. It also includes a performance test program to measure the execution time of the kij and jki loop
        permutations with random input data.</p>

    <h2>Files</h2>
    <ul>
        <li><code>hw3_p1_header.hpp</code>: Header file containing the template function declarations for each loop
            permutation.</li>
        <li><code>hw3_p1.cpp</code>: Source file containing the template function definitions for each loop
            permutation.</li>
        <li><code>main.cpp</code>: Main program to test the performance of kij and jki loop permutations using random
            input data.</li>
    </ul>

    <h2>Compilation</h2>
    <p>To compile the project with different optimization levels, use the following commands:</p>
    <ol>
        <li>No optimization:
            <pre><code>g++ -std=c++11 -o main_no_opt main.cpp hw3_p1.cpp</code></pre>
        </li>
        <li>-O3 optimization:
            <pre><code>g++ -std=c++11 -O3 -o main_O3 main.cpp hw3_p1.cpp</code></pre>
        </li>
        <li>-ffast-math optimization:
            <pre><code>g++ -std=c++11 -O3 -ffast-math -o main_ffast_math main.cpp hw3_p1.cpp</code></pre>
        </li>
    </ol>

    <h2>Execution</h2>
    <p>After compilation, you can run the compiled programs and observe the results.</p>
    <ol>
        <li>No optimization:
            <pre><code>./main_no_opt</code></pre>
        </li>
        <li>-O3 optimization:
            <pre><code>./main_O3</code></pre>
        </li>
        <li>-ffast-math optimization:
            <pre><code>./main_ffast_math</code></pre>
        </li>
    </ol>
    <p>The output will display the average execution time (in seconds) for each matrix size (n) from 2 to 512.</p>
</body>

</html>
