#include <stdio.h>

/*Elabore um algoritmo em C que preencha uma matriz de inteiros com 5 linhas e 5 colunas. Faça as trocas
necessárias para que as linhas se transformem em colunas (1ª linha → 1ª coluna, 2ª linha → 2ª coluna, … , 5ª
linha → 5ª coluna) utilizando obrigatoriamente ciclos.*/

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
