/*Crie um algoritmo que redimensione a string para guardar um nome à dimensão do nome inserido.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *resize_string(const char *input)
{
    size_t len = strlen(input);
    char *resized_string = malloc((len + 1) * sizeof(char));

    if (resized_string == NULL)
    {
        return NULL;
    }

    strncpy(resized_string, input, len);
    resized_string[len] = '\0';
    return resized_string;
}

int main()
{
    char input[256];
    char **names = NULL;
    int capacity = 0;
    int count = 0;

    while (1)
    {
        printf("Escreva um nome (-1 para sair): ");
        fgets(input, 256, stdin);

        input[strcspn(input, "\n")] = 0;

        if (strcmp(input, "-1") == 0)
        {
            break;
        }

        if (count >= capacity)
        {
            capacity = capacity == 0 ? 1 : capacity * 2;
            names = realloc(names, capacity * sizeof(char *));
        }

        names[count] = resize_string(input);
        count++;
    }

    for (int i = 0; i < count; i++)
    {
        printf("Nome %d: %s\n", i + 1, names[i]);
        free(names[i]);
    }

    free(names);

    return 0;
}