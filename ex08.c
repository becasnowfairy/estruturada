#include <stdio.h>

int main()
{
    int array[10];
    int array2[10];
    int i, j = 0, k = 9;

    printf("Escreva 10 números inteiros:\n");
    for (i = 0; i < 10; i++)
    {
        scanf("%d", &array[i]);
    }

    for (i = 0; i < 10; i++)
    {
        if (array[i] % 2 != 0)
        {
            array2[j] = array[i];
            j++;
        }
        else
        {
            array2[k] = array[i];
            k--;
        }
    }

    printf("O seu novo array:\n");
    for (i = 0; i < 10; i++)
    {
        printf("%d ", array2[i]);
    }
    printf("\n");

    return 0;
}
