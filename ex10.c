#include <stdio.h>
#include <string.h>

/*Crie um algoritmo em C que receba uma string e faça a conversão das minúsculas para maiúsculas e das
maiúsculas para minúsculas.*/

int main()
{
    char str[100];
    printf("Digite uma string: ");
    fgets(str, 100, stdin);
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] = str[i] - 32;
        }
        else if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] = str[i] + 32;
    }
    printf("String convertida: %s", str);
    return 0;
}
