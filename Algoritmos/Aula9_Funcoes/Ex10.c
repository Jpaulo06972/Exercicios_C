#include <stdio.h>

void PrintVector(int sz, int vec[sz]){

    printf("Valores do vetor:\n");
    for (int i = 0; i < sz; i++) 
    {
        printf("%d\n", vec[i]);
    }
}

int main(){

    int sz;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &sz);

    int vet[sz];

    for (int i = 0; i < sz; i++)
    {
        printf("Digite o valor do vet[%d]: ", i);
        scanf("%d", &vet[i]);
    }

    PrintVector(sz, vet);

    return 0;
}