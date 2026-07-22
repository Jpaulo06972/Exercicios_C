#include <stdio.h>  // Operacoes padrao de entrada/saida
#include <stdlib.h> // Funcoes padrao da biblioteca C

// Separa os numeros de um vetor em dois vetores distintos: um de pares e outro de impares,
// atualizando os respetivos tamanhos (*szPar e *szImpar) por referencia
void SeparaParImpar(int sz, int vec[sz], int vPar[], int vImpar[], int *szPar, int *szImpar){
    
    int contPar = 0, contImpar = 0;

    // Primeira passada: contabiliza a quantidade de elementos pares e impares
    for (int i = 0; i < sz; i++)
    {
        if ((vec[i] % 2) == 0)
        {
            contPar++;
        } else{
            contImpar++;
        }
    }
    
    // Armazena as contagens nas variaveis da funcao principal através de ponteiros
    *szPar = contPar;
    *szImpar = contImpar;

    int idxP = 0, idI = 0;
    
    // Segunda passada: distribui os valores do vetor original nos vetores de destino vPar e vImpar
    for (int i = 0; i < sz; i++)
    {        
        if ((vec[i] % 2) == 0)
        {
            vPar[idxP++] = vec[i]; // Insere no vetor de pares e avanca o indice de pares
        } else{
            vImpar[idI++] = vec[i]; // Insere no vetor de impares e avanca o indice de impares
        }             
    }
    
    // Exibe os elementos do vetor de numeros pares
    printf("Vetores Pares:\n");
    for (int i = 0; i < contPar; i++)
    {
        printf(" %d\t", vPar[i]);
    }

    // Exibe os elementos do vetor de numeros impares
    printf("\nVetores Impares:\n");
    for (int i = 0; i < contImpar; i++)
    {
        printf(" %d\t", vImpar[i]);
    }
    
    printf("\n");
}

int main(){

    int sz;

    // Solicita o tamanho do vetor inicial ao usuario
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &sz);

    // Aloca vetores locais com tamanho variavel
    int vet[sz];
    int vetPar[sz];
    int vetImpar[sz];
    int tamPar, tamIpar;

    // Coleta a entrada de cada elemento do vetor
    for (int i = 0; i < sz; i++)
    {
        printf("Digite o valor do vet[%d]: ", i);
        scanf("%d", &vet[i]);
    }

    // Processa o vetor separando os valores e atualizando as dimensoes tamPar e tamIpar
    SeparaParImpar(sz, vet, vetPar, vetImpar ,&tamPar, &tamIpar);

    return 0; // Termino normal
}