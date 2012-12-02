#!/bin/bash
#
#  Compile the program with ICC.
#
icc -openmp -parallel hello_openmp.c -lm
#
mv a.out hello
#
#  Run with 1, 2, and 4 threads.
#
echo "Run with 1 thread."
export OMP_NUM_THREADS=1
./hello > hello_local_icc_output.txt
#
echo "Run with 2 threads."
export OMP_NUM_THREADS=2
./hello >> hello_local_icc_output.txt
#
echo "Run with 4 threads."
export OMP_NUM_THREADS=4
./hello >> hello_local_icc_output.txt
#
#  Discard the executable file.
#
rm hello
#
echo "Program output written to hello_local_icc_output.txt"
