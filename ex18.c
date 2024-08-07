/*Construa uma função em C que devolva o valor que se repete com mais frequência num array de
números inteiros positivos passado como argumento. Se não existirem números repetidos deve devolver
-1.*/

#include <stdio.h>

int most_frequent(int arr[], int size) {
    int max_count = 0, most_frequent = -1;
    for (int i = 0; i < size; i++) {
        int count = 0;
        for (int j = 0; j < size; j++) {
            if (arr[i] == arr[j]) count++;
        }
        if (count > max_count) {
            max_count = count;
            most_frequent = arr[i];
        }
    }
    return max_count > 1 ? most_frequent : -1;
}

int main() {
    int size;
    printf("Informe o tamanho do array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Informe os elementos do array:\n");
    for (int i = 0; i < size; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    int result = most_frequent(arr, size);
    if (result != -1) {
        printf("O elemento mais frequente é: %d\n", result);
    } else {
        printf("Todos os elementos são únicos.\n");
    }
    return 0;
}