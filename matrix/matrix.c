#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

// Function to reverse the order of blocks inside the matrix
void routine1(int **M, int **O, int n, int b)
{
    int blockCount = n / b;

    // Measure wall-clock time for the main loop
    struct timeval start_time, end_time;
    gettimeofday(&start_time, NULL);

    for (int i = 0; i < blockCount; ++i)
    {
        for (int j = 0; j < blockCount; ++j)
        {
            // Reverse the order of blocks in-place
            for (int x = 0; x < b; ++x)
            {
                for (int y = 0; y < b; ++y)
                {
                    O[(blockCount - 1 - i) * b + x][(blockCount - 1 - j) * b + y] = M[i * b + x][j * b + y];
                }
            }
        }
    }

    gettimeofday(&end_time, NULL);
    long elapsed_time = (end_time.tv_sec - start_time.tv_sec) * 1000000 + (end_time.tv_usec - start_time.tv_usec);

    printf("Block size: %d - Time taken: %lu microseconds\n", b, elapsed_time);
}

int main()
{
    // Set random seed
    srand((unsigned int)time(NULL));

    // Matrix size
    int n = 4096;

    // Block dimension
    int b;

    int k;
    for (k = 1; k <= 7; k++)
    {
        b = 2 << k;
        // Initialize matrix M with random numbers
        int **M = (int **)malloc(n * sizeof(int *));
        for (int i = 0; i < n; ++i)
        {
            M[i] = (int *)malloc(n * sizeof(int));
            for (int j = 0; j < n; ++j)
            {
                M[i][j] = rand() % 100; // Random number between 0 and 99
            }
        }

        // Output matrix O with the same size as M
        int **O = (int **)malloc(n * sizeof(int *));
        for (int i = 0; i < n; ++i)
        {
            O[i] = (int *)malloc(n * sizeof(int));
        }

        // Call routine1 to reverse the order of blocks inside the matrix
        routine1(M, O, n, b);

        // // Output the result matrix O
        // printf("Matrix M:\n");
        // for (int i = 0; i < n; ++i)
        // {
        //     for (int j = 0; j < n; ++j)
        //     {
        //         printf("%d ", M[i][j]);
        //     }
        //     printf("\n");
        // }

        // printf("\nMatrix O (after reversing the order of blocks inside the matrix):\n");
        // for (int i = 0; i < n; ++i)
        // {
        //     for (int j = 0; j < n; ++j)
        //     {
        //         printf("%d ", O[i][j]);
        //     }
        //     printf("\n");
        // }

        // Free allocated memory
        for (int i = 0; i < n; ++i)
        {
            free(M[i]);
            free(O[i]);
        }
        free(M);
        free(O);
    }
    return 0;
}