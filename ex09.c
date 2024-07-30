#include <stdio.h>

#define SIZE 5

int main()
{
    int matrix[SIZE][SIZE];
    int transposed[SIZE][SIZE];

    printf("Matriz original:\n");
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            matrix[i][j] = i * SIZE + j + 1;
            printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            transposed[j][i] = matrix[i][j];
        }
    }
    printf("\nMatriz transposta:\n");
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            printf("%3d ", transposed[i][j]);
        }
        printf("\n");
    }

    return 0;
}
