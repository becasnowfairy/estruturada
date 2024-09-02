#include <stdio.h>
#include <ctype.h>
#include <time.h>
#include <stdlib.h>

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

/*fazer uma função que cacula a enésima potência de uma variável real x:
f(x, n) = x */

double potencia(double base, int exponent)
{
    double result = 1;
    for (int i = 0; i < exponent; i++)
    {
        result *= base;
    }
    return result;
}

int função()
{
    double base;
    int exponent;
    printf("Indique o seu primeiro numero (base): ");
    scanf("%lf", &base);
    printf("Indique o seu expoente: ");
    scanf("%d", &exponent);
    double result = potencia(base, exponent);
    printf("Resultado: %.2f\n", result);

    return 0;
}

/*Exercício: fazer um programa em "C" que solicita o total gasto pelo cliente de uma loja, imprime as opções de pagamento,
solicita a opção desejada e imprime o valor total das prestações (se houverem).
1) Opção: a vista com 10% de desconto
2) Opção: em duas vezes (preço da etiqueta)
3) Opção: de 3 até 10 vezes com 3% de juros ao mês (somente para compras
acima de R$ 100,00).
OBS: fazer uma função que imprime as opções solicita a opção desejada e retorna
a opção escolhida. No programa principal, testar a opção escolhida e ativar a
função correspondente (uma função para cada opção).*/

// Function to print options
void imprimeOpcoes()
{
    printf("Opções:\n");
    printf("1. Opção 1: pagamento á vista com 10 porcento de desconto\n");
    printf("2. Opção 2; pagamento em duas vezes\n");
    printf("3. Opção 3: pagamento de três até 10 vezes com 3 porcento de juros\n");
}

// Function to get user's option
int opcaoEscolhida()
{
    int opcao;
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);
    return opcao;
}

// Function for option 1
void opcao1(double total)
{
    if (total > 100.0)
    {
        double desconto = total * 0.1;
        double valorTotal = total - desconto;
        printf("Valor da compra: $ %.2f\n", valorTotal);
    }
    else
    {
        printf("Valor da compra deve ser maior que $ 100,00!\n");
    }
}

// Function for option 2
void opcao2(double total)
{
    double valorTotal = total;
    printf("Valor total das prestações: $ %.2f\n", valorTotal);
}

// Function for option 3
void opcao3(double total)
{
    int vezes;
    printf("Número de vezes: ");
    scanf("%d", &vezes);
    if (vezes >= 3 && vezes <= 10)
    {
        double juros = total * 0.03;
        double valorTotal = total + (juros * vezes);
        printf("Valor total com juros: $ %.2f\n", valorTotal);
    }
    else
    {
        printf("Número de vezes inválido!\n");
    }
}

int mainop()
{
    double total;
    printf("Valor da etiqueta: $ ");
    scanf("%lf", &total);

    imprimeOpcoes();
    int opcao = opcaoEscolhida();

    switch (opcao)
    {
    case 1:
        opcao1(total);
        break;
    case 2:
        opcao2(total);
        break;
    case 3:
        opcao3(total);
        break;
    default:
        printf("Opção inválida!\n");
    }

    return 0;
}

/*euromilhões*/

int euro()
{
    srand(time(NULL));
    int chave[5], estrelas[2];
    for (int i = 0; i < 5; i++)
    {
        chave[i] = rand() % 50 + 1;
        for (int i2 = 0; i2 < i; i2++)
            if (chave[i] == chave[i2])
            {
                i--;
                break;
            }
    }
    estrelas[0] = rand() % 12 + 1;
    do
        estrelas[1] = rand() % 12 + 1;
    while (estrelas[0] == estrelas[1]);
    printf("Chave:");
    for (int i = 0; i < 5; i++)
        printf(" %d", chave[i]);
    printf("\nEstrelas: %d %d\n", estrelas[0], estrelas[1]);
    return 0;
}

// Crie um programa capaz de criar a transposta de uma matriz. A matriz deve ser lida de teclado.
void printMatrix(int matrix[][10], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void transposeMatrix(int matrix[][10], int transposed[][10], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            transposed[j][i] = matrix[i][j];
        }
    }
}

void matrix()
{
    int matrix[10][10], transposed[10][10];
    int rows, cols;

    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d %d", &rows, &cols);

    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("Matrix:\n");
    printMatrix(matrix, rows, cols);

    transposeMatrix(matrix, transposed, rows, cols);

    printf("Transposed Matrix:\n");
    printMatrix(transposed, cols, rows);
}

int main()
{
    // metros();
    // tabuada();
    // decimal();
    // lista();
    // string();
    // função();
    // imprimeOpcoes();
    // mainop();
    // euro();
    matrix();
}
