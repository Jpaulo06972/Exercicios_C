#include <stdio.h>
#include <stdlib.h>

void SeparaParImpar(int sz, int vec[sz], int vPar[], int vImpar[], int *szPar, int *szImpar){
    
    int contPar = 0, contImpar = 0;

    // Conta quantos números pares e impares tem
    for (int i = 0; i < sz; i++)
    {
        if ((vec[i] % 2) == 0)
        {
            contPar++;
        } else{
            contImpar++;
        }
    }
    
    *szPar = contPar;
    *szImpar = contImpar;

    int idxP = 0, idI = 0;
    
    // Passa os valores para os vetores
    for (int i = 0; i < sz; i++)
    {        
        if ((vec[i] % 2) == 0)
        {
            vPar[idxP++] = vec[i];
        } else{
            vImpar[idI++] = vec[i];
        }             
    }
    
    // Imprime os vetores
    printf("Vetores Pares:\n");
    for (int i = 0; i < contPar; i++)
    {
        printf(" %d\t", vPar[i]);
    }

    printf("\nVetores Impares:\n");
    for (int i = 0; i < contImpar; i++)
    {
        printf(" %d\t", vImpar[i]);
    }
    
    printf("\n");
}

int main(){

    int sz;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &sz);

    int vet[sz];
    int vetPar[sz];
    int vetImpar[sz];
    int tamPar, tamIpar;

    for (int i = 0; i < sz; i++)
    {
        printf("Digite o valor do vet[%d]: ", i);
        scanf("%d", &vet[i]);
    }

    SeparaParImpar(sz, vet, vetPar, vetImpar ,&tamPar, &tamIpar);

    return 0;
}