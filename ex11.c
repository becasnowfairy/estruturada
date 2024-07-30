/*Crie um algoritmo em C que receba uma string e faça a substituição dos espaços em branco por underscore
‘_’.*/
#include <stdio.h>
#include <string.h>
#define MAX 100

int main()
{
    char str[MAX];
    printf("Digite uma string: ");
    fgets(str, MAX, stdin);
    int i;
    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ' ')
        {
            str[i] = '_';
        }
    }
    printf("String com espaços substituidos por underscore: %s", str);
    return 0;
}
