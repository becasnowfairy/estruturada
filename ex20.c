#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*Crie uma função que devolva um número aleatório entre dois números inteiros passados como
argumentos.*/

int numeroAleatorio(int min, int max) {
    return min + rand() % (max - min + 1);
}

int main() {
    srand(time(NULL));
    int min, max;
    printf("Digite o número mínimo: ");
    scanf("%d", &min);
    printf("Digite o número máximo: ");
    scanf("%d", &max);
    printf("Número aleatório: %d\n", numeroAleatorio(min, max));
    return 0;
}