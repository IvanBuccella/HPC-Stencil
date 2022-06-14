#!/bin/bash
clang 0-initialization.c -o 0-initialization.out -fopenmp
clang 1-1-loop-interchange.c -o 1-1-loop-interchange.out -fopenmp
clang 1-2-loop-interchange.c -o 1-2-loop-interchange.out -fopenmp
clang 2-1-optimization-flags.c -o 2-1-optimization-flags.out -fopenmp -O0
clang 2-2-optimization-flags.c -o 2-2-optimization-flags.out -fopenmp -O1
clang 2-3-optimization-flags.c -o 2-3-optimization-flags.out -fopenmp -O2
clang 2-4-optimization-flags.c -o 2-4-optimization-flags.out -fopenmp -O3
clang 3-1-parallel-loops.c -o 3-1-parallel-loops.out -fopenmp -O3
clang 3-2-parallel-loops.c -o 3-2-parallel-loops.out -fopenmp -O3
clang 3-3-parallel-loops.c -o 3-3-parallel-loops.out -fopenmp -O3
clang 4-1-tiling.c -o 4-1-tiling.out -fopenmp -O3
clang 4-2-tiling.c -o 4-2-tiling.out -fopenmp -O3
clang 4-3-tiling.c -o 4-3-tiling.out -fopenmp -O3
clang 4-4-tiling.c -o 4-4-tiling.out -fopenmp -O3
clang 5-1-dimension-augmentation.c -o 5-1-dimension-augmentation.out -fopenmp -O3
clang 5-2-dimension-augmentation.c -o 5-2-dimension-augmentation.out -fopenmp -O3
clang 5-3-dimension-augmentation.c -o 5-3-dimension-augmentation.out -fopenmp -O3
clang 5-4-dimension-augmentation.c -o 5-4-dimension-augmentation.out -fopenmp -O3


./0-initialization.out
./1-1-loop-interchange.out
./1-2-loop-interchange.out
./2-1-optimization-flags.out
./2-2-optimization-flags.out
./2-3-optimization-flags.out
./2-4-optimization-flags.out
./3-1-parallel-loops.out
./3-2-parallel-loops.out
./3-3-parallel-loops.out
./4-1-tiling.out
./4-2-tiling.out
./4-3-tiling.out
./4-4-tiling.out
./5-1-dimension-augmentation.out
./5-2-dimension-augmentation.out
./5-3-dimension-augmentation.out
./5-4-dimension-augmentation.out