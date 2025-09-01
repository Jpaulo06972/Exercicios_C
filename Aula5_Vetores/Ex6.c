#include <stdio.h>
#include <stdbool.h>

int main()
{
    int i = 0;
    int menor_Media = 0;
    double media = 0;
    double vet[20] = {25, 4, 18, 13, 20, 7, 35, 6, 11, 12, 27, 2, 41, 45, 14, 33, 16, 8, 10, 21};

    for (i = 0; i < 20; i ++)
    {
        media = media + vet[i];
    }

    media = media / 20.0;

    for (i = 0; i < 20; i ++)
    {
        if (media > vet[i]) menor_Media ++;
    }    

    printf("Quantidade de numeros menor que a media = %f\n", media);
    printf("Quantidade de numeros menor que a media = %d\n", menor_Media);
        
    return 0;
}    