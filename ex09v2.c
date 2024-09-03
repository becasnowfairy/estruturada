#include <stdio.h>

#define size 5

/*Elabore um algoritmo em C que preencha uma matriz de inteiros com 5 linhas e 5 colunas. Faça as trocas
necessárias para que as linhas se transformem em colunas (1ª linha → 1ª coluna, 2ª linha → 2ª coluna, … , 5ª
linha → 5ª coluna) utilizando obrigatoriamente ciclos.*/

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
