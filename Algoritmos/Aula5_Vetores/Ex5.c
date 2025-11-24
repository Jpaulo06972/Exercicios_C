#include <stdio.h>
#include <stdbool.h>

int main()
{
    int i;
    int cont_Par = 0;
    int cont_M5 = 0;
    int vet[20] = {25, 4, 18, 13, 20, 7, 35, 6, 11, 12, 27, 2, 41, 45, 14, 33, 16, 8, 10, 21};

    for (i = 0; i < 20; i ++)
    {
        if ((vet[i] % 2) == 0) cont_Par ++;
        if ((vet[i] % 5) == 0) cont_M5 ++;
    }

    printf("Quantidade de numeros pares = %d\n", cont_Par);
    printf("Quantidade de multiplos de 5 = %d\n", cont_M5);

    
    return 0;
}    