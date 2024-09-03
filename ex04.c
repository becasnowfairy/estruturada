#include <stdio.h>

/*Calcule o preço de venda de um artigo, sabendo o preço base e a percentagem do IVA*/

int main()
{
    float precoBase, percentagemIVA, precoVenda;

    printf("Digite o preço base do artigo: ");
    scanf("%f", &precoBase);

    printf("Digite a percentagem do IVA (exemplo: 23 para 23%%): ");
    scanf("%f", &percentagemIVA);

    precoVenda = precoBase * (1 + percentagemIVA / 100);

    printf("O preço de venda do artigo é: %.2f\n", precoVenda);

    return 0;
}
