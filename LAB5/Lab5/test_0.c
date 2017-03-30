#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 128

int main(void)
{
    static int A[SIZE][SIZE], B[SIZE][SIZE], C[SIZE][SIZE] = {0};
    int i, j, k;

    srand(time(NULL));

    for(i = 0; i < SIZE; i++)
    {
        for(j = 0; j < SIZE; j++)
        {
            A[i][j] = rand()%10;
            B[i][j] = rand()%10;
        }
    }

    clock_t begin, end;
    double time_spent;

    begin = clock();

    for(i = 0; i < SIZE; i++)
        for(j = 0; j < SIZE; j++)
            for(k = 0; k < SIZE; k++)
                C[i][j] += A[i][k] * B[k][j];

    end = clock();

    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    printf("Elapsed time: %.9lf seconds.\n", time_spent);

    return 0;
}