#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>


// Routine to perform element-wise addition of floats
void routine1(const float *A, const float *B, float *C, int n)
{
    int i;
     struct timeval start_time, end_time;
    gettimeofday(&start_time, NULL);
    
    for (i = 0; i < n; ++i)
    {
        C[i] = A[i] + B[i];
    }

    gettimeofday(&end_time, NULL);
    long elapsed_time = (end_time.tv_sec - start_time.tv_sec) * 1000000 + (end_time.tv_usec - start_time.tv_usec);

    printf("Array length: %d - Time taken: %lu microseconds\n", n, elapsed_time);
}

int main(int argc, char *argv[])
{

    int i, n, j;
    for (i = 3; i < 22; i++)
    {
        n = 2 << i;
        // Allocate memory for arrays A, B, and C
        float *A = (float *)malloc(n * sizeof(float));
        float *B = (float *)malloc(n * sizeof(float));
        float *C = (float *)malloc(n * sizeof(float));

        // Initialize arrays A and B with some values

        for (j = 0; j < n; ++j)
        {
            A[j] = (float)j;
            B[j] = (float)(2 * j);
        }

        routine1(A, B, C, n);

        // Clean up: Release allocated memory
        free(A);
        free(B);
        free(C);
    }
    return 0;
}