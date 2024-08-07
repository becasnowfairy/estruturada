/*Construa uma função em C que receba um array de números inteiros. A função deve movimentar para a
esquerda do array os números ímpares e para a direita os números pares.
*/
#include <stdio.h>

void separate_odd_even(int arr[], int size) {
    int i, j;
    int aux;

    // Separate odd and even numbers
    for (i = 0; i < size; i++) {
        if (arr[i] % 2 != 0) { // If the number is odd
            for (j = i + 1; j < size; j++) {
                if (arr[j] % 2 == 0) { // If the number is even
                    aux = arr[i];
                    arr[i] = arr[j];
                    arr[j] = aux;
                    break;
                }
            }
        }
    }
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter %d integers: ", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Original array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    separate_odd_even(arr, size);

    printf("Array after separation: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}