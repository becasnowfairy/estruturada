#include <stdio.h>

/*Crie uma função que receba como argumentos dois arrays de números inteiros e que copie os valores de
um para o outro.*/

void copy_array(int *src, int *dst, int size) {
    for (int i = 0; i < size; i++) {
        dst[i] = src[i];
    }
}

int main() {
    int size;

    printf("Digite o tamanho do array: ");
    scanf("%d", &size);

    int source[size];
    int destination[size];

    printf("Digite os %d números inteiros:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &source[i]);
    }

    copy_array(source, destination, size);

    printf("Array copiado: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", destination[i]);
    }
    printf("\n");

    return 0;
}