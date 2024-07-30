/*Crie um algoritmo em C que receba uma string e imprima a contagem das palavras existentes na string*/
#include <stdio.h>
#include <string.h>
#define MAX 100

int main()
{
    char str[MAX];
    int i, j, cont = 0;
    printf("Digite uma string: ");
    fgets(str, MAX, stdin);
    for (i = 0; i < strlen(str); i++)
    {
        if (str[i] == ' ')
        {
            cont++;
        }
    }
    printf("A contagem das palavras e: %d\n", cont + 1);
    return 0;
}
