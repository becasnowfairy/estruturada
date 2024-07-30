#include <stdio.h>

#define size 5

int main()
{
    int matrix[size][size];
    int i, j;

    printf("Matriz original:\n");
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            matrix[i][j] = i * size + j + 1;
            printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }

    printf("\nMatriz transposta:\n");
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            printf("%3d ", matrix[j][i]);
        }
        printf("\n");
    }

    return 0;
}
