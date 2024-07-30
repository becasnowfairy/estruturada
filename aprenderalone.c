#include <stdio.h>
#include <ctype.h>

/* pergunta um valor em metros e imprime o correspondente em decímetros, centímetros e milímetros.*/

int metros()
{
    float metros;
    printf("Digite um valor em metros: ");
    scanf("%f", &metros);
    printf("%2f metros é igual a %.2f decímetros, %.2f centímetros e %.2f milímetros.\n", metros, metros * 10, metros * 100, metros * 1000);
    return 0;
}

/*imprime uma tabela com a tabuada de 1 a 9*/

void tabuada()
{
    printf("  |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  | \n");
    printf("--+-  --+-  --+-----+-----+-----+-----+-----+-----+-----+\n");
    for (int i = 1; i <= 9; i++)
    {
        printf("%d | ", i);
        for (int j = 1; j <= 9; j++)
        {
            printf(" %2d  |", i * j);
        }
        printf("\n");
    }
}

/*solicita um número decimal e imprime o correspondente em hexa e octal*/

int decimal()
{
    int decimal;
    printf("Digite um número decimal: ");
    scanf("%d", &decimal);
    printf("%d em hexadecimal é %x e em octal é %o.\n", decimal, decimal, decimal);
    return 0;
}

/* lê dois valores e imprime:
- se o primeiro valor for menor que o segundo, a lista de valores do primeiro até o segundo;
- se o primeiro valor for menor que o segundo a lista de valores do segundo até o primeiro em ordem crescente;
- se ambos forem iguais a mensagem "valores iguais". */

void lista()
{
    int a, b;
    printf("Digite o primeiro valor: ");
    scanf("%d", &a);
    printf("Digite o segundo valor: ");
    scanf("%d", &b);
    if (a < b)
    {
        printf("Lista de valores do primeiro até o segundo: ");
        for (int i = a; i <= b; i++)
        {
            printf("%d ", i);
        }
        printf("\n");
    }
    else if (a > b)
    {
        printf("Lista de valores do segundo até o primeiro em ordem crescente: ");
        for (int i = b; i <= a; i++)
        {
            printf("%d ", i);
        }
        printf("\n");
    }
    else
    {
        printf("Valores iguais.\n");
    }
}

/*lê um string qualquer de no máximo 80 caracteres e imprime:
- Quantos caracteres tem o string;
- Quantos caracteres são de pontuação;
- Quantos caracteres são números;
- Quantos caracteres são minúsculas.*/

void string()
{
    char string[80];
    int cont = 0, contPont = 0, contNum = 0, contMin = 0, contMai = 0;
    printf("Digite uma string: ");
    fgets(string, 80, stdin);
    for (int i = 0; string[i] != '\0'; i++)
    {
        if (isalpha(string[i]))
        {
            cont++;
            if (islower(string[i]))
            {
                contMin++;
            }
            else
            {
                contMai++;
            }
        }
        else if (isdigit(string[i]))
        {
            contNum++;
        }
        else if (ispunct(string[i]))
        {
            contPont++;
        }
    }
    printf("Quantidade de caracteres: %d\n", cont);
    printf("Quantidade de caracteres de pontuação: %d\n", contPont);
    printf("Quantidade de caracteres de números: %d\n", contNum);
    printf("Quantidade de caracteres minúsculas: %d\n", contMin);
    printf("Quantidade de caracteres maiúsculas: %d\n", contMai);
}

int main()
{
    // metros();
    // tabuada();
    // decimal();
    // lista();
    string();
}
