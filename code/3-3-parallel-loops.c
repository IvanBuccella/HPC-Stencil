// clang 3-3-parallel-loops.c -o 3-3-parallel-loops.out -fopenmp -O2

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <omp.h>

int N = 45056, x, y, n_threads;
float a = 2, b = 3, **A, **B;
double t_init;

void initialization()
{
    t_init = omp_get_wtime();
    A = (float **)malloc(N * sizeof(float *));
    B = (float **)malloc(N * sizeof(float *));
    for (x = 0; x < N; x++)
    {
        A[x] = (float *)malloc(N * sizeof(float));
        B[x] = (float *)malloc(N * sizeof(float));
        for (y = 0; y < N; y++)
        {
            A[x][y] = 1.0f;
            B[x][y] = 0.0f;
        }
    }
    printf("Initialization: %0.15f\n", omp_get_wtime() - t_init);
}

int main()
{
    n_threads = omp_get_max_threads();
    omp_set_max_active_levels(1);
    omp_set_num_threads(n_threads);
    omp_set_dynamic(0);

    initialization();

    t_init = omp_get_wtime();

#pragma omp parallel for collapse(2)
    for (x = 1; x < N - 1; x++)
    {
        for (y = 1; y < N - 1; y++)
        {
            B[x][y] = a * A[x][y] + b * (A[x - 1][y] + A[x + 1][y] + A[x][y - 1] + A[x][y + 1]);
        }
    }

    printf("Parallel loops on X and Y: %0.15f\n", omp_get_wtime() - t_init);

    free(A);
    free(B);
}
