/*Elabore uma função em C que devolva a dimensão da menor palavra encontrada numa string passada
como argumento.*/
#include <stdio.h>
#include <string.h>
#include <limits.h>

int menor_palavra(char *str) {
    int menor = INT_MAX;
    char *token = strtok(str, " ");
    while (token != NULL) {
        int tamanho = strlen(token);
        if (tamanho < menor) {
            menor = tamanho;
        }
        token = strtok(NULL, " ");
    }
    return menor;
}

int main() {
    char str[100];
    printf("Digite uma string: ");
    fgets(str, 100, stdin); 
    str[strlen(str) - 1] = '\0'; 
    printf("Tamanho da menor palavra: %d\n", menor_palavra(str));
    return 0;
}