#include <stdio.h>
#include <stdbool.h>

int main()
{
    int i, j;
    int vet[20] = {25, 4, 18, 13, 20, 7, 35, 6, 11, 12, 27, 2, 41, 45, 14, 33, 16, 8, 10, 21};
    int temp;

    // Esse primeiro For serve para contar quantas vezes ele já percorreu
    for (i = 0; i < 20 - 1; i ++){

        // Esse For interno compara os valores
        for (j = 0; j < 20 - i - 1; j ++){            
            if (vet[j] < vet[j+1]){
                temp = vet[j];
                vet[j] = vet[j+1];
                vet[j+1] = temp;
            }            
        }
    }

    printf("Vetor ordenado: ");
    for(i = 0; i < 20; i++){
        printf(" %d", vet[i]);
    }

    return 0;
}    

 