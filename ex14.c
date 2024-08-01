#include <stdio.h>

/*Crie uma função em C que faça a conversão de graus Celsius para Fahrenheit.*/

float celsiusToFahrenheit(float celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

int main() {
    float celsius;
    printf("Digite a temperatura em Celsius: ");
    scanf("%f", &celsius);
    float fahrenheit = celsiusToFahrenheit(celsius);
    printf("%.2f°C é igual a %.2f°F\n", celsius, fahrenheit);
    return 0;
}