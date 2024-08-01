#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*Construa uma função em C que faça a inversão de uma String passada como argumento.*/

void print_inverse(const char *str) {
    int length = strlen(str);
    char *inverse = (char *)malloc((length + 1) * sizeof(char));

    // Check if memory allocation was successful
    if (inverse == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }

    // Copy characters from the original string to the inverse string in reverse order
    for (int i = 0; i < length; i++) {
        inverse[i] = str[length - i - 1];
    }
    inverse[length] = '\0'; // Null-terminate the inverse string

    printf("%s\n", inverse);

    free(inverse);
}

int main() {
    char input[100];

    printf("Enter a string: ");
    fgets(input, 100, stdin);

    // Remove the newline character from the input string
    input[strcspn(input, "\n")] = 0;

    print_inverse(input);

    return 0;
}