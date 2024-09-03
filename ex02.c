#include <stdio.h>

/*Escreva um programa que solicite ao utilizador dois números inteiros e apresente o resultado
das seguintes operações aritméticas (adição, subtração, multiplicação e divisão)*/

int add(int x, int y)
{
    return x + y;
}

int sub(int x, int y)
{
    return x - y;
}

int div(int x, int y)
{
    return x / y;
}

int multi(int x, int y)
{
    return x * y;
}

int main()
{
    int num1, num2;
    printf("digite um numero inteiro \n");
    scanf("%i", &num1);
    printf("digite outro numero inteiro \n");
    scanf("%i", &num2);
    printf("%i + %i = %i \n", num1, num2, add(num1, num2));
    printf("%i - %i = %i \n", num1, num2, sub(num1, num2));
    printf("%i * %i = %i \n", num1, num2, multi(num1, num2));
    printf("%i / %i = %i \n", num1, num2, div(num1, num2));
}
