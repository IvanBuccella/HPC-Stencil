// clang 4-1-tiling.c -o 4-1-tiling.out -fopenmp -O2

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <omp.h>
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

int N = 32768, x, y, n_threads;
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
    // printf("Initialization: %0.15f\n", omp_get_wtime() - t_init);
}

int main()
{
    n_threads = omp_get_max_threads();
    omp_set_max_active_levels(1);
    omp_set_num_threads(n_threads);
    omp_set_dynamic(0);

    initialization();

    const int tile_size = 16384;
    t_init = omp_get_wtime();
#pragma omp parallel for collapse(2)
    for (int xx = 0; xx < N; xx += tile_size)
    {
        for (int yy = 0; yy < N; yy += tile_size)
        {
            for (x = xx + 1; x < MIN(xx + tile_size, N - 1); x++)
            {
                for (y = yy + 1; y < MIN(yy + tile_size, N - 1); y++)
                {
                    B[x][y] = a * A[x][y] + b * (A[x - 1][y] + A[x + 1][y] + A[x][y - 1] + A[x][y + 1]);
                }
            }
        }
    }
    printf("Tiling with size of %d: %0.15f\n", tile_size, omp_get_wtime() - t_init);

    free(A);
    free(B);
}
