#include <stdio.h>

int estrelas()
{
    int i, cont;
    for (i = 1; i <= 5; i++){
        for (cont = 1; cont <= i; cont++)
        {
            printf("*");
        }
    printf("\n");
}
return 0;
}

int estrelinhas()
{
    int n = 5;
    for (int cont1 = 0; cont1 < n; cont1++)
    {
        for (int cont2 = 0; cont2 < n; cont2++)
        {
            if (cont1 == 0 || cont2 == 0 || cont2 == n - cont1 - 1)
            {
                printf("*");
            }
            else
            {
                printf(" ");
                
            }
        }
        printf("\n");
    }
    return 0;
}

int estrelitas()
{
    int cont1, cont2, n = 4;

    for (cont1 = 1; cont1 <= n; cont1++)
    {

        for (cont2 = 1; cont2 <= n - cont1; cont2++)
        {
            printf(" ");
        }

        for (cont2 = 1; cont2 <= 2 * cont1 - 1; cont2++)
        {
            printf("*");
        }

        printf("\n");
    }

    return 0;
}

int main(){
    estrelas();
    estrelinhas();
    estrelitas();
    }