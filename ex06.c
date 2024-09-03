#include <stdio.h>

/*Escreva um programa que solicite dois números e faça a troca dos números entre variáveis.*/

int main()
{
    int a, b, temporary;
    printf("Digite o primeiro número: ");
    scanf("%d", &a);
    printf("Digite o segundo número: ");
    scanf("%d", &b);
    printf("Antes da troca: 1º numero era %d e  2º numero era %d\n", a, b);
    temporary = a;
    a = b;
    b = temporary;
    printf("Depois da troca: 1ºnumero é %d e 2º numero é %d\n", a, b);
    return 0;
}
