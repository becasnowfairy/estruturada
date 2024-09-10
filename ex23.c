/*Faça um algoritmo que crie um array para inserção de temperaturas. A matriz deve ser redimensionada
sempre que se insira uma nova temperatura e ter no final uma posição para guardar a média das
temperaturas. A média deve ser atualizada sempre que se insira uma nova temperatura*/
#include <stdio.h>
#include <stdlib.h>

#define INITIAL_CAPACITY 10
#define GROWTH_FACTOR 2

int main()
{
    int capacity = INITIAL_CAPACITY;
    float *temperatures = malloc(capacity * sizeof(float));
    if (temperatures == NULL)
    {
        printf("Erro de alocação de memória\n");
        return 1;
    }

    int count = 0;
    float sum = 0.0;

    while (1)
    {
        printf("Insira a temperatura %d: ", count + 1);
        if (scanf("%f", &temperatures[count]) != 1)
        {
            printf("Erro de leitura da temperatura\n");
            free(temperatures);
            return 1;
        }

        sum += temperatures[count];
        count++;

        if (count == capacity)
        {
            capacity *= GROWTH_FACTOR;
            float *new_temperatures = realloc(temperatures, capacity * sizeof(float));
            if (new_temperatures == NULL)
            {
                printf("Erro de alocação de memória\n");
                free(temperatures);
                return 1;
            }
            temperatures = new_temperatures;
        }

        printf("Média das temperaturas: %.2f\n", sum / count);
    }

    free(temperatures);
    return 0;
}