#include <stdio.h>

/*Escreva um programa que solicite um determinado número de segundos, e em seguida
indique quantas horas, minutos e segundos esse valor representa.*/

int main()
{
    int segundos_total;
    int horas, minutos, segundos;
    
    printf("Digite o número de segundos: ");
    scanf("%d", &segundos_total);

    horas = segundos_total / 3600;
    segundos_total %= 3600;

    minutos = segundos_total / 60;
    segundos = segundos_total % 60;

    printf("%d:%d:%d\n", horas, minutos, segundos);

    return 0;
}
